/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_one_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 15:24:14 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/25 16:17:10 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void			draw_vertical(int x, t_env *env)
{
	if (env->drawstart < env->drawend)
	{
		while (env->drawstart <= env->drawend)
		{
			pixel_to_image(env, x, env->drawstart, env->color);
			env->drawstart++;
		}
	}
	else
	{
		while (env->drawstart >= env->drawend)
		{
			pixel_to_image(env, x, env->drawstart, env->color);
			env->drawstart--;
		}
	}
}
