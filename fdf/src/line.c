#include "../include/fdf.h"

static void		final_line_1(t_coord a, t_env *e, t_line *l)
{
	int			x;
	int			y;
	int			d;
	int			ai;
	int			bi;

	x = -1;
	y = 0;
	d = (2 * l->dy) - l->dx;
	ai = 2 * (l->dy - l->dx);
	bi = 2 * l->dy;
	while (++x <= l->dx)
	{
		put_pixel_to_img(e, a.x + x, a.y + (y * l->coef_sign), l->color);
		if (d >= 0)
		{
			y++;
			d += ai;
		}
		else
			d += bi;
	}
}

static void		final_line_2(t_coord a, t_env *e, t_line *l)
{
	int			x;
	int			y;
	int			d;
	int			ai;
	int			bi;

	y = -1;
	x = 0;
	d = (2 * l->dx) - l->dy;
	ai = 2 * (l->dx - l->dy);
	bi = 2 * l->dx;
	while (++y <= l->dy)
	{
		put_pixel_to_img(e, a.x + (x * l->coef_sign), a.y + y, l->color);
		if (d >= 0)
		{
			x++;
			d += ai;
		}
		else
			d += bi;
	}
}

static void		line_1(t_coord a, t_coord b, t_env *e, int color)
{
	t_line		l;

	l.color = color;
	l.dx = ABS(b.x - a.x);
	l.dy = ABS(b.y - a.y);
	if (l.dy)
	{
		l.coef_sign = ((a.y - b.y) < 0) ? 1 : -1;
		final_line_1(a, e, &l);
	}
	else
		line_hori(e, a, b, color);
}

static void		line_2(t_coord a, t_coord b, t_env *e, int color)
{
	t_line		l;

	l.color = color;
	l.dx = ABS(b.x - a.x);
	l.dy = ABS(b.y - a.y);
	if (l.dx)
	{
		l.coef_sign = ((a.x - b.x) < 0) ? 1 : -1;
		final_line_2(a, e, &l);
	}
	else
		line_vert(e, a, b, color);
}

void			print_line(t_coord a, t_coord b, t_env *e, int color)
{
	if (ABS(b.x - a.x) >= ABS(b.y - a.y))
	{
		if (a.x <= b.x)
			line_1(a, b, e, color);
		else
			line_1(b, a, e, color);
	}
	else
	{
		if (a.y <= b.y)
			line_2(a, b, e, color);
		else
			line_2(b, a, e, color);
	}
}
