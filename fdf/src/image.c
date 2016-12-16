#include "../include/fdf.h"

void				put_pixel_to_img(t_env *e, int x, int y, int color)
{
	int				begin;

	begin = (x * e->bpp / 8) + (y * e->size_line);
	if ((y >= 0 && y <= WIN_Y) && (x >= 0 && x <= WIN_X))
		ft_memcpy(e->addr + begin, &color, (e->bpp / 8));
}

void				put_img_to_win(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
