/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 12:34:24 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/23 15:36:01 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		ray_cast(t_env *env)
{
	int		x;
	int		map[24][24] = {
	  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
	  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,4,0,4,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};
	x = 0;
	while(x < X_SIZE)
	{
		env->cam_X = 2 * x / (double)X_SIZE - 1;
		env->rayPosX = env->posX;
		env->rayPosY = env->posY;
		env->rayDirX = env->dirX + env->planeX * env->cam_X;
		env->rayDirY = env->dirY + env->planeY * env->cam_X;
		env->mapX = (int)env->rayPosX;
		env->mapY = (int)env->rayPosY;
		env->deltaDistX = sqrt(1 + pow(env->rayDirY, 2) / pow(env->rayDirX, 2));
		env->deltaDistY = sqrt(1 + pow(env->rayDirX, 2) / pow(env->rayDirY, 2));
		if (env->rayDirX < 0)
		{
			env->stepX = -1;
			env->sideDistX = (env->rayPosX - (int)env->rayPosX) * env->deltaDistX;
		}
		else
		{
			env->stepX = 1;
			env->sideDistX = (env->mapX + 1.0 - env->rayPosX) * env->deltaDistX;
		}
		if (env->rayDirY < 0)
		{
			env->stepY = -1;
			env->sideDistY = (env->rayPosY - env->mapY) * env->deltaDistY;
		}
		else
		{
			env->stepY = 1;
			env->sideDistY = (env->mapY + 1.0 - env->rayPosY) * env->deltaDistY;
		}
		while (env->hit == 0)
		{
			if (env->sideDistX < env->sideDistY)
			{
				env->sideDistX += env->deltaDistX;
				env->mapX += env->stepX;
				env->side = 0;
			}
			else
			{
				env->sideDistY += env->deltaDistY;
				env->mapY += env->stepY;
				env->side = 1;
			}
			if (map[env->mapX][env->mapY] > 0)
			{
				env->hit = 1;
			}
		}
		if (env->side == 0)
			env->perpWallDist = (env->mapX - env->rayPosX + (1 - env->stepX) / 2) / env->rayDirX;
		else
			env->perpWallDist = (env->mapY - env->rayPosY + (1 - env->stepY) / 2) / env->rayDirY;
		env->lineHeight = (int)(Y_SIZE / env->perpWallDist);
		env->drawStart = -env->lineHeight / 2 + Y_SIZE / 2;
		if (env->drawStart < 0)
			env->drawStart = 0;
		env->drawEnd = env->lineHeight / 2 + Y_SIZE / 2;
		if (env->drawEnd >= Y_SIZE)
			env->drawEnd = Y_SIZE - 1;
		if (map[env->mapX][env->mapY] == 1)
			env->color = 0xFF0000;
		if (map[env->mapX][env->mapY] == 2)
			env->color = 0x00FF00;
		if (map[env->mapX][env->mapY] == 3)
			env->color = 0x0000FF;
		if (map[env->mapX][env->mapY] == 4)
			env->color = 0xFF00FF;
		else
			env->color = 0xFFFF00;
		if (env->side == 1)
			env->color /= 2;
		draw_vertical(x, env);
		x++;
	}
}
