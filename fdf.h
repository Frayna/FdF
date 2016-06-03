/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgourran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/29 01:30:58 by pgourran          #+#    #+#             */
/*   Updated: 2016/05/29 02:50:57 by pgourran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "libft.h"
# define ESCAPE 53
# define LEFT 123
# define RIGHT 124
# define UP 126
# define DOWN 125

typedef struct		s_dot
{
	int				x;
	int				y;
	int				color;
	void			*win;
	void			*mlx;
	struct s_dot	*next;
}					t_dot;

#endif
