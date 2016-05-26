/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchinlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 15:34:51 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/26 13:27:47 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		searchinlist(int x, int y, t_env *env)
{
	t_node	*tmp;

	if (!(tmp = (t_node *)malloc(sizeof(t_node))))
		ft_error("Malloc error");
	tmp =env->map;
	while (tmp)
	{
		if (tmp->y == y && tmp->x == x)
			return (tmp->z);
		tmp = tmp->next;
	}
	return (1);
}
