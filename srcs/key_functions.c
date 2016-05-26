/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 14:20:21 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/26 15:11:43 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	moove_forward(t_env *env)
{
	if (!searchinlist((int)(env->posx + env->dirx * env->movespeed),
				(int)env->posy, env) && !searchinlist((int)env->posx,
					(int)(env->posy + env->diry * env->movespeed), env))
	{
		env->posx += env->dirx * env->movespeed;
		env->posy += env->diry * env->movespeed;
	}
	else
		ft_putstr("\a");
}

void	moove_backwards(t_env *env)
{
	if (!searchinlist((int)(env->posx - env->dirx * env->movespeed),
				(int)env->posy, env) && !searchinlist((int)env->posx,
					(int)(env->posy - env->diry * env->movespeed), env))
	{
		env->posx -= env->dirx * env->movespeed;
		env->posy -= env->diry * env->movespeed;
	}
	else
		ft_putstr("\a");
}

void	rotate_right(t_env *env)
{
	double	olddirx;
	double	oldplanex;

	olddirx = env->dirx;
	oldplanex = env->planex;
	env->dirx = env->dirx * cos(-env->rotspeed) - env->diry *
		sin(-env->rotspeed);
	env->diry = olddirx * sin(-env->rotspeed) + env->diry *
		cos(-env->rotspeed);
	env->planex = env->planex * cos(-env->rotspeed) - env->planey *
		sin(-env->rotspeed);
	env->planey = oldplanex * sin(-env->rotspeed) + env->planey *
		cos(-env->rotspeed);
}

void	rotate_left(t_env *env)
{
	double	olddirx;
	double	oldplanex;

	olddirx = env->dirx;
	oldplanex = env->planex;
	env->dirx = env->dirx * cos(env->rotspeed) - env->diry *
		sin(env->rotspeed);
	env->diry = olddirx * sin(env->rotspeed) + env->diry *
		cos(env->rotspeed);
	env->planex = env->planex * cos(env->rotspeed) - env->planey *
		sin(env->rotspeed);
	env->planey = oldplanex * sin(env->rotspeed) + env->planey *
		cos(env->rotspeed);
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
