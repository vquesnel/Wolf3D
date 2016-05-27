/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 15:03:50 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/27 12:18:13 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	check_pos(t_env *env)
{
	env->posx = (double)env->x_max / 2;
	env->posy = (double)env->y_max / 2;
	if (searchinlist(env->posx, env->posy, env))
		ft_error("\033[31;1mStarting point is a wall!\033[0m");
	else if (searchinlist(env->posx + 1, env->posy, env))
		ft_error("\033[31;1mStarting point is too close to wall!\033[0m");
	else if (searchinlist(env->posx - 1, env->posy, env))
		ft_error("\033[31;1mStarting point is too close to wall!\033[0m");
	else if (searchinlist(env->posx, env->posy + 1, env))
		ft_error("\033[31;1mStarting point is too close to wall!\033[0m");
	else if (searchinlist(env->posx, env->posy - 1, env))
		ft_error("\033[31;1mStarting point is too close to wall!\033[0m");
}

static void	init_win(t_env *env)
{
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, X_SIZE, Y_SIZE, "Wolf3D @42");
	env->img = init_img(env);
	if (!env->mlx || !env->win || !env->img)
		ft_error("\033[31;1mError when creating the window.\033[0m");
}

t_env		*init_env(int fd)
{
	t_env	*env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	env->map = get_map(fd, env);
	check_pos(env);
	init_win(env);
	env->x_max = 0;
	env->y_max = 0;
	env->dirx = -1;
	env->diry = 0;
	env->time = 0;
	env->planex = 0;
	env->planey = 0.66;
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
