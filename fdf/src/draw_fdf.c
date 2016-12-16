#include "../include/fdf.h"

static void	draw_fdf_1(t_env *e, t_coord **map)
{
	t_coord a;
	t_coord	b;
	int		i;
	int		j;

	i = -1;
	while (++i < e->map_x)
	{
		j = 0;
		while (++j < e->map_y)
		{
			a.x = map[j - 1][i].x;
			a.y = map[j - 1][i].y;
			b.x = map[j][i].x;
			b.y = map[j][i].y;
			print_line(a, b, e, 0xFF0000);
		}
	}
}

void		draw_fdf(t_env *e, t_coord **map)
{
	t_coord a;
	t_coord	b;
	int		i;
	int		j;

	j = -1;
	while (++j < e->map_y)
	{
		i = 0;
		while (++i < e->map_x)
		{
			a.x = map[j][i - 1].x;
			a.y = map[j][i - 1].y;
			b.x = map[j][i].x;
			b.y = map[j][i].y;
			print_line(a, b, e, 0xFF0000);
		}
	}
	draw_fdf_1(e, map);
}

void		reset_window(t_env *e)
{
	int		i;
	int		j;

	i = -1;
	while (++i < WIN_Y)
	{
		j = -1;
		while (++j < WIN_X)
			put_pixel_to_img(e, j, i, 0X000000);
	}
}

void		change_pers(t_env *e)
{
	reset_window(e);
	if (e->pers == 0)
	{
		parallel_fdf(e);
		draw_fdf(e, e->para_map);
		e->pers = 1;
	}
	else if (e->pers == 1)
	{
		iso_fdf(e);
		draw_fdf(e, e->iso_map);
		e->pers = 0;
	}
	put_img_to_win(e);
}
