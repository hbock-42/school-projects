/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hugo <Hugo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 16:20:49 by hbock             #+#    #+#             */
/*   Updated: 2016/11/15 13:56:10 by Hugo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

t_rgb		new_color_set(double r, double g, double b)
{
	t_rgb	color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

t_rgb		color_product(t_rgb c, double x)
{
	c.r *= x;
	c.g *= x;
	c.b *= x;
	return (c);
}

t_rgb		color_add(t_rgb c1, t_rgb c2)
{
	t_rgb	new;

	new.r = c1.r + c2.r;
	new.g = c1.g + c2.g;
	new.b = c1.b + c2.b;
	return (new);
}

int			color_convert_rgb(t_rgb rgb)
{
	return ((int)rgb.r << 16 | (int)rgb.g << 8 | (int)rgb.b);
}
