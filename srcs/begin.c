/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 12:34:24 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/24 16:37:30 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
static void	init_param(t_env *env, int x)
{
		env->cam_x = 2 * x / (double)X_SIZE - 1;
		env->rayposx = env->posx;
		env->rayposy = env->posy;
		env->raydirx = env->dirx + env->planex * env->cam_x;
		env->raydiry = env->diry + env->planey * env->cam_x;
		env->mapx = (int)env->rayposx;
		env->mapy = (int)env->rayposy;
		env->deltadistx = sqrt(1 + pow(env->raydiry, 2) / pow(env->raydirx, 2));
		env->deltadisty = sqrt(1 + pow(env->raydirx, 2) / pow(env->raydiry, 2));
		env->hit = 0;
		if (env->raydirx < 0)
		{
			env->stepx = -1;
			env->sidedistx = (env->rayposx - (int)env->rayposx) * env->deltadistx;
		}
		else
		{
			env->stepx = 1;
			env->sidedistx = (env->mapx + 1.0 - env->rayposx) * env->deltadistx;
		}
		if (env->raydiry < 0)
		{
			env->stepy = -1;
			env->sidedisty = (env->rayposy - env->mapy) * env->deltadisty;
		}
		else
		{
			env->stepy = 1;
			env->sidedisty = (env->mapy + 1.0 - env->rayposy) * env->deltadisty;
		}
}

static void	select_color(t_env *env)
{
		env->lineheight = (int)(Y_SIZE / env->perpwalldist);
		env->drawstart = -env->lineheight / 2 + Y_SIZE / 2;
		env->drawend = env->lineheight / 2 + Y_SIZE / 2;
		if (env->drawstart < 0)
			env->drawstart = 0;
		if (env->drawend >= Y_SIZE)
			env->drawend = Y_SIZE - 1;
		if (searchinlist(env->mapx, env->mapy, env) == 1)
			env->color = 0xFF0000;
		if (searchinlist(env->mapx, env->mapy, env) == 2)
			env->color = 0x00FF00;
		if (searchinlist(env->mapx, env->mapy, env) == 3)
			env->color = 0x0000FF;
		if (searchinlist(env->mapx, env->mapy, env) == 4)
			env->color = 0xFF00FF;
		else
			env->color = 0xFFFF00;
		if (env->side == 1)
			env->color /= 2;
}

void	ray_cast(t_env *env)
{
	int		x;

	x = 0;
	while (x < X_SIZE)
	{
		init_param(env, x);
		while (env->hit == 0)
		{
			if (env->sidedistx < env->sidedisty)
			{
				env->sidedistx += env->deltadistx;
				env->mapx += env->stepx;
				env->side = 0;
			}
			else
			{
				env->sidedisty += env->deltadisty;
				env->mapy += env->stepy;
				env->side = 1;
			}
			if (searchinlist(env->mapx, env->mapy, env) > 0)
				env->hit = 1;
		}
		if (env->side == 0)
			env->perpwalldist = (env->mapx - env->rayposx + (1 - env->stepx) / 2) / env->raydirx;
		else
			env->perpwalldist = (env->mapy - env->rayposy + (1 - env->stepy) / 2) / env->raydiry;
		select_color(env);
		draw_vertical(x, env);
		x++;
	}
}

void	expose(t_env *env)
{
	mlx_clear_window(env->mlx, env->win);
	ray_cast(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img->img, 0, 0);
	mlx_hook(env->win, 2, 3, key_funct, env);
	mlx_loop(env->mlx);
}
