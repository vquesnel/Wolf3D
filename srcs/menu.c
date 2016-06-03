/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 13:49:02 by vquesnel          #+#    #+#             */
/*   Updated: 2016/06/03 13:16:49 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	commands(void)
{
	ft_putendl("     \033[31;1;4mPARAMETERS\033[0m");
	ft_putendl("Moove    :  \033[34;1mArrows\033[0m");
	ft_putendl("L_Rotate :    \033[34;1ma\033[0m");
	ft_putendl("R_Rotate :    \033[34;1md\033[0m");
	ft_putendl("Mute     :    \033[34;1mm\033[0m");
	ft_putendl("Musics   : \033[34;1m1 to 3\033[0m");
	ft_putendl("Quit     :   \033[34;1mesc\033[0m");
	ft_putendl("Reset    :  \033[34;1mspace\033[0m");
}

