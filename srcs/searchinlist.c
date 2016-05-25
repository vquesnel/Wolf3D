/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchinlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 15:34:51 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/25 11:59:56 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		searchinlist(int x, int y, t_env *env)
{
	t_node	*tmp;

	tmp = env->map;
	while (tmp)
	{
		if (tmp->y == y && tmp->x == x)
			return (tmp->z);
		tmp = tmp->next;
	}
	printf("erreur\n");
	return (1);
}
