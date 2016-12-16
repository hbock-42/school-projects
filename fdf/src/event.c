#include "../include/fdf.h"

static void	move_map(t_env *e, int key)
{
	if (key == 124)
		map_shift(e, 0);
	else if (key == 123)
		map_shift(e, 1);
	else if (key == 126)
		map_shift(e, 2);
	else if (key == 125)
		map_shift(e, 3);
}

static int	key_hook(unsigned int key, t_env *e)
{
	if (key == 53)
		leave(e);
	if (key == 82)
		change_pers(e);
	if (key == 69)
		depth_change(e, 0);
	if (key == 78)
		depth_change(e, 1);
	if (key == 89)
		const_modif(e, 0);
	if (key == 91)
		const_modif(e, 1);
	if (key >= 123 && key <= 126)
		move_map(e, key);
	if (key == 83)
		on_screen_ctrl(e);
	return (0);
}

static int	expose_hook(t_env *e)
{
	put_img_to_win(e);
	return (0);
}

void		hook_event(t_env *e)
{
	mlx_key_hook(e->win, &key_hook, e);
	mlx_expose_hook(e->win, &expose_hook, e);
	mlx_loop(e->mlx);
}
