#include "../include/wolf.h"

void		rotate_player(t_env *e, int modif)
{
	double old_dir_x;
	double old_plane_x;

	if (modif == 1)
    {
    	old_dir_x = e->dir->x;
		old_plane_x = e->plane->x;
    	e->dir->x = e->dir->x * cos(-e->rot_speed) - e->dir->y * sin(-e->rot_speed);
    	e->dir->y = old_dir_x * sin(-e->rot_speed) + e->dir->y * cos(-e->rot_speed);
    	e->plane->x = e->plane->x * cos(-e->rot_speed) - e->plane->y * sin(-e->rot_speed);
    	e->plane->y = old_plane_x * sin(-e->rot_speed) + e->plane->y * cos(-e->rot_speed);
    }
    if (modif == 0)
    {
    	old_dir_x = e->dir->x;
		old_plane_x = e->plane->x;
		e->dir->x = e->dir->x * cos(e->rot_speed) - e->dir->y * sin(e->rot_speed);
		e->dir->y = old_dir_x * sin(e->rot_speed) + e->dir->y * cos(e->rot_speed);
		e->plane->x = e->plane->x * cos(e->rot_speed) - e->plane->y * sin(e->rot_speed);
		e->plane->y = old_plane_x * sin(e->rot_speed) + e->plane->y * cos(e->rot_speed);
    }
}

void		p_move(t_env *e, int modif)
{
	reset_image(e);
	if (modif == 3)
    {
    	if(e->map[(int)(e->pos->x + e->dir->x * e->speed)][(int)(e->pos->y)] == 0)
    		e->pos->x += e->dir->x * e->speed;
    	if(e->map[(int)(e->pos->x)][(int)(e->pos->y + e->dir->y * e->speed)] == 0)
    		e->pos->y += e->dir->y * e->speed;
    }
    if (modif == 2)
    {
    	if(e->map[(int)(e->pos->x - e->dir->x * e->speed)][(int)(e->pos->y)] == 0)
    		e->pos->x -= e->dir->x * e->speed;
    	if(e->map[(int)(e->pos->x)][(int)(e->pos->y - e->dir->y * e->speed)] == 0)
    		e->pos->y -= e->dir->y * e->speed;
    }
    if (modif == 0 || modif == 1)
    	rotate_player(e, modif);
    wolf(e);
	put_img_to_win(e);
}
