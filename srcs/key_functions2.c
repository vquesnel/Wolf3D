/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 12:13:50 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/27 12:15:13 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	moove_forward(t_env *env)
{
	if (!searchinlist((int)(env->posx + env->dirx * env->movespeed),
				(int)env->posy, env))
		env->posx += env->dirx * env->movespeed;
	if (!searchinlist((int)env->posx, (int)(env->posy +
					env->diry * env->movespeed), env))
		env->posy += env->diry * env->movespeed;
	else
		ft_putstr("\a");
}

void	moove_backwards(t_env *env)
{
	if (!searchinlist((int)(env->posx - env->dirx * env->movespeed),
				(int)env->posy, env))
		env->posx -= env->dirx * env->movespeed;
	if (!searchinlist((int)env->posx, (int)(env->posy -
					env->diry * env->movespeed), env))
		env->posy -= env->diry * env->movespeed;
	else
		ft_putstr("\a");
}

void	moove_left(t_env *env)
{
	if (!searchinlist((int)(env->posx - env->planex * env->movespeed),
				(int)(env->posy), env))
		env->posx -= env->planex * env->movespeed;
	if (!searchinlist((int)(env->posx), (int)(env->posy - env->planey *
					env->movespeed), env))
		env->posy -= env->planey * env->movespeed;
}

void	moove_right(t_env *env)
{
	if (!searchinlist((int)(env->posx + env->planex * env->movespeed),
				(int)(env->posy), env))
		env->posx += env->planex * env->movespeed;
	if (!searchinlist((int)(env->posx), (int)(env->posy + env->planey *
					env->movespeed), env))
		env->posy += env->planey * env->movespeed;
}
