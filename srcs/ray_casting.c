/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 12:34:24 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/26 20:26:32 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	init_param(t_env *env, int x)
{
	env->cam_x = 2 * x / (double)X_SIZE - 1;
	env->rposx = env->posx;
	env->rposy = env->posy;
	env->raydirx = env->dirx + env->planex * env->cam_x;
	env->raydiry = env->diry + env->planey * env->cam_x;
	env->mapx = (int)env->rposx;
	env->mapy = (int)env->rposy;
	env->deltx = sqrt(1 + pow(env->raydiry, 2) / pow(env->raydirx, 2));
	env->delty = sqrt(1 + pow(env->raydirx, 2) / pow(env->raydiry, 2));
	env->hit = 0;
	env->stepx = (env->raydirx < 0) ? -1 : 1;
	if (env->stepx == -1)
		env->sidedistx = (env->rposx - env->mapx) * env->deltx;
	else
		env->sidedistx = (env->mapx + 1.0 - env->rposx) * env->deltx;
	env->stepy = (env->raydiry < 0) ? -1 : 1;
	if (env->stepy == -1)
		env->sidedisty = (env->rposy - env->mapy) * env->delty;
	else
		env->sidedisty = (env->mapy + 1.0 - env->rposy) * env->delty;
}

static void	check_wall(t_env *env)
{
	while (env->hit == 0)
	{
		if (env->sidedistx < env->sidedisty)
		{
			env->sidedistx += env->deltx;
			env->mapx += env->stepx;
			env->side = 0;
		}
		else
		{
			env->sidedisty += env->delty;
			env->mapy += env->stepy;
			env->side = 1;
		}
		if (searchinlist(env->mapx, env->mapy, env) > 0)
			env->hit = 1;
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
		env->drawend = Y_SIZE;
	if (env->side == 1)
		env->wallx = env->rposx + ((env->mapy - env->rposy + (1 - env->stepy) / 2) /
				env->raydiry) * env->raydirx;
	else
		env->wallx = env->rposy + ((env->mapx - env->rposx + (1 - env->stepx) / 2) /
				env->raydirx) * env->raydiry;
	env->wallx -= floor((env->wallx));
	env->texx = (int)(env->wallx * 64);
	if (!env->side && env->raydirx > 0)
		env->texx = 64 - env->texx - 1;
	if (env->side && env->raydiry < 0)
		env->texx = 64 - env->texx - 1;
}

static void	check_color(int x, int y, int color, t_env *env)
{
	while (y < env->drawend)
	{
		env->texy = (y * 2 - Y_SIZE + env->lineheight) * 32 / env->lineheight;
		if (searchinlist(env->mapx, env->mapy, env) == 1)
			color = env->tex->tab1[64 * env->texy + env->texx];
		else if (searchinlist(env->mapx, env->mapy, env) == 2)
			color = env->tex->tab2[64 * env->texy + env->texx];
		else if (searchinlist(env->mapx, env->mapy, env) == 3)
			color = env->tex->tab3[64 * env->texy + env->texx];
		else if (searchinlist(env->mapx, env->mapy, env) == 4)
			color = env->tex->tab4[64 * env->texy + env->texx];
		env->buftext[y][x] = color;
		y++;
	}
	if (!env->side && env->raydirx > 0)
	{
		env->floorxwall = env->mapx;
		env->floorywall = env->mapy + env->wallx;
	}
	else if (!env->side && env->raydirx < 0)
	{
		env->floorxwall = env->mapx + 1.0;
		env->floorywall = env->mapy + env->wallx;
	}
	else if (env->side == 1 && env->raydiry > 0)
	{
		env->floorxwall = env->mapx + env->wallx;
		env->floorywall = env->mapy;
	}
	else
	{
		env->floorxwall = env->mapx + env->wallx;
		env->floorywall = env->mapy + 1.0;
	}
	env->distwall = env->perpwalldist;
	env->distplayer = 0.0;
	if (env->drawend < 0)
		env->drawend = Y_SIZE;
	y = env->drawend;
	while (y < Y_SIZE)
	{
		env->currentdist = Y_SIZE / (2.0 * y - Y_SIZE);
		env->weight = (env->currentdist - env->distplayer) /
			(env->distwall - env->distplayer);
		env->currentfloorx = env->weight * env->floorxwall +
			(1.0 - env->weight) * env->posx;
		env->currentfloory = env->weight * env->floorywall +
			(1.0 - env->weight) * env->posy;
		env->floortexx = (int)(env->currentfloorx * 64) % 64;
		env->floortexy = (int)(env->currentfloory * 64) % 64;
		env->buftext[y][x] = env->tex->sol[64 * env->floortexy + env->floortexx];
		env->buftext[Y_SIZE - y][x] = env->tex->roof[64 *
			env->floortexy + env->floortexx];
		y++;
	}
}


void		ray_cast(t_env *env)
{
	int		x;
	double color;

	x = 0;
	color = 0;
	while (x < X_SIZE)
	{
		init_param(env, x);
		check_wall(env);
		if (env->side == 0)
			env->perpwalldist = (env->mapx - env->rposx + (1 - env->stepx) / 2)
				/ env->raydirx;
		else
			env->perpwalldist = (env->mapy - env->rposy + (1 - env->stepy) / 2)
				/ env->raydiry;
		select_color(env);
		check_color(x, env->drawstart, color, env);
		x++;
	}
}
