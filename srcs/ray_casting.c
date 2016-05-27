/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 12:34:24 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/27 13:24:21 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

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
}

static void	init_floor(t_env *env)
{
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
}

static void	text_floor(int x, t_env *env)
{
	int	y;

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
		env->buftext[y][x] = env->tex->sol[64 * env->floortexy +
			env->floortexx];
		env->buftext[Y_SIZE - y][x] = env->tex->roof[64 *
			env->floortexy + env->floortexx];
		y++;
	}
}

void		ray_cast(t_env *env)
{
	int		x;
	double	color;

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
		init_floor(env);
		text_floor(x, env);
		x++;
	}
}
