/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 14:38:46 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/20 12:41:22 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static t_node	*convert_map(t_node *list, char *line)
{
	int			x;
	char		**map;
	static int	y;
	t_node		*elem;

	x = 0;
	map = ft_strsplit(line, ' ');
	while (map[x])
	{
		elem = init_node();
		elem->x = x;
		elem->y = y;
		elem->z = ft_atoi(map[x]);
		list = insert_node(list, elem);
		x++;
	}
	y++;
	free(map);
	return (list);
}

static void		check_line(char *line)
{
	long	i;

	i = 0;
	if (line[0] != '1' || line[ft_strlen(line) - 1] != '1')
		ft_error("\033[31;1mBorder's error.\033[0m");
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '1' || line[i] == '0')
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

t_node			*get_map(int fd)
{
	char		*line;
	t_node		*new;
	static int	x;

	new = NULL;
	if (get_next_line(fd, &line))
	{
		check_border(line);
		x = ft_tablen(ft_strsplit(line, ' '));
		new = convert_map(new, line);
	}
	else
		ft_error("\033[31;1mError when reading the file.\033[0m");
	while (get_next_line(fd, &line))
	{
		check_line(line);
		if (ft_tablen(ft_strsplit(line, ' ')) != x)
			ft_error("\033[31;1mMap isn't a square.\033[0m");
		new = convert_map(new, line);
	}
	check_border(line);
	return (new);
}
