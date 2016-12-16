/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raylaunch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hugo <Hugo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 12:18:53 by hbock             #+#    #+#             */
/*   Updated: 2016/11/15 14:00:09 by Hugo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

void		raylaunch(t_env *e, t_obj *obj)
{
	int		x;
	int		y;

	e->x_indent = VIEW_PLANE_WIDTH / WIN_X;
	e->y_indent = VIEW_PLANE_HEIGHT / WIN_Y;
	y = -1;
	while (++y < WIN_Y)
	{
		x = -1;
		while (++x < WIN_X)
		{
			e->pix_ray = vec_add(e->view_plane_ori,
				vec_sub(vec_numb(e->right_vec, e->x_indent * x),
					vec_numb(e->up_vec, e->y_indent * y)));
			e->pix_ray = vec_sub(e->pix_ray, e->eye_pos);
			e->pix_ray = vec_normalize(e->pix_ray);
			obj->t = INFI;
			obj->type_fix = -1;
			obj->type = -1;
			calc_inter(e, obj, 0);
			if (obj->t < INFI)
				shadow(e, obj, x, y);
		}
	}
	draw(e);
}

static void	init_inter_ray(t_env *e, t_obj *obj, int shadow, t_ray *ray)
{
	if (shadow)
	{
		ray->o = obj->hitpoint;
		ray->dir = obj->neg_light_dir;
	}
	else
	{
		ray->o = e->eye_pos;
		ray->dir = e->pix_ray;
	}
}

static void	call_other_inter_funct(t_obj *obj, t_ray ray, int shadow)
{
	int		i;

	i = -1;
	while (++i < obj->cylind_max)
	{
		if (shadow && obj->type_fix == CYLINDER && obj->id == i)
			continue ;
		inter_cylinder(i, obj, ray);
	}
	i = -1;
	while (++i < obj->cone_max)
	{
		if (shadow && obj->type_fix == CONE && obj->id == i)
			continue ;
		inter_cone(i, obj, ray);
	}
}

void		calc_inter(t_env *e, t_obj *obj, int shadow)
{
	int		i;
	t_ray	ray;

	init_inter_ray(e, obj, shadow, &ray);
	i = -1;
	while (++i < obj->sphere_max)
	{
		if (shadow && obj->type_fix == SPHERE && obj->id == i)
			continue ;
		inter_sphere(i, obj, ray);
	}
	i = -1;
	while (++i < obj->plane_max)
	{
		if (shadow && obj->type_fix == PLANE && obj->id == i)
			continue ;
		inter_plane(i, obj, ray);
	}
	call_other_inter_funct(obj, ray, shadow);
}
