/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_xpm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 19:43:03 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/30 11:26:07 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	xpm_to_image(t_texture *tex, t_env *env)
{
	int			width;
	int			height;

	tex->text1 = mlx_xpm_file_to_image(env->mlx, "./textures/wall1.xpm",
			&width, &height);
	tex->text2 = mlx_xpm_file_to_image(env->mlx, "./textures/wall2.xpm",
			&width, &height);
	tex->text3 = mlx_xpm_file_to_image(env->mlx, "./textures/wall3.xpm",
			&width, &height);
	tex->text4 = mlx_xpm_file_to_image(env->mlx, "./textures/wall4.xpm",
			&width, &height);
	tex->text5 = mlx_xpm_file_to_image(env->mlx, "./textures/kwiessle.xpm",
			&width, &height);
	tex->text6 = mlx_xpm_file_to_image(env->mlx, "./textures/psyche.xpm",
			&width, &height);
	tex->text7 = mlx_xpm_file_to_image(env->mlx, "./textures/vquesnel.xpm",
			&width, &height);
	tex->textsol = mlx_xpm_file_to_image(env->mlx, "./textures/floor.xpm",
			&width, &height);
	tex->textroof = mlx_xpm_file_to_image(env->mlx, "./textures/neon.xpm",
			&width, &height);
	if (!tex->text1 || !tex->text2 || !tex->text3 || !tex->text4 || !tex->text7
			|| !tex->text5 || !tex->text6 || !tex->textsol || !tex->textroof)
		ft_error("Error when extracting xpm files.");
}

t_texture	*create_xpm(t_env *env)
{
	t_texture	*tex;

	if (!(tex = (t_texture *)malloc(sizeof(t_texture))))
		return (NULL);
	xpm_to_image(tex, env);
	tex->tab1 = (int *)MLXGDATA(tex->text1, &tex->bpp, &tex->sl, &tex->ed);
	tex->tab2 = (int *)MLXGDATA(tex->text2, &tex->bpp, &tex->sl, &tex->ed);
	tex->tab3 = (int *)MLXGDATA(tex->text3, &tex->bpp, &tex->sl, &tex->ed);
	tex->tab4 = (int *)MLXGDATA(tex->text4, &tex->bpp, &tex->sl, &tex->ed);
	tex->tab5 = (int *)MLXGDATA(tex->text5, &tex->bpp, &tex->sl, &tex->ed);
	tex->tab6 = (int *)MLXGDATA(tex->text6, &tex->bpp, &tex->sl, &tex->ed);
	tex->tab7 = (int *)MLXGDATA(tex->text7, &tex->bpp, &tex->sl, &tex->ed);
	tex->sol = (int *)MLXGDATA(tex->textsol, &tex->bpp, &tex->sl, &tex->ed);
	tex->roof = (int *)MLXGDATA(tex->textroof, &tex->bpp, &tex->sl, &tex->ed);
	if (!tex->tab1 || !tex->tab2 || !tex->tab3 || !tex->tab4 || !tex->tab5 ||
			!tex->tab6 || !tex->tab7 || !tex->sol || !tex->roof)
		ft_error("Error when extracting xpm files.");
	return (tex);
}
