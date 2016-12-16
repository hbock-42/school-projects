/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hugo <Hugo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 11:37:21 by hbock             #+#    #+#             */
/*   Updated: 2016/11/15 14:28:11 by Hugo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

static void		solve_quad(t_obj *obj, int id, t_quad q, int type)
{
	q.delta = (q.b * q.b) - (4 * q.a * q.c);
	if (q.delta >= 0)
	{
		q.t1 = (-q.b + sqrt(q.delta)) / (2 * q.a);
		q.t2 = (-q.b - sqrt(q.delta)) / (2 * q.a);
		if (q.t1 < EPSILONE)
			q.t1 = INFI;
		if (q.t2 < EPSILONE)
			q.t2 = INFI;
		q.t1 = (q.t1 < q.t2) ? q.t1 : q.t2;
		if (q.t1 < obj->t)
		{
			obj->t = q.t1;
			obj->id = id;
			obj->type = type;
		}
	}
}

void			inter_sphere(int id, t_obj *obj, t_ray ray)
{
	t_quad		q;

	q.a = ray.dir.x * ray.dir.x + ray.dir.y * ray.dir.y + ray.dir.z *
		ray.dir.z;
	q.b = 2 * (ray.dir.x * (ray.o.x - obj->sphere[id].c.x) + ray.dir.y *
		(ray.o.y - obj->sphere[id].c.y) + ray.dir.z *
		(ray.o.z - obj->sphere[id].c.z));
	q.c = ((ray.o.x - obj->sphere[id].c.x) * (ray.o.x - obj->sphere[id].c.x)
		+ (ray.o.y - obj->sphere[id].c.y) * (ray.o.y - obj->sphere[id].c.y) +
		(ray.o.z - obj->sphere[id].c.z) * (ray.o.z - obj->sphere[id].c.z)) -
		obj->sphere[id].r * obj->sphere[id].r;
	solve_quad(obj, id, q, SPHERE);
}

void			inter_plane(int id, t_obj *obj, t_ray ray)
{
	double	top_term;
	double	bot_term;
	double	t;

	top_term = -(obj->plane[id].a * (ray.o.x - obj->plane[id].point.x) +
		obj->plane[id].b * (ray.o.y - obj->plane[id].point.y) +
		obj->plane[id].c * (ray.o.z - obj->plane[id].point.z) +
		obj->plane[id].d);
	bot_term = obj->plane[id].a * ray.dir.x + obj->plane[id].b * ray.dir.y +
		obj->plane[id].c * ray.dir.z;
	if (bot_term != 0)
	{
		t = top_term / bot_term;
		if (t < EPSILONE)
			t = INFI;
		if (t > 0 && t < obj->t)
		{
			obj->t = t;
			obj->id = id;
			obj->type = PLANE;
		}
	}
}

void			inter_cylinder(int id, t_obj *obj, t_ray ray)
{
	t_quad		q;

	obj->cylind[id].eye_pos = vec_sub(ray.o, obj->cylind[id].o);
	obj->cylind[id].eye_pos = rot_xyz(obj->cylind[id].eye_pos,
		-obj->cylind[id].rotx, -obj->cylind[id].roty, -obj->cylind[id].rotz);
	obj->cylind[id].eye_dir = rot_xyz(ray.dir, -obj->cylind[id].rotx,
		-obj->cylind[id].roty, -obj->cylind[id].rotz);
	q.a = obj->cylind[id].eye_dir.x * obj->cylind[id].eye_dir.x +
		obj->cylind[id].eye_dir.z * obj->cylind[id].eye_dir.z;
	q.b = 2 * obj->cylind[id].eye_dir.x * obj->cylind[id].eye_pos.x + 2 *
		obj->cylind[id].eye_dir.z * obj->cylind[id].eye_pos.z;
	q.c = obj->cylind[id].eye_pos.x * obj->cylind[id].eye_pos.x +
		obj->cylind[id].eye_pos.z * obj->cylind[id].eye_pos.z -
		obj->cylind[id].r * obj->cylind[id].r;
	solve_quad(obj, id, q, CYLINDER);
}

void			inter_cone(int id, t_obj *obj, t_ray ray)
{
	t_quad		q;

	obj->cone[id].eye_pos = vec_sub(ray.o, obj->cone[id].o);
	obj->cone[id].eye_pos = rot_xyz(obj->cone[id].eye_pos, -obj->cone[id].rotx,
		-obj->cone[id].roty, -obj->cone[id].rotz);
	obj->cone[id].eye_dir = rot_xyz(ray.dir, -obj->cone[id].rotx,
		-obj->cone[id].roty, -obj->cone[id].rotz);
	q.a = obj->cone[id].eye_dir.x * obj->cone[id].eye_dir.x +
		obj->cone[id].eye_dir.z * obj->cone[id].eye_dir.z -
		(obj->cone[id].tan_alpha * obj->cone[id].tan_alpha *
		obj->cone[id].eye_dir.y * obj->cone[id].eye_dir.y);
	q.b = 2 * (obj->cone[id].eye_pos.x * obj->cone[id].eye_dir.x +
		obj->cone[id].eye_pos.z * obj->cone[id].eye_dir.z -
		(obj->cone[id].tan_alpha * obj->cone[id].tan_alpha *
		obj->cone[id].eye_pos.y * obj->cone[id].eye_dir.y));
	q.c = obj->cone[id].eye_pos.x * obj->cone[id].eye_pos.x +
		obj->cone[id].eye_pos.z * obj->cone[id].eye_pos.z -
		(obj->cone[id].tan_alpha * obj->cone[id].tan_alpha *
		obj->cone[id].eye_pos.y * obj->cone[id].eye_pos.y);
	solve_quad(obj, id, q, CONE);
}
