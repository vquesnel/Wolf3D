/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_one_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 15:24:14 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/23 14:18:20 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void			draw_vertical(int x, t_env *env)
{
	if (env->drawStart < env->drawEnd)
	{
		while (env->drawStart <= env->drawEnd)
		{
			pixel_to_image(env,x, env->drawStart, env->color);
			env->drawStart++;
		}
	}
	else
	{
		while (env->drawStart >= env->drawEnd)
		{
			pixel_to_image(env, x, env->drawStart, env->color);
			env->drawStart--;
		}
	}
}
