/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 14:29:30 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/28 14:11:23 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int	close_win(t_env *env)
{
	if (env->music)
		system("killall afplay");
	free(env);
	exit(EXIT_SUCCESS);
}

int			key_funct(int keycode, t_env *env)
{
	if (env->mlx == NULL)
		return (0);
	if (keycode == ESC)
		close_win(env);
	if (keycode == FORWARD)
		moove_forward(env);
	if (keycode == BACKWARDS)
		moove_backwards(env);
	if (keycode == LEFT)
		moove_left(env);
	if (keycode == RIGHT)
		moove_right(env);
	if (keycode == LROTATE)
		rotate_left(env);
	if (keycode == RROTATE)
		rotate_right(env);
	if (keycode == M1 || keycode == M2 || keycode == M3 || keycode == MUTE)
		select_music(keycode, env);
	if (keycode == SPACE)
		reset(env);
	expose(env);
	return (0);
}

static void	empty_buftext(t_env *env)
{
	int x;
	int y;

	y = 0;
	while (y < Y_SIZE)
	{
		x = 0;
		while (x < X_SIZE)
		{
			env->buftext[y][x] = 0;
			x++;
		}
		y++;
	}
}

void		expose(t_env *env)
{
	empty_buftext(env);
	mlx_hook(env->win, 2, 1, key_funct, env);
	mlx_hook(env->win, 17, 1L << 17, close_win, env);
	mlx_loop_hook(env->mlx, ray_cast, env);
	mlx_loop(env->mlx);
}
