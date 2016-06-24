/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgourran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/29 01:30:58 by pgourran          #+#    #+#             */
/*   Updated: 2016/06/24 18:05:35 by pgourran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "libft.h"
# include "get_next_line.h"
# define ESCAPE 53
# define LEFT 123
# define RIGHT 124
# define UP 126
# define DOWN 125
# define WIN_X 1000
# define WIN_Y 1000
# define WIN_NAME "4242424242 YOOLLLOOOO"

typedef struct		s_clr
{
	long			cl_drw;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_clr;

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
	t_clr		*clr;
}				t_point;

typedef struct	s_img
{
	void		*img;
	int			bpp;
	int			sl;
	int			en;
	char		*data;
	int			ht;
	int			wh;
}				t_img;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	int			height;
	int			width;
	t_img		*imgs;
}				t_env;

typedef struct dt
{
	t_env		*env;
	t_point		*point;
	t_clr		*clr;
}				t_dt;

#endif
