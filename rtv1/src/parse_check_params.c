/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check_params.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbock <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 15:22:53 by hbock             #+#    #+#             */
/*   Updated: 2016/11/18 15:22:54 by hbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

int			check_sphere(char *line)
{
	if (ft_strstr(line, "center") == NULL)
		return (m_error("sphere: center missing"));
	if (ft_strstr(line, "radius{") == NULL)
		return (m_error("sphere: radius missing"));
	return (0);
}

int			check_plane(char *line)
{
	if (ft_strstr(line, "point") == NULL)
		return (m_error("plane: point missing"));
	if (ft_strstr(line, "normal") == NULL)
		return (m_error("plane: normal missing"));
	if (ft_strstr(line, "d{") == NULL)
		return (m_error("plane: d is missing"));
	return (0);
}

int			check_cylinder(char *line)
{
	if (ft_strstr(line, "radius{") == NULL)
		return (m_error("cylinder: radius missing"));
	return (0);
}

int			check_cone(char *line)
{
	if (ft_strstr(line, "angle{") == NULL)
		return (m_error("cone: angle missing"));
	return (0);
}

int			check_light(char *line)
{
	if (ft_strstr(line, "pos") == NULL)
		return (m_error("light: pos missing"));
	return (0);
}
