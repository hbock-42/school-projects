/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_parse_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hugo <Hugo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 11:36:25 by hbock             #+#    #+#             */
/*   Updated: 2016/11/15 01:30:24 by Hugo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

void		fill_plane_0(t_obj *obj, t_parse *p, t_vec point, t_vec normal)
{
	obj->plane[p->id_pl].point = point;
	obj->plane[p->id_pl].a = normal.x;
	obj->plane[p->id_pl].b = normal.y;
	obj->plane[p->id_pl].c = normal.z;
}

int			parse_plane_1(t_obj *obj, char *line, t_parse *p)
{
	t_vec	trans;
	char	*s;
	int		error;

	trans = vec_new(0, 0, 0);
	error = 1;
	if ((s = ft_strstr(line, "d{")) != NULL)
	{
		s += 2;
		obj->plane[p->id_pl].d = (double)ft_atoi(s);
	}
	if ((s = ft_strstr(line, "trans")) != NULL)
		error = (error == 1) ? fill_vector(s, "trans", &trans) : -1;
	if (error == -1)
		return (m_error("scene file formated wrong -> plane"));
	obj->plane[p->id_pl].point = vec_add(obj->plane[p->id_pl].point, trans);
	p->id_pl++;
	return (1);
}

int			parse_cylinder(t_obj *obj, char *line, t_parse *p)
{
	t_vec	trans;
	t_vec	rot;
	char	*s;
	int		error;

	trans = vec_new(0, 0, 0);
	rot = vec_new(0, 0, 0);
	error = 1;
	if ((s = ft_strstr(line, "trans")) != NULL)
		error = (error == 1) ? fill_vector(s, "trans", &trans) : -1;
	if ((s = ft_strstr(line, "rotxyz")) != NULL)
		error = (error == 1) ? fill_vector(s, "rotxyz", &rot) : -1;
	if ((s = ft_strstr(line, "radius")) != NULL)
	{
		s += 7;
		obj->cylind[p->id_cy].r = (double)ft_atoi(s);
	}
	if (error == -1)
		return (m_error("scene file formated wrong -> cylinder"));
	obj->cylind[p->id_cy].o = trans;
	obj->cylind[p->id_cy].rotx = rot.x;
	obj->cylind[p->id_cy].roty = rot.y;
	obj->cylind[p->id_cy].rotz = rot.z;
	p->id_cy++;
	return (1);
}

static void	fill_cone(t_obj *obj, t_parse *p, t_vec trans, t_vec rot)
{
	obj->cone[p->id_co].o = trans;
	obj->cone[p->id_co].rotx = rot.x;
	obj->cone[p->id_co].roty = rot.y;
	obj->cone[p->id_co].rotz = rot.z;
	obj->cone[p->id_co].tan_alpha =
			tan(obj->cone[p->id_co].alpha * M_PI / 180);
	p->id_co++;
}

int			parse_cone(t_obj *obj, char *line, t_parse *p)
{
	t_vec	trans;
	t_vec	rot;
	char	*s;
	int		error;

	trans = vec_new(0, 0, 0);
	rot = vec_new(0, 0, 0);
	error = 1;
	if ((s = ft_strstr(line, "trans")) != NULL)
		error = (error == 1) ? fill_vector(s, "trans", &trans) : -1;
	if ((s = ft_strstr(line, "rotxyz")) != NULL)
		error = (error == 1) ? fill_vector(s, "rotxyz", &rot) : -1;
	if ((s = ft_strstr(line, "angle")) != NULL)
	{
		s += 6;
		obj->cone[p->id_co].alpha = (double)ft_atoi(s);
	}
	if (error == -1)
		return (m_error("scene file formated wrong -> cone"));
	fill_cone(obj, p, trans, rot);
	return (1);
}
