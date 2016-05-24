/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchinlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 15:34:51 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/24 20:15:01 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		searchinlist(int x, int y, t_env *env)
{
	t_node	*tmp;

	tmp = env->map;
	while (tmp->y != y)
		tmp = tmp->next;
	while (tmp->x != x)
		tmp = tmp->next;
	if (!tmp)
		return (0);
	else
		return (tmp->z);
}
