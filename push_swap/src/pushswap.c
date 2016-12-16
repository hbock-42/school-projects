#include "../include/pushswap.h"

int			main(int ac, char **av)
{
	int		*la;
	int		*lb;

	if (ac != 1)
	{
		la = (int *)malloc(sizeof(int) * ac);
		lb = (int *)malloc(sizeof(int) * ac);
		lb[ac - 1] = 0;
		la = fill_la(ac - 1, av + 1, la);
		lb = noob_algo(la, lb, ac - 1);
		la = reverse_l(la, lb, ac - 1);
		write(1, "\n", 1);
	}
	return (0);
}
