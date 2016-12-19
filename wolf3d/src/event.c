#include "../include/wolf.h"

int			expose_hook(t_env *e)
{
	put_img_to_win(e);
	return (0);
}

void		player_move(t_env *e, int key)
{
	if (key == 123)
		p_move(e, 0);
	else if (key == 124)
		p_move(e, 1);
	else if (key == 125)
		p_move(e, 2);
	else if (key == 126)
		p_move(e, 3);
}

static int			key_press(unsigned int key, t_env *e)
{
	if (key == 53)
		exit(0);
	if (key == 123)
		e->event[GO_UP] = 1;
	if (key == 124)
		e->event[GO_DOWN] = 1;
	if (key == 125)
		e->event[ROT_RIGHT] = 1;
	if (key == 126)
		e->event[ROT_LEFT] = 1;
	return (0);
}

static int			key_release(unsigned int key, t_env *e)
{
	if (key == 123)
		e->event[GO_UP] = 0;
	if (key == 124)
		e->event[GO_DOWN] = 0;
	if (key == 125)
		e->event[ROT_RIGHT] = 0;
	if (key == 126)
		e->event[ROT_LEFT] = 0;
	return (0);
}

static int			loop(t_env *e)
{
	if (e->event[GO_UP])
		player_move(e, 123);
	if (e->event[GO_DOWN])
		player_move(e, 124);
	if (e->event[ROT_RIGHT])
		player_move(e, 125);
	if (e->event[ROT_LEFT])
		player_move(e, 126);
	return (0);
}

void		hook_event(t_env *e)
{
	mlx_expose_hook(e->win, &expose_hook, e);
	mlx_hook(e->win, 2, 1, &key_press, e);
	mlx_hook(e->win, 3, 2, &key_release, e);
	mlx_loop_hook(e->mlx, &loop, e);
	mlx_loop(e->mlx);
}