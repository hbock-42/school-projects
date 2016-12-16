/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hugo <Hugo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 12:25:01 by hbock             #+#    #+#             */
/*   Updated: 2016/11/15 13:55:01 by Hugo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

static int	init_obj(t_obj *obj)
{
	obj->sphere_max = 0;
	obj->plane_max = 0;
	obj->cylind_max = 0;
	obj->cone_max = 0;
	obj->light_max = 0;
	return (0);
}

int			init_env(t_env *e, t_obj *obj)
{
	if ((e->mlx = mlx_init()) == NULL)
		return (m_error("mlx_init(): fail"));
	if ((e->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "rtv1")) == NULL)
		return (m_error("mlx_new_window(): fail"));
	if ((e->img = mlx_new_image(e->mlx, WIN_X, WIN_Y)) == NULL)
		return (m_error("mlx_new_image(): fail"));
	if ((e->addr = mlx_get_data_addr(e->img, &(e->bpp), &(e->size_line),
		&(e->endian))) == NULL)
		return (m_error("mlx_get_data_addr(): fail"));
	if ((e->rgb_tab = (t_rgb *)malloc(sizeof(t_rgb) * (WIN_X * WIN_Y))) == NULL)
		return (m_error("rgb_tab_init(): fail"));
	e->eye_pos = vec_new(0, 0, 0);
	e->eye_dir = vec_new(0, 0, 1);
	e->right_vec = vec_new(1, 0, 0);
	e->up_vec = vec_new(0, -1, 0);
	e->view_plane_ori = vec_add(vec_add(e->eye_pos, vec_numb(e->eye_dir,
		VIEW_PLANE_DIST)), vec_sub(vec_numb(e->up_vec, VIEW_PLANE_HEIGHT / 2.0)
		, vec_numb(e->right_vec, VIEW_PLANE_WIDTH / 2.0)));
	init_obj(obj);
	return (0);
}
