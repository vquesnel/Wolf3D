/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_xpm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 19:43:03 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/27 13:46:35 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	xpm_to_image(t_texture *tex, t_env *env)
{
	int			width;
	int			height;

	tex->text1 = mlx_xpm_file_to_image(env->mlx, "./textures/wall.xpm",
			&width, &height);
	tex->text2 = mlx_xpm_file_to_image(env->mlx, "./textures/wall_tag.xpm",
			&width, &height);
	tex->text3 = mlx_xpm_file_to_image(env->mlx, "./textures/wall7.xpm",
			&width, &height);
	tex->text4 = mlx_xpm_file_to_image(env->mlx, "./textures/unnamed.xpm", &width,
			&height);
	tex->textsol = mlx_xpm_file_to_image(env->mlx, "./textures/sable.xpm",
			&width, &height);
	tex->textroof = mlx_xpm_file_to_image(env->mlx, "./textures/arcenciel.xpm",
			&width, &height);
	if (!tex->text1 || !tex->text2 || !tex->text3 || !tex->text4 ||
			!tex->textsol || !tex->textroof)
		ft_error("Error when extracting xpm files.");
}

t_texture	*create_xpm(t_env *env)
{
	t_texture	*tex;

	if (!(tex = (t_texture *)malloc(sizeof(t_texture))))
		return (NULL);
	xpm_to_image(tex, env);
	tex->tab1 = (int *)mlx_get_data_addr(tex->text1, &tex->bpp, &tex->sizeline,
			&tex->endian);
	tex->tab2 = (int*)mlx_get_data_addr(tex->text2, &tex->bpp, &tex->sizeline,
			&tex->endian);
	tex->tab3 = (int *)mlx_get_data_addr(tex->text3, &tex->bpp, &tex->sizeline,
			&tex->endian);
	tex->tab4 = (int *)mlx_get_data_addr(tex->text4, &tex->bpp, &tex->sizeline,
			&tex->endian);
	tex->sol = (int *)mlx_get_data_addr(tex->textsol, &tex->bpp, &tex->sizeline,
			&tex->endian);
	tex->roof = (int *)mlx_get_data_addr(tex->textroof, &tex->bpp,
			&tex->sizeline, &tex->endian);
	if (!tex->tab1 || !tex->tab2 || !tex->tab3 || !tex->tab4 ||
			!tex->sol || !tex->roof)
		ft_error("Error when extracting xpm files.");
	return (tex);
}
