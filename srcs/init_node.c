/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 14:42:59 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/26 14:31:55 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_node		*insert_node(t_node *node, t_node *elem)
{
	t_node	*tmp;

	if (!node)
		return (elem);
	if (!(tmp = (t_node *)malloc(sizeof(t_node))))
		return (NULL);
	tmp = node;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = elem;
	return (node);
}
