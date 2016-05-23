/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 14:38:46 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/23 14:33:16 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
/*
static char	**convert_map(t_env *env, char *line)
{
	int			y;
	char		**split;
	static int	x;

	y = 0;
	split = ft_strsplit(line, ' ');
	while (split[y])
	{
		printf("split[y] = %s\n", split[y]);
		env->map[x][y] = *split[y];
		printf("coucu\n");
		y++;
	}
	x++;
	env->x_max = x;
	env->y_max = y;
	free(split);
	return (env->map);
}

static void		check_line(char *line)
{
	long	i;

	i = 0;
	if (line[0] != '1' || line[ft_strlen(line) - 1] != '1')
		ft_error("\033[31;1mBorder's error.\033[0m");
	while (line[i])
	{
		if (line[i] == ' ' || line[i] >= '0' || line[i] <= '9')
			i++;
		else
			ft_error("\033[31;1mMap must be made of 1 and 0.\033[0m");
	}
}

static void		check_border(char *line)
{
	long	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '1')
			i++;
		else
			ft_error("\033[31;1mBorder's error.\033[0m");
	}
}

char		**get_map(int fd, t_env *env)
{
	char		*line;
	char		**map;
	static int	x;

	if (get_next_line(fd, &line))
	{
		check_border(line);
		x = ft_tablen(ft_strsplit(line, ' '));
		map = (char **)malloc(sizeof(char *) * 100000);
		map = convert_map(env, line);
	}
	else
		ft_error("\033[31;1mError when reading the file.\033[0m");
	while (get_next_line(fd, &line))
	{
		check_line(line);
		if (ft_tablen(ft_strsplit(line, ' ')) != x)
			ft_error("\033[31;1mMap isn't a square.\033[0m");
		map = convert_map(env, line);
	}
	check_border(line);
	return (map);
}*/
