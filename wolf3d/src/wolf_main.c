#include "../include/wolf.h"

int			main(int ac, char **av)
{
	char	*cmap;
	t_env	*e;

	e = NULL;
	if (ac != 2)
		return (0);
	if ((e = env_init(e)) == NULL)
		exit(EXIT_FAILURE);
	cmap = default_reading(av[1], e);
	create_int_map(cmap, e);
	wolf(e);
	hook_event(e);
	return (0);
}