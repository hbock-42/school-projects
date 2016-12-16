#include "../include/fdf.h"

void		on_screen_ctrl(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 10, 10, 0xFF0000, "Change perspective: 0");
	mlx_string_put(e->mlx, e->win, 10, 25, 0xFF0000,
		"Move the map: arrow keys");
	mlx_string_put(e->mlx, e->win, 10, 40, 0xFF0000,
		"Enlarge or reduce the map: 7 8");
	mlx_string_put(e->mlx, e->win, 10, 55, 0xFF0000, "Change the levels: + -");
	mlx_string_put(e->mlx, e->win, 10, 70, 0xFF0000,
		"Press esc to leave properly");
}

void		print_usages(void)
{
	ft_putendl("\e[92mPress:\e[39m numpad \e[35m1\e[39m\e[92m to see the options\n");
	ft_putendl("\e[31mpress esc to close\e[39m");
}
