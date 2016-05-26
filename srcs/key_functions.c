/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 14:20:21 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/26 20:19:01 by vquesnel         ###   ########.fr       */
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
	if(!searchinlist((int)env->posx, (int)(env->posy -
	env->diry * env->movespeed), env))
		env->posy -= env->diry * env->movespeed;
	else
		ft_putstr("\a");
}

void	moove_left(t_env *env)
{
	if (!searchinlist((int)(env->posx - env->planex * env->movespeed), (int)(env->posy), env))
		env->posx -= env->planex * env->movespeed;
	if (!searchinlist((int)(env->posx), (int)(env->posy - env->planey * env->movespeed), env))
		env->posy -= env->planey * env->movespeed;
}

void	moove_right(t_env *env)
{
		if (!searchinlist((int)(env->posx + env->planex * env->movespeed), (int)(env->posy), env))
		env->posx += env->planex * env->movespeed;
	if (!searchinlist((int)(env->posx), (int)(env->posy + env->planey * env->movespeed), env))
		env->posy += env->planey * env->movespeed;
}

void	rotate_right(t_env *env)
{
	double	olddirx;
	double	oldplanex;

	olddirx = env->dirx;
	oldplanex = env->planex;
	env->dirx = env->dirx * cos(-0.1) - env->diry *
		sin(-0.1);
	env->diry = olddirx * sin(-0.1) + env->diry *
		cos(-0.1);
	env->planex = env->planex * cos(-0.1) - env->planey *
		sin(-0.1);
	env->planey = oldplanex * sin(-0.1) + env->planey *
		cos(-0.1);
}

void	rotate_left(t_env *env)
{
	double	olddirx;
	double	oldplanex;

	olddirx = env->dirx;
	oldplanex = env->planex;
	env->dirx = env->dirx * cos(0.1) - env->diry *
		sin(0.1);
	env->diry = olddirx * sin(0.1) + env->diry *
		cos(0.1);
	env->planex = env->planex * cos(0.1) - env->planey *
		sin(0.1);
	env->planey = oldplanex * sin(0.1) + env->planey *
		cos(0.1);
}

void	select_music(int keycode, t_env *env)
{
	if (env->music)
		system("killall afplay");
	if (keycode == M1)
	{
		system("afplay musics/mario.mp3&");
		env->music = 1;
	}
	if (keycode == M2)
	{
		system("afplay musics/song.mp3&");
		env->music = 1;
	}
	if (keycode == M3)
	{
		system("afplay musics/tetris.mp3&");
		env->music = 1;
	}
	if (keycode == MUTE)
		env->music = 0;
}
