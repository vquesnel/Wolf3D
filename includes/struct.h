/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 12:14:33 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/24 16:32:18 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef stRUCt_h
# define stRUCt_h

typedef struct		s_node
{
	int				x;
	int				y;
	int				z;
	struct s_node	*next;
}					t_node;

typedef struct	s_img
{
	void		*img;
	char		*data;
	int			bpp;
	int			sizeline;
	int			endian;
}				t_img;

typedef struct		s_env
{
	char	*name;
	void	*mlx;
	void	*win;
	t_node	*map;
	int		x_max;
	int		y_max;
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	clock_t	time;
	clock_t	oldtime;
	int		fps;
	double	cam_x;
	int		mapx;
	int		mapy;
	double	rayposx;
	double	rayposy;
	double	raydirx;
	double	raydiry;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		lineheight;
	int		drawstart;
	int		drawend;
	int		color;
	double	movespeed;
	double	rotspeed;
	t_img	*img;
}					t_env;

#endif
