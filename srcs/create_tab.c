/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 19:31:56 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/26 19:37:07 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		**create_tab(t_env *env)
{
	int		**buftext;
	int		i;

	i = 0;
	if (!(buftext = (int **)malloc(sizeof(int *) * (Y_SIZE + 1))))
		return (NULL);
	while (i < Y_SIZE)
	{
		buftext[i] = &env->tab[i * X_SIZE];
		i++;
	}
	buftext[i] = NULL;
	return (buftext);
}
