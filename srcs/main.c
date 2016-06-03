/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 12:15:32 by vquesnel          #+#    #+#             */
/*   Updated: 2016/06/03 13:09:00 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		main(int ac, char **av)
{
	t_env	*env;

	if (ac != 1)
		ft_error("\033[31;1mUsage: ./wolf3d \033[0m");
	if (!(env = init_env()))
		ft_error("\033[31;1mMalloc Error.\033[0m");
	commands();
	expose(env);
	return (0);
}
