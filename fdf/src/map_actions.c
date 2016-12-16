#include "../include/fdf.h"

void	free_map(t_env *e, t_coord **map)
{
	int		i;

	i = -1;
	while (++i < e->map_y)
		free(map[i]);
	free(map);
}

void	depth_change(t_env *e, int sign)
{
	reset_window(e);
	if (sign == 0)
		e->maximize++;
	else if (sign == 1)
		e->maximize--;
	if (e->pers == 0)
	{
		iso_fdf(e);
		draw_fdf(e, e->iso_map);
	}
	else if (e->pers == 1)
	{
		parallel_fdf(e);
		draw_fdf(e, e->para_map);
	}
	put_img_to_win(e);
}

void	const_iso(t_env *e, int modif)
{
	if (modif == 0)
	{
		e->iso_c1 -= 0.1;
		e->iso_c2 -= 0.1;
	}
	else if (modif == 1)
	{
		e->iso_c1 += 0.1;
		e->iso_c2 += 0.1;
	}
	if (e->iso_c1 > 2)
		e->iso_c1 = 2;
	if (e->iso_c2 > 2)
		e->iso_c2 = 2;
	if (e->iso_c1 < 0.2)
		e->iso_c1 = 0.2;
	if (e->iso_c2 < 0.2)
		e->iso_c2 = 0.2;
	iso_fdf(e);
	draw_fdf(e, e->iso_map);
	put_img_to_win(e);
}

void	const_modif(t_env *e, int modif)
{
	reset_window(e);
	if (e->pers == 0)
		const_iso(e, modif);
	if (e->pers == 1)
	{
		if (modif == 0)
			e->para_const_sq -= 0.1;
		else if (modif == 1)
			e->para_const_sq += 0.1;
		if (e->para_const_sq > 2)
			e->para_const_sq = 2;
		if (e->para_const_sq < 0.2)
			e->para_const_sq = 0.2;
		parallel_fdf(e);
		draw_fdf(e, e->para_map);
		put_img_to_win(e);
	}
}

void	map_shift(t_env *e, int modif)
{
	reset_window(e);
	if (modif == 0)
		e->x_shift -= 10;
	else if (modif == 1)
		e->x_shift += 10;
	else if (modif == 2)
		e->y_shift += 10;
	else if (modif == 3)
		e->y_shift -= 10;
	if (e->pers == 0)
	{
		iso_fdf(e);
		draw_fdf(e, e->iso_map);
	}
	else if (e->pers == 1)
	{
		parallel_fdf(e);
		draw_fdf(e, e->para_map);
	}
	put_img_to_win(e);
}
