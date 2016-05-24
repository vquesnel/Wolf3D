/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 14:42:59 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/24 16:34:54 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_node		*init_node(void)
{
	t_node	*node;

	if (!(node = (t_node *)malloc(sizeof(t_node))))
		return (NULL);
	node->x = 0;
	node->y = 0;
	node->z = 0;
	node->next = NULL;
	return (node);
}

t_node		*insert_node(t_node *node, t_node *elem)
{
	static t_node	*tmp;

	if (!tmp)
		tmp = node;
	if (!tmp)
		return (elem);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = elem;
	return (node);
}
