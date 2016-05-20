/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 12:11:39 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/20 12:23:44 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "mlx.h"
# include "libft.h"
# include <math.h>
# include "struct.h"
# include <stdio.h>

t_node	*get_map(int fd);
t_node	*init_node(void);
t_node	*insert_node(t_node *node, t_node *elem);

#endif
