#include "../include/fdf.h"

void		line_hori(t_env *e, t_coord a, t_coord b, int color)
{
	int		x_start;
	int		x_end;

	if (a.x <= b.x)
	{
		x_start = a.x;
		x_end = b.x;
	}
	else
	{
		x_start = b.x;
		x_end = a.x;
	}
	while (x_start <= x_end)
	{
		put_pixel_to_img(e, x_start, a.y, color);
		x_start++;
	}
}

void		line_vert(t_env *e, t_coord a, t_coord b, int color)
{
	int		y_start;
	int		y_end;

	if (a.y <= b.y)
	{
		y_start = a.y;
		y_end = b.y;
	}
	else
	{
		y_start = b.y;
		y_end = a.y;
	}
	while (y_start <= y_end)
	{
		put_pixel_to_img(e, a.x, y_start, color);
		y_start++;
	}
}
