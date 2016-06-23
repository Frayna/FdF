/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgourran <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 19:23:58 by pgourran          #+#    #+#             */
/*   Updated: 2016/06/23 19:28:09 by pgourran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define DEFAULT_COLOR "0xFFFFFF"
int		ft_tablen(char **tab)
{
	int		i;

	i = 0;
	while(tab[i])
		i++;
	return(i);
}

/*
void	ft_tabdel(char **tab)
{
	int i;
	
	i = 0;
	while(tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_tabcpy(char	**dst, char		**src)
{
	int		i;

	i = 0;
	while(src[i])
	{
		dst[i] = ft_strnew(ft_strlen(src[i]));
		dst[i] = ft_strcpy(dst[i], src[i]);
		i++;
	}
	dst[i] = NULL;
}

char	**ft_newline(char **line, char *str)
{
	char	**save;
	int		i;
	char	**keep;

	keep = line;
	i = 0;
	if (!(save = malloc(sizeof(char **) * (ft_tablen(line) + 2))))
		return(NULL);
	while (save[i])
		i++;
	save[i] = ft_strnew(ft_strlen(str));
	save[i] = ft_strcpy(save[i], str);
	save[i + 1] = NULL;
	ft_tabcpy(save, line);
	return(save);
}
*/
/*
typedef struct		s_dot
{
	int				z;
	int				color;
	struct s_dot	*next_x;
	struct s_dot	*next_y;
}					t_dot;
*/
static char convert(const unsigned char c)
{
	if (c <= 9)
		return (c + '0');
	return (c + 'a' - 10);
}

void	put_hexa(const	unsigned char c)
{
//		ft_putstr("0x");
		ft_putchar(convert(c / 16));
		ft_putchar(convert(c % 16));
}

int		ft_ishexa(char c)
{
	if (ft_isdigit(c) || c == 'a' || c == 'b' || c == 'c' || c == 'd'
			|| c == 'e'|| c == 'f' || c == 'A' || c == 'B' || c == 'D'
			|| c == 'E' || c == 'F' || c == 'x')
		return(1);
	return(0);
}

unsigned int		ft_atohex(char c)
{
	if (ft_isdigit(c))
		return((unsigned int)(c - 48));
	else if (ft_isalpha(c) && c < 'G')
		return((unsigned int)(c - 55));
	else if (ft_isalpha(c) && c < 'g')
		return((unsigned int)(c - 87));
	return(0);
}

unsigned int		ft_hextoi(char *str)
{
	unsigned int	ret;
	int				i;

	i = 2;
	ret = 0;
	if (!(str[0] == '0' && str[1] == 'x'))
		return(ret);
	if (ft_ishexa(str[i]))
		ret = ft_atohex(str[i]);
	i++;
	while(str[i] && str[i] != ' ' && ft_ishexa(str[i]))
	{
		ret <<= 4;
		ret += ft_atohex(str[i]);
		i++;
	}
	return(ret);
}
/*

t_dot	*makeparam(char **map)
{
	t_dot	*dot;
	int		bpp;
	int		endian;
	int		size_line;

	bpp = 3 * 8;
	size_line = WIN_X * bpp;
	endian = 0;
	dot = malloc(sizeof(t_dot *));
	dot->map = map;
	dot.mlx = mlx_init();
	dot.win = mlx_new_window(dot.mlx, WIN_X, WIN_Y, WIN_NAME);
	dot.img_ptr = mlx_new_image(dot.mlx, WIN_X, WIN_Y);
	dot.img = mlx_get_data_addr(dot.img_ptr, &bpp, &endian)
	dot->next = NULL;
	
	
	
	
}

*/
char	*find_color(char *str)
{
	char	*ptr;

	ptr = str;
	
	while(ft_isdigit(*ptr))
		ptr++;
	if (*ptr == ',')
		return(ptr + 1);
	return(DEFAULT_COLOR);
}

/*
int main()
{
	unsigned int	hexa;
	unsigned char	*ptr;

	hexa = 0;
	hexa = ft_hextoi("0x000011");
	ptr = (unsigned char *)&hexa;
	put_hexa(ptr[0]);
	put_hexa(ptr[1]);
	put_hexa(ptr[2]);
	ft_putnbr((int)hexa);
}
*/

int		*int_line(char *str)
{
	int		*line;
	char	*ptr;
	int		size_line;
	int		i;

	i = 2;
	size_line = 1;
	ptr = str;
	while ((ptr = ft_strchr(ptr, ' ')))
	{
		while(!(ft_isdigit(*ptr)))
			ptr++;
		size_line++;
	}
	if (!(line = malloc(sizeof(int) * (size_line + 1))))
		return(NULL);
	line[0] = size_line;
	line[1] = ft_atoi(str);
	ptr = str;
	while ((ptr = ft_strchr(ptr, ' ')) && i <= size_line)
	{
		ptr++;
		line[i] = ft_atoi(ptr);
		i++;
	}
	return(line);
}




int main()
{
	int fd;
	char	*full;
	char	*tmp;
	char	*seg;
	char	**tab;
	int		**line;
	int		i;
	int		y;

	y = -1;
	i = 0;
	fd = open("maps/42.fdf",O_RDONLY);
	while (( 1 == get_next_line(fd, &tmp)))
	{
			if (ft_strchr(tmp, ':'))
				return(-1);
			seg = ft_strjoin_free(tmp, ":", 1);
			full = ft_strjoin_free(full, seg, 2);
	}
	tab = ft_strsplit(full, ':');
//	ft_puttab(tab);
	if(!(line = malloc(sizeof(int *) * (ft_tablen(tab) + 1))))
		return(-1);
	while(++y < ft_tablen(tab))
		line[y] = int_line(tab[y]);
	line[y + 1] = NULL;
//	ft_putnbr(line[0][0]);
	while(++i <= line[0][0])
		ft_putnbr(line[i][0]);
	return(0);
	
	
}
