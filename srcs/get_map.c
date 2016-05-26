/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 10:18:36 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/26 20:08:01 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static t_node	*convert_map(t_node *list, t_env *env, char *line)
{
	int			x;
	char		**map;
	static int	y;
	t_node		*elem;

	x = 0;
	map = ft_strsplit(line, ' ');
	while (map[x])
	{
		if (!(elem = (t_node *)malloc(sizeof(t_node))))
			return (NULL);
		elem->x = x;
		elem->y = y;
		elem->z = ft_atoi(map[x]);
		elem->next = NULL;
		list = insert_node(list, elem);
		x++;
	}
	y++;
	env->x_max = x;
	env->y_max = y;
	ft_clear_tab((void **)map);
	return (list);
}

static void		check_line(char *line)
{
	int	i;

	i = 0;
	if (line[0] == '0' || line[ft_strlen(line) - 1] == '0')
		ft_error("\033[31;1mBorder's error.\033[0m");
	while (line[i])
	{
		if (line[i] == ' ' || (line[i] >= '0' && line[i] <= '9'))
			i++;
		else
			ft_error("\033[31;1mMap must be made of numbers.\033[0m");
	}
}

static void		check_border(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ' || (line[i] >= '1' && line[i] <= '9'))
			i++;
		else
			ft_error("\033[31;1mBorder's error!\033[0m");
	}
}

t_node			*get_map(int fd, t_env *env)
{
	char		*line;
	t_node		*new;
	int			x;

	new = NULL;
	if (get_next_line(fd, &line))
	{
		check_border(line);
		x = ft_tablen(ft_strsplit(line, ' '));
		new = convert_map(new, env, line);
		free(line);
	}
	else
		ft_error("\033[31;1mError when reading the file.\033[0m");
	while (get_next_line(fd, &line))
	{
		check_line(line);
		if (ft_tablen(ft_strsplit(line, ' ')) != x)
			ft_error("\033[31;1mMap isn't a square.\033[0m");
		new = convert_map(new, env, line);
	}
	check_border(line);
	free(line);
	return (new);
}
