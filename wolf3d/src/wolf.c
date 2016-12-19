#include "../include/wolf.h"

void	wolf(t_env *e)
{
	int 	x;
	clock_t begin;
	clock_t end;

	begin = clock();
	x = -1;
	while (++x < WIN_X)
	{
		calc_view_ray(e, x);
		e->d = dda_algorithm(e);
		draw_column(e, x);
	}
	end = clock();
	e->frame_time = (double)(end - begin) / CLOCKS_PER_SEC;
	e->fps = (int)(1.0 / e->frame_time);
	printf("fps: %d\n", e->fps);//CARE
	put_img_to_win(e);
}

void	calc_view_ray(t_env *e, int x)
{
	e->camera_x = 2.0 * x / (1.0 * WIN_X) - 1;
	e->ray_pos->x = e->pos->x;
	e->ray_pos->y = e->pos->y;
	e->ray_dir->x = e->dir->x + e->plane->x * e->camera_x;
	e->ray_dir->y = e->dir->y + e->plane->y * e->camera_x;
}

void	init_dda(t_env *e)
{
	e->d->map_x = (int)(e->ray_pos->x);
	e->d->map_y = (int)(e->ray_pos->y);
	e->d->hit = 0;
	e->d->delta_distx = sqrt(1 + (e->ray_dir->y * e->ray_dir->y) / (e->ray_dir->x * e->ray_dir->x));
	e->d->delta_disty = sqrt(1 + (e->ray_dir->x * e->ray_dir->x) / (e->ray_dir->y * e->ray_dir->y));
	if (e->ray_dir->x < 0)
	{
		e->d->step_x = -1;
		e->d->ini_distx = (e->ray_pos->x - e->d->map_x) * e->d->delta_distx;
	}
	else
	{
		e->d->step_x = 1;
		e->d->ini_distx = (1 + e->d->map_x - e->ray_pos->x) * e->d->delta_distx;
	}
	if (e->ray_dir->y < 0)
	{
		e->d->step_y = -1;
		e->d->ini_disty = (e->ray_pos->y - e->d->map_y) * e->d->delta_disty;
	}
	else
	{
		e->d->step_y = 1;
		e->d->ini_disty = (1 + e->d->map_y - e->ray_pos->y) * e->d->delta_disty;
	}
}

t_dda	*dda_algorithm(t_env *e)
{
	init_dda(e);
	while (e->d->hit == 0)
	{
		if (e->d->ini_distx < e->d->ini_disty)
		{
			e->d->ini_distx += e->d->delta_distx;
			e->d->map_x += e->d->step_x;
			e->d->side = 0;
		}
		else
		{
			e->d->ini_disty += e->d->delta_disty;
			e->d->map_y += e->d->step_y;
			e->d->side = 1;
		}
		if (e->map[e->d->map_x][e->d->map_y] > 0)
			e->d->hit = 1;
	}
	e->wall_height = calc_wall(e);
	return (e->d);
}

int		calc_wall(t_env *e)
{
	if (e->d->side == 0)
		e->d->orth_proj_dist = fabs((e->d->map_x - e->ray_pos->x + (1 - e->d->step_x) / 2) / e->ray_dir->x);
	else
		e->d->orth_proj_dist = fabs((e->d->map_y - e->ray_pos->y + (1 - e->d->step_y) / 2) / e->ray_dir->y);
	return (abs((int)(e->cube / e->d->orth_proj_dist)));
}