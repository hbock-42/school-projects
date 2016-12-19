#include "../include/wolf.h"

t_env				*init_understruct(t_env *e)
{
	if ((e->pos = malloc(sizeof(t_d_coord))) == NULL)
		return (NULL);
	e->pos->x = POSX_START;
	e->pos->y = POSY_START;
	if ((e->dir = malloc(sizeof(t_d_coord))) == NULL)
		return (NULL);
	e->dir->x = DIRX_START;
	e->dir->y = DIRY_START;
	if ((e->plane = malloc(sizeof(t_d_coord))) == NULL)
		return (NULL);
	e->plane->x = PLANEX_START;
	e->plane->y = PLANEY_START;
	if ((e->ray_pos = malloc(sizeof(t_d_coord))) == NULL)
		return (NULL);
	if ((e->ray_dir = malloc(sizeof(t_d_coord))) == NULL)
		return (NULL);
	if ((e->event = malloc(sizeof(t_event))) == NULL)
		return (NULL);
	e->event[GO_UP] = 0;
	e->event[GO_DOWN] = 0;
	e->event[ROT_RIGHT] = 0;
	e->event[ROT_LEFT] = 0;
	return (e);
}

t_dda				*init_dda_struct(t_env *e)
{
	if ((e->d = malloc(sizeof(t_dda))) == NULL)
		return (NULL);
	return (e->d);
}

t_env				*env_init(t_env *e)
{
	if ((e = malloc(sizeof(t_env))) == NULL)
		return (NULL);
	if ((e->mlx = mlx_init()) == NULL)
		return (NULL);
	if ((e->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "HUGO")) == NULL)
		return (NULL);
	if ((e->img = mlx_new_image(e->mlx, WIN_X, WIN_Y)) == NULL)
		return (NULL);
	if ((e->addr = mlx_get_data_addr(e->img, &e->bpp, &e->size_line,
		&e->endian)) == NULL)
		return (NULL);
	if (init_understruct(e) == NULL)
		return (NULL);
	e->d = NULL;
	if (init_dda_struct(e) == NULL)
		return(NULL);
	e->cube = CUBE;
	e->speed = INI_SPEED;
	e->rot_speed = INI_ROT_SPEED;
	e->frame_time = 60;
	return (e);
}