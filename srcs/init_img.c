/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 14:26:15 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/19 14:53:19 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_img		*init_img(t_env *env)
{
	t_img	*img;

	if (!(img = (t_img *)malloc(sizeof(t_img))))
		ft_error("Can't create image.");
	img->img = mlx_new_image(env->mlx, X_SIZE, Y_SIZE);
	img->data = mlx_get_data_addr(img->img, &img->bpp, \
			&img->sizeline, &img->endian);
	return (img);
}

void		pixel_to_image(t_env *env, int x, int y, int color)
{
	int		octet;

	octet = env->img->bpp / 8;
	if (x > 0 && x < X_SIZE && y > 0 && y < Y_SIZE)
		ft_memcpy(&env->img->data[octet * (x + env->img->sizeline / \
					octet * y)], &color, octet);
}
