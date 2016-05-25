/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 12:14:33 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/25 17:12:26 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct		s_node
{
	int				x;
	int				y;
	int				z;
	struct s_node	*next;
}					t_node;

typedef struct		s_img
{
	void		*img;
	char		*data;
	int			bpp;
	int			sizeline;
	int			endian;
}					t_img;

typedef struct		s_env
{
	void		*mlx;
	void		*win;
	t_node		*map;
	int			x_max;
	int			y_max;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	clock_t		time;
	clock_t		oldtime;
	double		fps;
	double		cam_x;
	int			mapx;
	int			mapy;
	double		rposx;
	double		rposy;
	double		raydirx;
	double		raydiry;
	double		sidedistx;
	double		sidedisty;
	double		deltx;
	double		delty;
	double		perpwalldist;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			lineheight;
	int			drawstart;
	int			drawend;
	int			color;
	double		movespeed;
	double		rotspeed;
	t_img		*img;
}					t_env;

#endif
