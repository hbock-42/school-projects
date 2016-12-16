#include "../include/fdf.h"

int		main(int ac, char **av)
{
	t_map	m;
	t_env	e;

	if (ac != 2)
		return (m_error("require ONE argument"));
	if (!(m.map_name = ft_strdup(av[1])))
		return (-1);
	if (get_map(&m) == -1)
		return (m_error("reading problem"));
	if (init_env(&e, &m) == -1)
		return (m_error("env initiation problem"));
	print_usages();
	parallel_fdf(&e);
	iso_fdf(&e);
	draw_fdf(&e, e.iso_map);
	hook_event(&e);
	return (0);
}
