/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_xpm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 19:43:03 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/26 20:25:55 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_texture	*create_xpm(t_env *env)
{
	int			width;
	int			height;
	t_texture	*tex;

	if (!(tex = (t_texture *)malloc(sizeof(t_texture))))
		return (NULL);
	tex->text1 = mlx_xpm_file_to_image(env->mlx, "./textures/redbrick.xpm", &width, &height);
	tex->tab1 = (int *)mlx_get_data_addr(tex->text1, &tex->bpp, &tex->sizeline, &tex->endian);
	tex->text2 = mlx_xpm_file_to_image(env->mlx, "./textures/colorstone.xpm", &width, &height);
	tex->tab2 = (int*)mlx_get_data_addr(tex->text2, &tex->bpp, &tex->sizeline, &tex->endian);
	tex->textsol = mlx_xpm_file_to_image(env->mlx, "./textures/sol.xpm", &width, &height);
	tex->sol = (int*)mlx_get_data_addr(tex->textsol, &tex->bpp, &tex->sizeline, &tex->endian);
	tex->textroof = mlx_xpm_file_to_image(env->mlx, "./textures/cieletoile.xpm", &width, &height);
	tex->roof = (int*)mlx_get_data_addr(tex->textroof, &tex->bpp, &tex->sizeline, &tex->endian);
	tex->text3 = mlx_xpm_file_to_image(env->mlx, "./textures/brique_sable64.xpm", &width, &height);
	tex->tab3 = (int *)mlx_get_data_addr(tex->text3, &tex->bpp, &tex->sizeline, &tex->endian);
	tex->text4 = mlx_xpm_file_to_image(env->mlx, "./textures/carrelage.xpm", &width, &height);
	tex->tab4 = (int *)mlx_get_data_addr(tex->text4, &tex->bpp, &tex->sizeline, &tex->endian);
	return (tex);
}
