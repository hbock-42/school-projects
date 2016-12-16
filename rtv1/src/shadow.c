/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hugo <Hugo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 16:20:49 by hbock             #+#    #+#             */
/*   Updated: 2016/11/15 13:59:04 by Hugo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

static t_vec	normal_cone(t_obj *obj)
{
	t_vec	hitp;
	t_vec	normal;
	t_vec	tmp;
	double	hypo_lenght;

	hitp = vec_add(obj->cone[obj->id].eye_pos,
		vec_numb(obj->cone[obj->id].eye_dir, obj->t));
	hypo_lenght = vec_length(hitp) / cos(obj->cone[obj->id].alpha * M_PI / 90);
	tmp = (hitp.y >= 0) ? vec_new(0, hypo_lenght, 0) :
		vec_new(0, -hypo_lenght, 0);
	normal = vec_normalize(vec_sub(hitp, tmp));
	normal = rot_xyz(normal, obj->cone[obj->id].rotx, obj->cone[obj->id].roty,
		obj->cone[obj->id].rotz);
	return (normal);
}

static t_vec	normal_plane(t_env *e, t_obj *obj)
{
	t_vec	normal;

	normal = vec_normalize(vec_new(obj->plane[obj->id].a,
			obj->plane[obj->id].b, obj->plane[obj->id].c));
	if (vec_dot(normal, vec_normalize(e->pix_ray)) > 0)
	{
		normal.x = -normal.x;
		normal.y = -normal.y;
		normal.z = -normal.z;
	}
	return (normal);
}

static t_vec	calc_normal(t_env *e, t_obj *obj, int objtype)
{
	t_vec	tmphitp;
	t_vec	normal;

	if (objtype == SPHERE)
		return (vec_normalize(vec_sub(obj->hitpoint, obj->sphere[obj->id].c)));
	if (objtype == PLANE)
		return (normal_plane(e, obj));
	if (objtype == CYLINDER)
	{
		tmphitp = vec_add(obj->cylind[obj->id].eye_pos,
			vec_numb(obj->cylind[obj->id].eye_dir, obj->t));
		normal = vec_normalize(vec_sub(tmphitp, vec_new(0, tmphitp.y, 0)));
		normal = rot_x(obj->cylind[obj->id].rotx, normal);
		normal = rot_y(obj->cylind[obj->id].roty, normal);
		normal = rot_z(obj->cylind[obj->id].rotz, normal);
		return (normal);
	}
	if (objtype == CONE)
		return (normal_cone(obj));
	return (vec_new(1, 2, 3));
}

static t_vec	normal_all(t_env *e, t_obj *obj)
{
	if (obj->type_fix == SPHERE)
		return (calc_normal(e, obj, SPHERE));
	else if (obj->type_fix == PLANE)
		return (calc_normal(e, obj, PLANE));
	else if (obj->type_fix == CYLINDER)
		return (calc_normal(e, obj, CYLINDER));
	else
		return (calc_normal(e, obj, CONE));
}

void			shadow(t_env *e, t_obj *obj, int x, int y)
{
	t_vec	normal;
	double	dist;
	int		i;

	obj->type_fix = obj->type;
	obj->hitpoint = vec_add(e->eye_pos, vec_numb(e->pix_ray, obj->t));
	normal = normal_all(e, obj);
	obj->lambert = 0;
	obj->phong = 0;
	i = -1;
	while (++i < obj->light_max)
	{
		obj->light_dir = vec_normalize(vec_sub(obj->hitpoint, obj->light[i].o));
		if ((obj->dot = vec_dot(obj->light_dir, normal)) >= 0)
			continue ;
		dist = vec_length(vec_sub(obj->hitpoint, obj->light[i].o));
		obj->neg_light_dir =
			vec_normalize(vec_sub(obj->light[i].o, obj->hitpoint));
		obj->t = INFI;
		calc_inter(e, obj, 1);
		obj->phong += (obj->t > dist) ? phong(normal, obj->neg_light_dir,
			e->pix_ray, obj->type_fix) : 0;
		obj->lambert += (obj->t > dist) ? -obj->dot : 0;
	}
	calc_color(e, obj, x, y);
}
