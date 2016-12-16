/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hugo <Hugo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 11:36:25 by hbock             #+#    #+#             */
/*   Updated: 2016/11/15 13:39:26 by Hugo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

static int	count_objects(t_obj *obj, char *scene)
{
	int		fd;
	int		ret;
	char	*line;

	if ((fd = open(scene, O_RDONLY)) == -1)
		return (-1);
	while ((ret = get_next_line(fd, &line)))
	{
		if (ft_strstr(line, "sphere") != NULL)
			obj->sphere_max++;
		if (ft_strstr(line, "plane") != NULL)
			obj->plane_max++;
		if (ft_strstr(line, "cylinder") != NULL)
			obj->cylind_max++;
		if (ft_strstr(line, "cone") != NULL)
			obj->cone_max++;
		if (ft_strstr(line, "light") != NULL)
			obj->light_max++;
		free(line);
	}
	if (ret == -1)
		return (-1);
	if (allocate_obj(obj, fd) == -1)
		return (-1);
	return (0);
}

static int	check_missing_params(char *line)
{
	int		error;

	error = 1;
	if (ft_strstr(line, "sphere") != NULL)
		error = (error == 1) ? check_sphere(line) : -1;
	if (ft_strstr(line, "plane") != NULL)
		error = (error == 1) ? check_plane(line) : -1;
	if (ft_strstr(line, "cylinder") != NULL)
		error = (error == 1) ? check_cylinder(line) : -1;
	if (ft_strstr(line, "cone") != NULL)
		error = (error == 1) ? check_cone(line) : -1;
	if (ft_strstr(line, "light") != NULL)
		error = (error == 1) ? check_light(line) : -1;
	if (error == -1)
		return (-1);
	return (0);
}

static int	under_parse(t_env *e, t_obj *obj, char *line, t_parse *p)
{
	int		error;

	if (check_missing_params(line) == -1)
		return (-1);
	error = 1;
	if (ft_strstr(line, "sphere") != NULL)
		error = (error == 1) ? parse_sphere(obj, line, p) : -1;
	if (ft_strstr(line, "plane") != NULL)
		error = (error == 1) ? parse_plane(obj, line, p) : -1;
	if (ft_strstr(line, "cylinder") != NULL)
		error = (error == 1) ? parse_cylinder(obj, line, p) : -1;
	if (ft_strstr(line, "cone") != NULL)
		error = (error == 1) ? parse_cone(obj, line, p) : -1;
	if (ft_strstr(line, "light") != NULL)
		error = (error == 1) ? parse_light(obj, line, p) : -1;
	if (ft_strstr(line, "eye") != NULL)
		error = (error == 1) ? parse_eye(e, line) : -1;
	if (error == -1)
		return (-1);
	return (0);
}

static int	parse_attributes(t_env *e, t_obj *obj, char *scene)
{
	int		fd;
	int		ret;
	char	*line;
	t_parse	p;

	if ((fd = open(scene, O_RDONLY)) == -1)
		return (-1);
	p.id_sp = 0;
	p.id_pl = 0;
	p.id_cy = 0;
	p.id_co = 0;
	p.id_li = 0;
	while ((ret = get_next_line(fd, &line)))
	{
		if (under_parse(e, obj, line, &p) == -1)
		{
			free(line);
			return (-1);
		}
		free(line);
	}
	close(fd);
	if (ret == -1)
		return (-1);
	return (0);
}

int			read_scene(t_env *e, t_obj *obj, char *scene)
{
	int		fd;

	if (check_name(scene) == -1)
		return (-1);
	if ((fd = open(scene, O_WRONLY)) == -1)
		return (m_error("You tried to open a directory !"));
	else
		close(fd);
	if (count_objects(obj, scene) == -1)
		return (-1);
	if (parse_attributes(e, obj, scene) == -1)
		return (-1);
	return (0);
}
