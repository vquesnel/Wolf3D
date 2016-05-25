/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 14:29:30 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/25 10:19:17 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			key_funct(int keycode, t_env *env)
{
	if (env->mlx == NULL)
		return (0);
	if (keycode == ESC)
		exit(EXIT_SUCCESS);
	if (keycode == FORWARD)
		moove_forward(env);
	if (keycode == BACKWARDS)
		moove_backwards(env);
	if (keycode == LEFT)
		rotate_right(env);
	if (keycode == RIGHT)
		rotate_left(env);
	expose(env);
	return (0);
}

static int	close_win(t_env *e)
{
	free(e);
	exit(EXIT_SUCCESS);
}

void		expose(t_env *env)
{
	mlx_destroy_image(env->mlx, env->img->img);
	env->img = init_img(env);
	ray_cast(env);
	mlx_put_image_to_window(env->mlx, env->win, env->img->img, 0, 0);
	mlx_hook(env->win, 2, 3, key_funct, env);
	mlx_hook(env->win, 17, 1L << 17, close_win, env);
	mlx_loop(env->mlx);
}
