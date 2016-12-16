#include "../include/fdf.h"

void		parallel_fdf(t_env *e)
{
	int		x;
	int		y;
	int		sq_size;
	int		x_start;
	int		y_start;

	sq_size = MIN((WIN_X / (e->map_x * 1.2)), (WIN_Y / (e->map_y * 1.2)));
	sq_size = (sq_size < 2) ? 2 : sq_size;
	x_start = e->x_shift + (WIN_X - (sq_size * e->map_x)) / 2;
	y_start = e->y_shift + (WIN_Y - (sq_size * e->map_y)) / 2;
	y = -1;
	while (++y < e->map_y)
	{
		x = -1;
		while (++x < e->map_x)
		{
			e->para_map[y][x].x = x_start + (x * sq_size * e->para_const_sq) +
			(e->para_const * e->map[y][x] * (-e->maximize));
			e->para_map[y][x].y = y_start + (y * sq_size * e->para_const_sq) +
			(e->para_const / 2 * e->map[y][x] * (-e->maximize));
		}
	}
}

void		iso_fdf(t_env *e)
{
	int		x;
	int		y;
	int		sq_size;
	int		x_start;
	int		y_start;

	sq_size = MIN((WIN_X / (e->map_x * 1.2)), (WIN_Y / (e->map_y * 1.2)));
	sq_size = (sq_size < 2) ? 2 : sq_size;
	x_start = e->x_shift + (WIN_X - ((e->iso_c1 * e->map_x * sq_size) -
		(e->iso_c2 * e->map_y * sq_size))) / 2;
	y_start = e->y_shift + (WIN_Y - ((e->iso_c1 / 2 * e->map_x * sq_size) +
		(e->iso_c2 / 2 * e->map_y * sq_size))) / 2;
	y = -1;
	while (++y < e->map_y)
	{
		x = -1;
		while (++x < e->map_x)
		{
			e->iso_map[y][x].x = x_start + (e->iso_c1 * x * sq_size) -
			(e->iso_c2 * y * sq_size);
			e->iso_map[y][x].y = y_start + (e->iso_c1 / 2 * x * sq_size) +
			(e->iso_c2 / 2 * y * sq_size) - (e->map[y][x] * e->maximize);
		}
	}
}
