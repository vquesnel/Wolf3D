/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 15:03:50 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/24 21:22:20 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_env	*new_env(void)
{
	t_env	*env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	env->name = NULL;
	env->mlx = NULL;
	env->win = NULL;
	env->img = NULL;
	return (env);
}

t_env	*init_env(int fd)
{
	t_env	*env;

	if (!(env = new_env()))
		return (NULL);
	env->name = "WOLF3d";
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, X_SIZE, Y_SIZE, env->name);
	env->img = init_img(env);
	env->x_max = 0;
	env->y_max = 0;
	env->map = get_map(fd, env);
	env->posx = env->x_max / 2;
	env->posy = env->y_max / 2;
	env->dirx = 1;
	env->diry = 0;
	env->planex = 0;
	env->planey = 0.66;
	env->time = 0;
	env->oldtime = env->time;
	env->time = clock();
	env->fps = (env->time - env->oldtime) / 1000.0;
	env->movespeed = env->fps * 0.003;
	env->rotspeed = env->fps * 0.001;
	return (env);
}
