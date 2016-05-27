/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 12:36:07 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/27 14:35:34 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	init_param(t_env *env, int x)
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

void	check_wall(t_env *env)
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
		if (check_map(env->mapx, env->mapy) > 0)
			env->hit = 1;
	}
}

void	select_color(t_env *env)
{
	env->lineheight = (int)(Y_SIZE / env->perpwalldist);
	env->drawstart = -env->lineheight / 2 + Y_SIZE / 2;
	env->drawend = env->lineheight / 2 + Y_SIZE / 2;
	if (env->drawstart < 0)
		env->drawstart = 0;
	if (env->drawend >= Y_SIZE)
		env->drawend = Y_SIZE;
	if (env->side == 1)
		env->wallx = env->rposx + ((env->mapy - env->rposy + (1 - env->stepy)
					/ 2) / env->raydiry) * env->raydirx;
	else
		env->wallx = env->rposy + ((env->mapx - env->rposx + (1 - env->stepx)
					/ 2) / env->raydirx) * env->raydiry;
	env->wallx -= floor((env->wallx));
	env->texx = (int)(env->wallx * 64);
	if (!env->side && env->raydirx > 0)
		env->texx = 64 - env->texx - 1;
	if (env->side && env->raydiry < 0)
		env->texx = 64 - env->texx - 1;
}
