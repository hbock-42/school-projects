/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_calc_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbock <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 12:21:25 by hbock             #+#    #+#             */
/*   Updated: 2016/11/17 12:21:40 by hbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

t_vec		vec_normalize(t_vec v)
{
	double	l;
	t_vec	res;

	l = vec_length(v);
	res.x = v.x / l;
	res.y = v.y / l;
	res.z = v.z / l;
	return (res);
}

double		vec_dot(t_vec u, t_vec v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

t_vec		rot_x(double alpha, t_vec v)
{
	t_vec	new;

	alpha = alpha / 180 * M_PI;
	new.x = v.x;
	new.y = v.y * cos(alpha) - v.z * sin(alpha);
	new.z = v.y * sin(alpha) + v.z * cos(alpha);
	return (new);
}

t_vec		rot_y(double alpha, t_vec v)
{
	t_vec	new;

	alpha = alpha / 180 * M_PI;
	new.x = v.x * cos(alpha) + v.z * sin(alpha);
	new.y = v.y;
	new.z = -v.x * sin(alpha) + v.z * cos(alpha);
	return (new);
}

t_vec		rot_z(double alpha, t_vec v)
{
	t_vec	new;

	alpha = alpha / 180 * M_PI;
	new.x = v.x * cos(alpha) - v.y * sin(alpha);
	new.y = v.x * sin(alpha) + v.y * cos(alpha);
	new.z = v.z;
	return (new);
}
