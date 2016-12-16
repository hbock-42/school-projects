/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hugo <Hugo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 11:36:25 by hbock             #+#    #+#             */
/*   Updated: 2016/11/15 13:54:32 by Hugo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

int		main(int ac, char **av)
{
	t_env	e;
	t_obj	obj;

	if (init_env(&e, &obj) == -1)
		return (-1);
	if (ac != 2)
		return (-1);
	if (read_scene(&e, &obj, av[1]) == -1)
		return (-1);
	raylaunch(&e, &obj);
	hook_event(&e);
	return (0);
}
