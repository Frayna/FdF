/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgourran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/29 01:30:58 by pgourran          #+#    #+#             */
/*   Updated: 2016/06/17 04:57:25 by pgourran         ###   ########.fr       */
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

typedef struct		s_dot
{
	char			**map;
	void			*win;
	void			*mlx;
	void			*img_ptr;
	char			*img;
	struct s_dot	*next;
}					t_dot;

/*
typedef struct		s_dot
{
	int				x;
	int				y;
	int				color;
	void			*win;
	void			*mlx;
	struct s_dot	*next;
}					t_dot;
*/
#endif
