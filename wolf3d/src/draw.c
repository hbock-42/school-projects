#include "../include/wolf.h"

void				draw_column(t_env *e, int x)
{
	int				w_start;
	int				w_end;
	int				color;

	w_start = (WIN_Y / 2) - (e->wall_height / 2) - 1;
	w_end = (WIN_Y / 2) + (e->wall_height / 2);
	color = calc_color(e);
	if (e->d->orth_proj_dist >= 1)
		color = calc_shadow_color(color, e->d->orth_proj_dist / 3);
	if (w_start < 0)
		w_start = -1;
	if (w_end >= WIN_Y)
		w_end = WIN_Y - 1;
	while (++w_start <= w_end)
		put_pixel_to_img(e, x, w_start, color);
}
