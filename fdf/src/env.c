#include "../include/fdf.h"

void		leave(t_env *e)
{
	free_map(e, e->para_map);
	free_map(e, e->iso_map);
	mlx_destroy_image(e->mlx, e->img);
	mlx_destroy_window(e->mlx, e->win);
	exit(0);
}

static int	init_fdf_maps(t_env *e)
{
	int y;

	if ((e->para_map = malloc(sizeof(t_coord *) * e->map_y)) == NULL)
		return (-1);
	y = -1;
	while (++y < e->map_y)
	{
		if ((e->para_map[y] = malloc(sizeof(t_coord) * e->map_x)) == NULL)
			return (-1);
	}
	if ((e->iso_map = malloc(sizeof(t_coord *) * e->map_y)) == NULL)
		return (-1);
	y = -1;
	while (++y < e->map_y)
	{
		if ((e->iso_map[y] = malloc(sizeof(t_coord) * e->map_x)) == NULL)
			return (-1);
	}
	return (0);
}

static void	init_struct(t_env *e, t_map *m)
{
	e->pers = 0;
	e->maximize = 1;
	e->para_const = 0.8;
	e->para_const_sq = 1;
	e->iso_c1 = 0.8;
	e->iso_c2 = 0.8;
	e->x_shift = 0;
	e->y_shift = 0;
	e->map = m->map;
	e->map_x = m->width;
	e->map_y = m->height;
}

int			init_env(t_env *e, t_map *m)
{
	if (WIN_X > 1800 || WIN_Y > 1200)
	{
		ft_putendl("MAX_WIDTH:1800\nMAX_HEIGHT:1200");
		return (-1);
	}
	if ((e->mlx = mlx_init()) == NULL)
		return (-1);
	if ((e->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "FDF")) == NULL)
		return (-1);
	if ((e->img = mlx_new_image(e->mlx, WIN_X, WIN_Y)) == NULL)
		return (-1);
	if ((e->addr = mlx_get_data_addr(e->img, &(e->bpp), &(e->size_line),
		&(e->endian))) == NULL)
		return (-1);
	init_struct(e, m);
	free(m->map_name);
	if (init_fdf_maps(e) == -1)
		return (-1);
	return (0);
}
