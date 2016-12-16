/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_scene_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hugo <Hugo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 11:36:25 by hbock             #+#    #+#             */
/*   Updated: 2016/11/15 13:44:39 by Hugo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

int			check_name(char *name)
{
	int		len;

	len = ft_strlen(name);
	len -= 3;
	if (ft_strcmp(&(name[len]), ".sc") != 0)
		return (m_error("Wrong scene file format"));
	return (0);
}

static int	allocate_light(t_obj *obj)
{
	if (obj->light_max)
	{
		if ((obj->light = malloc(sizeof(t_light) * obj->light_max)) == NULL)
			return (-1);
	}
	return (0);
}

int			allocate_obj(t_obj *obj, int fd)
{
	close(fd);
	if (obj->sphere_max)
	{
		if ((obj->sphere = malloc(sizeof(t_sphere) * obj->sphere_max)) == NULL)
			return (-1);
	}
	if (obj->plane_max)
	{
		if ((obj->plane = malloc(sizeof(t_plane) * obj->plane_max)) == NULL)
			return (-1);
	}
	if (obj->cylind_max)
	{
		if ((obj->cylind = malloc(sizeof(t_cylind) * obj->cylind_max)) == NULL)
			return (-1);
	}
	if (obj->cone_max)
	{
		if ((obj->cone = malloc(sizeof(t_cone) * obj->cone_max)) == NULL)
			return (-1);
	}
	if (allocate_light(obj) == -1)
		return (-1);
	return (0);
}

int			int_lenght(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int			parse_eye(t_env *e, char *line)
{
	t_vec	rot;
	char	*s;
	int		error;

	rot = vec_new(0, 0, 0);
	error = 1;
	if ((s = ft_strstr(line, "pos")) != NULL)
		error = (error == 1) ? fill_vector(s, "pos", &(e->eye_pos)) : -1;
	if ((s = ft_strstr(line, "rotxyz")) != NULL)
		error = (error == 1) ? fill_vector(s, "rotxyz", &rot) : -1;
	if (error == -1)
		return (m_error("scene file formated wrong -> eye"));
	if (rot.x != 0 || rot.y != 0 || rot.z != 0)
	{
		e->eye_dir = rot_xyz(e->eye_dir, rot.x, rot.y, rot.z);
		e->right_vec = rot_xyz(e->right_vec, rot.x, rot.y, rot.z);
		e->up_vec = rot_xyz(e->up_vec, rot.x, rot.y, rot.z);
	}
	e->view_plane_ori = vec_add(vec_add(e->eye_pos, vec_numb(e->eye_dir,
		VIEW_PLANE_DIST)), vec_sub(vec_numb(e->up_vec, VIEW_PLANE_HEIGHT / 2.0),
		vec_numb(e->right_vec, VIEW_PLANE_WIDTH / 2.0)));
	return (1);
}
