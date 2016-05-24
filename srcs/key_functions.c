/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 14:20:21 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/24 16:35:28 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	moove_forward(t_env *env)
{
	if (searchinlist((int)(env->posx + env->dirx), (int)env->posy, env) == 0)
	{
		env->posx += env->dirx;
		env->posy += env->diry;
	}
	printf("%f\n", env->posx);
}

void	moove_backwards(t_env *env)
{
	if (searchinlist((int)(env->posx - env->dirx), (int)env->posy, env) == 0)
	{
		env->posx -= env->dirx;
		env->posy -= env->diry;
	}
}

void	rotate_right(t_env *env)
{
	double	oldDirx;
	double	oldPlanex;

	oldDirx = env->dirx;
	oldPlanex = env->planex;
	env->dirx = env->dirx * cos(-env->rotspeed) - env->diry * sin(-env->rotspeed);
	env->diry = oldDirx * sin(-env->rotspeed) + env->diry * cos(-env->rotspeed);
	env->planex = env->planex * cos(-env->rotspeed) - env->planey * sin(-env->rotspeed);
	env->planey = oldPlanex * sin(-env->rotspeed) + env->planey * cos(-env->rotspeed);
}

void	rotate_left(t_env *env)
{
	double	oldDirx;
	double	oldPlanex;

	oldDirx = env->dirx;
	oldPlanex = env->planex;
	env->dirx = env->dirx * cos(env->rotspeed) - env->diry * sin(env->rotspeed);
	env->diry = oldDirx * sin(-env->rotspeed) + env->diry * cos(env->rotspeed);
	env->planex = env->planex * cos(env->rotspeed) - env->planey * sin(env->rotspeed);
	env->planey = oldPlanex * sin(env->rotspeed) + env->planey * cos(env->rotspeed);
}
