/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 14:20:21 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/27 12:14:05 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

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
