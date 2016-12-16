/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_parse_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hugo <Hugo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 11:36:25 by hbock             #+#    #+#             */
/*   Updated: 2016/11/15 01:30:12 by Hugo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

int			fill_vector(char *s, char *needle, t_vec *v)
{
	int		tmp;

	s += ft_strlen(needle) + 1;
	tmp = ft_atoi(s);
	v->x += (double)tmp;
	s += int_lenght(tmp) + 1;
	tmp = ft_atoi(s);
	v->y += (double)tmp;
	s += int_lenght(tmp) + 1;
	tmp = ft_atoi(s);
	v->z += (double)tmp;
	s += int_lenght(tmp);
	if (s[0] != '}')
		return (-1);
	return (1);
}

static void	fill_sphere(t_obj *obj, t_parse *p, t_vec c, t_vec rot)
{
	if (rot.x != 0 || rot.y != 0 || rot.z != 0)
		c = rot_xyz(c, rot.x, rot.y, rot.z);
	obj->sphere[p->id_sp].c = c;
	p->id_sp++;
}

int			parse_sphere(t_obj *obj, char *line, t_parse *p)
{
	t_vec	c;
	t_vec	rot;
	char	*s;
	int		error;

	c = vec_new(0, 0, 0);
	rot = vec_new(0, 0, 0);
	if ((s = ft_strstr(line, "center")) != NULL)
		error = fill_vector(s, "center", &c);
	if ((s = ft_strstr(line, "radius")) != NULL)
	{
		s += 7;
		obj->sphere[p->id_sp].r = (double)ft_atoi(s);
	}
	if ((s = ft_strstr(line, "trans")) != NULL)
		error = (error == 1) ? fill_vector(s, "trans", &c) : -1;
	if ((s = ft_strstr(line, "rotxyz")) != NULL)
		error = (error == 1) ? fill_vector(s, "rotxyz", &rot) : -1;
	if (error == -1)
		return (m_error("scene file formated wrong -> sphere"));
	fill_sphere(obj, p, c, rot);
	return (1);
}

int			parse_light(t_obj *obj, char *line, t_parse *p)
{
	t_vec	o;
	char	*s;
	int		error;

	o = vec_new(0, 0, 0);
	error = 0;
	if ((s = ft_strstr(line, "pos")) != NULL)
		error = fill_vector(s, "pos", &o);
	if (error == -1)
		return (m_error("scene file formated wrong -> light"));
	obj->light[p->id_li].o = o;
	p->id_li++;
	return (1);
}

int			parse_plane(t_obj *obj, char *line, t_parse *p)
{
	t_vec	point;
	t_vec	normal;
	t_vec	rot;
	char	*s;
	int		error;

	point = vec_new(0, 0, 0);
	rot = vec_new(0, 0, 0);
	if ((s = ft_strstr(line, "point")) != NULL)
		error = fill_vector(s, "point", &point);
	if ((s = ft_strstr(line, "normal")) != NULL)
		error = fill_vector(s, "normal", &normal);
	if ((s = ft_strstr(line, "rotxyz")) != NULL)
		error = (error == 1) ? fill_vector(s, "rotxyz", &rot) : -1;
	if (error == -1)
		return (m_error("scene file formated wrong -> plane"));
	if (rot.x != 0 || rot.y != 0 || rot.z != 0)
		normal = rot_xyz(normal, rot.x, rot.y, rot.z);
	fill_plane_0(obj, p, point, normal);
	if (parse_plane_1(obj, line, p) == -1)
		return (-1);
	return (1);
}
