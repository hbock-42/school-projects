/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hugo <Hugo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 16:20:49 by hbock             #+#    #+#             */
/*   Updated: 2016/11/15 13:59:55 by Hugo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

static void	put_pixel_to_img(t_env *e, int x, int y, int color)
{
	int		begin;

	begin = (x * e->bpp / 8) + (y * e->size_line);
	if ((y >= 0 && y <= WIN_Y) && (x >= 0 && x <= WIN_X))
		ft_memcpy(e->addr + begin, &color, (e->bpp / 8));
}

static void	exposure_correction(t_env *e)
{
	int		max;
	int		x;
	double	coef;

	x = -1;
	max = -1;
	while (++x < (WIN_X * WIN_Y))
	{
		max = (e->rgb_tab[x].r > max) ? e->rgb_tab[x].r : max;
		max = (e->rgb_tab[x].g > max) ? e->rgb_tab[x].g : max;
		max = (e->rgb_tab[x].b > max) ? e->rgb_tab[x].b : max;
	}
	coef = 254.0 / max;
	x = -1;
	if (max > 1)
	{
		while (++x < (WIN_X * WIN_Y))
			e->rgb_tab[x] = color_product(e->rgb_tab[x], coef);
	}
}

double		phong(t_vec normal, t_vec light_dir, t_vec eye_dir, int type)
{
	double		reflect;
	t_vec		phong_dir;
	double		phong_coef;

	reflect = 2 * vec_dot(light_dir, normal);
	phong_dir = vec_sub(light_dir, vec_numb(normal, reflect));
	phong_coef = vec_dot(phong_dir, eye_dir);
	phong_coef = (phong_coef > 0) ? phong_coef : 0;
	if (type == SPHERE)
		phong_coef = SPHERE_SPEC_VALUE * pow(phong_coef, MAT_SPEC_POWER);
	else if (type == PLANE)
		phong_coef = PLANE_SPEC_VALUE * pow(phong_coef, MAT_SPEC_POWER);
	else if (type == CYLINDER)
		phong_coef = CYLINDER_SPEC_VALUE * pow(phong_coef, MAT_SPEC_POWER);
	else
		phong_coef = CONE_SPEC_VALUE * pow(phong_coef, MAT_SPEC_POWER);
	return (phong_coef);
}

void		draw(t_env *e)
{
	int		x;
	int		y;

	exposure_correction(e);
	y = -1;
	while (++y < WIN_Y)
	{
		x = -1;
		while (++x < WIN_X)
			put_pixel_to_img(e, x, y,
				color_convert_rgb(e->rgb_tab[y * WIN_X + x]));
	}
}

void		calc_color(t_env *e, t_obj *obj, int x, int y)
{
	t_rgb	color;
	t_rgb	color2;

	if (obj->type_fix == SPHERE)
		color = new_color_set(255, 0, 0);
	else if (obj->type_fix == PLANE)
		color = new_color_set(0, 255, 0);
	else if (obj->type_fix == CYLINDER)
		color = new_color_set(0, 0, 255);
	else
		color = new_color_set(255, 102, 178);
	color = color_product(color, obj->lambert);
	color2 = new_color_set(255, 255, 255);
	color2 = color_product(color2, obj->phong);
	color = color_add(color, color2);
	e->rgb_tab[y * WIN_X + x] = color;
}
