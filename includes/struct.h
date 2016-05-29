/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 12:14:33 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/29 18:36:29 by vquesnel         ###   ########.fr       */
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

typedef struct		s_texture
{
	int		bpp;
	int		sl;
	int		ed;
	void	*text1;
	int		*tab1;
	void	*text2;
	int		*tab2;
	void	*text3;
	int		*tab3;
	void	*text4;
	int		*tab4;
	void	*text5;
	int		*tab5;
	void	*text6;
	int		*tab6;
	void	*text7;
	int		*tab7;
	void	*textsol;
	int		*sol;
	void	*textroof;
	int		*roof;
}					t_texture;

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
	double		movespeed;
	int			music;
	double		wallx;
	int			texx;
	int			texy;
	double		floorxwall;
	double		floorywall;
	double		currentfloorx;
	double		currentfloory;
	int			floortexx;
	int			floortexy;
	double		distwall;
	double		distplayer;
	int			*tab;
	int			**buftext;
	double		currentdist;
	double		weight;
	double		color;
	int			menu;
	t_img		*img;
	t_texture	*tex;
}					t_env;

#endif
