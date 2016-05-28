/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 12:11:39 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/28 11:46:49 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "mlx.h"
# include "libft.h"
# include "struct.h"
# include "define.h"
# include <stdio.h>
# include <time.h>
# include <math.h>

t_env		*init_env(void);
t_img		*init_img(t_env *env);
void		ray_cast(t_env *env);
void		pixel_to_image(t_env *env, int x, int y, int color);
int			key_funct(int keycode, t_env *env);
void		moove_forward(t_env *env);
void		moove_left(t_env *env);
void		moove_right(t_env *env);
void		moove_backwards(t_env *env);
void		rotate_right(t_env *env);
void		rotate_left(t_env *env);
void		select_music(int keycode, t_env *env);
void		expose(t_env *env);
int			**create_tab(t_env *env);
t_texture	*create_xpm(t_env *env);
void		init_param(t_env *env, int x);
void		check_wall(t_env *env);
void		select_color(t_env *env);
int			check_map(int x, int y);
void		menu(t_env *env);
void		reset(t_env *env);

#endif
