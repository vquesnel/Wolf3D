/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 15:03:50 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/29 18:40:41 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	init_win(t_env *env)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, X_SIZE + 200, Y_SIZE, "Wolf3D @42");
	env->img = init_img(env);
	env->menu = 0;
	if (!env->mlx || !env->win || !env->img)
		ft_error("\033[31;1mError when creating the window.\033[0m");
}

t_env		*init_env(void)
{
	t_env	*env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	env->posx = 3;
	env->posy = 5;
	init_win(env);
	env->x_max = 0;
	env->y_max = 0;
	env->dirx = -1;
	env->diry = 0;
	env->time = 0;
	env->planex = 0;
	env->planey = 0.66;
	env->color = 0.0;
	env->oldtime = env->time;
	env->time = clock();
	env->fps = (env->time - env->oldtime) / 1000.0;
	env->movespeed = env->fps * 0.003;
	env->music = 0;
	env->tab = (int *)mlx_get_data_addr(env->img->img, &env->img->bpp,
			&env->img->sizeline, &env->img->endian);
	env->buftext = create_tab(env);
	env->tex = create_xpm(env);
	return (env);
}
