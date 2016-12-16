/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbock <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 16:22:20 by hbock             #+#    #+#             */
/*   Updated: 2016/09/19 16:22:37 by hbock            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

static int	key_hook(unsigned int key)
{
	if (key == 53)
		exit(0);
	return (0);
}

static int	expose_hook(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

static int	end_program(void)
{
	exit(0);
	return (0);
}

void		hook_event(t_env *e)
{
	mlx_key_hook(e->win, &key_hook, e);
	mlx_hook(e->win, DESTROYNOTIFY, STRUCTURENOTIFYMASK, &end_program, e);
	mlx_expose_hook(e->win, &expose_hook, e);
	mlx_loop(e->mlx);
}
