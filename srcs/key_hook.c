/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 14:29:30 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/24 20:30:02 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		key_funct(int keycode, t_env *env)
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
	mlx_destroy_image(env->mlx, env->img->img);
	env->img = init_img(env);
	expose(env);
	return (0);
}
