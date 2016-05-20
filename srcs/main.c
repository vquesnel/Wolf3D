/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 12:15:32 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/20 12:41:01 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		main(int ac, char **av)
{
	t_node	*node;
	int		fd;

	if (ac != 2)
		ft_error("Usage: ./wolf3d <map>");
	if ((fd = open(av[1], O_RDONLY)) < 0)
		ft_error("\033[31;1mError when openning file.\033[0m");
	node = get_map(fd);
	while (node)
	{
		printf("%d\n", node->z);
		node = node->next;
	}
	return (0);
}
