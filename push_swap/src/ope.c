#include "../include/pushswap.h"

int			*r_left(int *l, int tab_len)
{
	int		i;
	int		tmp;

	if (tab_len > 1)
	{
		tmp = l[0];
		i = -1;
		while (++i < (tab_len - 1))
			l[i] = l[i + 1];
		l[i] = tmp;
	}
	write(1, "ra ", 3);
	return (l);
}

int			*r_right(int *l, int tab_len)
{
	int		i;
	int		tmp;

	if (tab_len > 1)
	{
		tmp = l[tab_len - 1];
		i = tab_len;
		while (--i > 0)
			l[i] = l[i - 1];
		l[i] = tmp;
	}
	write(1, "rra ", 4);
	return (l);
}

t_two_l		p(int *l2, int *l1, int init_len)
{
	int		i;
	t_two_l	l;

	i = l1[init_len] + 1;
	while (--i > 0)
		l1[i] = l1[i - 1];
	l1[init_len]++;
	l1[0] = l2[0];
	i--;
	while (++i < (l2[init_len] - 1))
		l2[i] = l2[i + 1];
	l2[init_len]--;
	l.l1 = l1;
	l.l2 = l2;
	return (l);
}
