/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 12:13:50 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/28 11:48:55 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	moove_forward(t_env *env)
{
	if (!check_map((int)(env->posx + env->dirx * env->movespeed),
				(int)env->posy))
		env->posx += env->dirx * env->movespeed;
	else
		ft_putstr("\a");
	if (!check_map((int)env->posx, (int)(env->posy +
					env->diry * env->movespeed)))
		env->posy += env->diry * env->movespeed;
	else
		ft_putstr("\a");
}

void	moove_backwards(t_env *env)
{
	if (!check_map((int)(env->posx - env->dirx * env->movespeed),
				(int)env->posy))
		env->posx -= env->dirx * env->movespeed;
	else
		ft_putstr("\a");
	if (!check_map((int)env->posx, (int)(env->posy -
					env->diry * env->movespeed)))
		env->posy -= env->diry * env->movespeed;
	else
		ft_putstr("\a");
}

void	moove_left(t_env *env)
{
	if (!check_map((int)(env->posx - env->planex * env->movespeed),
				(int)(env->posy)))
		env->posx -= env->planex * env->movespeed;
	else
		ft_putstr("\a");
	if (!check_map((int)(env->posx), (int)(env->posy - env->planey *
					env->movespeed)))
		env->posy -= env->planey * env->movespeed;
	else
		ft_putstr("\a");
}

void	moove_right(t_env *env)
{
	if (!check_map((int)(env->posx + env->planex * env->movespeed),
				(int)(env->posy)))
		env->posx += env->planex * env->movespeed;
	else
		ft_putstr("\a");
	if (!check_map((int)(env->posx), (int)(env->posy + env->planey *
					env->movespeed)))
		env->posy += env->planey * env->movespeed;
	else
		ft_putstr("\a");
}

void	reset(t_env *env)
{
	env->posx = 3;
	env->posy = 5;
	env->x_max = 0;
	env->y_max = 0;
	env->dirx = -1;
	env->diry = 0;
	env->time = 0;
	env->planex = 0;
	env->planey = 0.66;
	env->color = 0.0;
}
