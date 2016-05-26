/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 11:14:33 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/26 12:55:42 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		power(int nb)
{
	int		power;

	power = 16;
	while (power < nb)
		power = power * 16;
	if (power > nb)
		power = power / 16;
	return (power);
}

void			ft_print_hex(int nb)
{
	int		pwr;
	int		index;
	int		rest;
	char	*hex;

	hex = "0123456789abcdef";
	pwr = power(nb);
	while (pwr > 0)
	{
		index = nb / pwr;
		rest = nb % pwr;
		write(1, &hex[index], 1);
		pwr = pwr / 16;
		nb = rest;
	}
}
