/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 13:49:02 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/30 09:52:02 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	commands(t_env *env)
{
	char	*posx;
	char	*posy;

	posx = ft_itoa(env->posx);
	posy = ft_itoa(env->posy);
	mlx_string_put(env->mlx, env->win, 813, 20, 0xC1500D, "    PARAMETERS   ");
	mlx_string_put(env->mlx, env->win, 815, 70, 0x165AA4, "Moove    :  Arrows");
	mlx_string_put(env->mlx, env->win, 815, 110, 0x165AA4, "L_Rotate :    a ");
	mlx_string_put(env->mlx, env->win, 815, 150, 0x165AA4, "R_Rotate :    d  ");
	mlx_string_put(env->mlx, env->win, 815, 190, 0x165AA4, "Mute     :    m ");
	mlx_string_put(env->mlx, env->win, 815, 230, 0x165AA4, "Musics   : 1 to 3");
	mlx_string_put(env->mlx, env->win, 815, 270, 0x165AA4, "Quit     :   esc ");
	mlx_string_put(env->mlx, env->win, 815, 310, 0x165AA4, "Reset    :  space ");
	mlx_string_put(env->mlx, env->win, 813, 620, 0xC1500D, " CURRENT SETTINGS");
	mlx_string_put(env->mlx, env->win, 810, 670, 0x165AA4, "Current x :");
	mlx_string_put(env->mlx, env->win, 930, 670, 0x165AA4, posx);
	mlx_string_put(env->mlx, env->win, 810, 710, 0x165AA4, "Current y :");
	mlx_string_put(env->mlx, env->win, 930, 710, 0x165AA4, posy);
	free(posx);
	free(posy);
}

static void	music(t_env *env)
{
	if (!env->music)
	{
		mlx_string_put(env->mlx, env->win, 930, 750, 0x990000, "off");
		mlx_string_put(env->mlx, env->win, 810, 750, 0x165AA4, "Music     :");
	}
	else if (env->music == 1)
	{
		mlx_string_put(env->mlx, env->win, 810, 750, 0x165AA4, "Music     :");
		mlx_string_put(env->mlx, env->win, 930, 750, 0x10A943, "GTA");
	}
	else if (env->music == 2)
	{
		mlx_string_put(env->mlx, env->win, 885, 750, 0x10A943, "Broda Vibes");
		mlx_string_put(env->mlx, env->win, 810, 750, 0x165AA4, "Music :");
	}
	else if (env->music == 3)
	{
		mlx_string_put(env->mlx, env->win, 900, 750, 0x10A943, "Daft Punk");
		mlx_string_put(env->mlx, env->win, 810, 750, 0x165AA4, "Music  :");
	}
}

void		menu(t_env *env)
{
	int		x;
	int		y;

	x = 800;
	y = -1;
	while (y++ <= Y_SIZE)
		mlx_pixel_put(env->mlx, env->win, x, y, 0x165AA4);
	y = 340;
	while (y <= 610)
	{
		x = 800;
		while (x <= X_SIZE + 200)
		{
			mlx_pixel_put(env->mlx, env->win, x, y, 0x165AA4);
			x++;
		}
		y = y + 10;
	}
	music(env);
	commands(env);
}
