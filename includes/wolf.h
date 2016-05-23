/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 12:11:39 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/23 14:27:39 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "mlx.h"
# include "libft.h"
# include <math.h>
# include "struct.h"
# include "define.h"
# include <stdio.h>

char	**get_map(int fd, t_env *env);
t_node	*init_node(void);
t_node	*insert_node(t_node *node, t_node *elem);
t_env	*init_env(int fd);
t_img	*init_img(t_env *env);
void	ray_cast(t_env *env);
void	draw_vertical(int x, t_env *env);
void		pixel_to_image(t_env *env, int x, int y, int color);

#endif
