/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 16:12:15 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/28 13:47:18 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define X_SIZE 800
# define Y_SIZE 800
# define MLXGDATA(x, y, z, a) mlx_get_data_addr(x, y, z, a)
/*
** KEYCODE
*/

# define ESC 53
# define LEFT 123
# define RIGHT 124
# define LROTATE 0
# define RROTATE 2
# define FORWARD 126
# define BACKWARDS 125
# define SPACE 49
# define M1 18
# define M2 19
# define M3 20
# define MUTE 46

#endif
