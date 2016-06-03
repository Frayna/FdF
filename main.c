#include "fdf.h"
int		key(int k, void *tdot)
{
	t_dot	*dot;

	dot = (t_dot *)tdot;
	ft_putnbr(k);
	if (k == ESCAPE)
		exit(3);
	if (k == UP)
		mlx_pixel_put(dot->mlx, dot->win, dot->x, dot->y--, dot->color);
	if (k == DOWN)
		mlx_pixel_put(dot->mlx, dot->win, dot->x, dot->y++, dot->color);
	if (k == LEFT)
		mlx_pixel_put(dot->mlx, dot->win, dot->x--, dot->y, dot->color);
	if (k == RIGHT)
		mlx_pixel_put(dot->mlx, dot->win, dot->x++, dot->y, dot->color);
	return (0);
}

t_dot	*init_dot(void	*mlx, void	*win, int color)
{
	t_dot	*dot;
	if (!(dot = malloc(sizeof(t_dot *))))
		return (NULL);
	dot->x = 0;
	dot->y = 0;
	dot->color = color;
	dot->mlx = mlx;
	dot->win = win;
	dot->next = NULL;
	return(dot);
}



int main(int argc, char **argv)
{
//	static t_dot	*dot;
//	void	*mlx;
//	void	*win;
//	void	*img;
	int		fd;
	char	*line;

	argc++;
	argc--;
	fd = open(argv[1], O_RDONLY);
	while ((0 < get_next_line(fd, &line)))
		ft_putendl(line);
//	mlx = mlx_init();
//	win = mlx_new_window(mlx, 500, 500, "YOLO");
//	if (!(dot = init_dot(mlx, win, 0x00FF0000)))
//		return(-1);
//	img = mlx_new_image(mlx, 500, 500);
//	mlx_pixel_put(mlx, win, 250, 250 , 0x00FFFFFF);
//	mlx_key_hook(win, key, (void *)dot);
//	mlx_loop(mlx);
	return (0);
}
