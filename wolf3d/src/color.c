#include "../include/wolf.h"

int					calc_color(t_env *e)
{
	if (e->d->side == 0)
	{
		if (e->d->step_x > 0)
			return (COLOR1);
		else
			return (COLOR2);
	}
	else
	{
		if (e->d->step_y > 0)
			return (COLOR3);
	}
	return (COLOR4);
}

int					ask_shadow(int color, double dist)
{
	int				r;
	int				g;
	int				b;
	int				nr;
	int				ng;
	int				nb;

	r = (color >> 16) & 0xff;
	g = (color >> 8) & 0xff;
	b = color & 0xff;
	nr = r / dist;
	ng = g / dist;
	nb = b / dist;
	if (nr > r || ng > g || nb > b)
		return (1);
	return (0);
}

int					calc_shadow_color(int color, double dist)
{
	int				r;
	int				g;
	int				b;
	int				nr;
	int				ng;
	int				nb;

	dist = dist * (dist / 3);
	if (ask_shadow(color, dist))
		return (color);
	r = (color >> 16) & 0xff;
	g = (color >> 8) & 0xff;
	b = color & 0xff;
	nr = r / dist;
	ng = g / dist;
	nb = b / dist;

	return ((nr << 16) + (ng << 8) + nb);
}