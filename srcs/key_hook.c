/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 14:29:30 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/26 11:05:20 by vquesnel         ###   ########.fr       */
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
		rotate_left(env);
	if (keycode == RIGHT)
		rotate_right(env);
	if (keycode == M1 || keycode == M2 || keycode == M3 || keycode == MUTE)
		select_music(keycode, env);
	expose(env);
	return (0);
}

void		expose(t_env *env)
{
	if (env->img->img)
		mlx_destroy_image(env->mlx, env->img->img);
	if (!(env->img = init_img(env)))
		ft_error("impossible to create image.");
	ray_cast(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img->img, 0, 0);
	mlx_hook(env->win, 2, 1, key_funct, env);
	mlx_hook(env->win, 17, 1L << 17, close_win, env);
	mlx_loop(env->mlx);
}
