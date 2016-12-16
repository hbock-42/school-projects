#include "../include/pushswap.h"

int			*noob_algo(int *la, int *lb, int init_len)
{
	int		i;
	int		j;
	int		index_min;
	t_two_l	l;

	i = -1;
	while (++i < init_len)
	{
		index_min = find_min(la, la[init_len]);
		j = -1;
		if (index_min < ((la[init_len] / 2) + 1))
		{
			while (++j < index_min)
				la = r_left(la, la[init_len]);
		}
		else
		{
			while (++j < (la[init_len] - index_min))
				la = r_right(la, la[init_len]);
		}
		l = p(la, lb, init_len);
		write(1, "pb ", 3);
	}
	return (l.l1);
}

int			*reverse_l(int *la, int *lb, int init_len)
{
	int		i;
	t_two_l	l;

	la[init_len] = 0;
	l = p(lb, la, init_len);
	write(1, "pa", 2);
	if (init_len > 1)
		write(1, " ", 1);
	i = 0;
	while (++i < init_len)
	{
		l = p(l.l2, l.l1, init_len);
		write(1, "pa", 2);
		if (i != (init_len - 1))
			write(1, " ", 1);
	}
	return (l.l1);
}
