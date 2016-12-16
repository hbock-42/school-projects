#include "../include/pushswap.h"

int			check_new_number(int *i_tab, int i)
{
	int		j;

	j = -1;
	while (++j < i)
	{
		if (i_tab[j] == i_tab[i])
			return (1);
	}
	return (0);
}

int			*fill_la(int tab_len, char **tab, int *i_tab)
{
	int		i;

	i = -1;
	while (++i < tab_len)
	{
		i_tab[i] = ft_atoi(tab[i]);
		if (check_new_number(i_tab, i))
			ft_error();
	}
	i_tab[tab_len] = tab_len;
	return (i_tab);
}

void		ft_putendl(char *s)
{
	int		i;

	i = -1;
	while (s[++i])
	{
		write(1, &s[i], 1);
	}
	write(1, "\n", 1);
}

int			find_min(int *l, int len)
{
	int		i;
	int		min_index;

	min_index = 0;
	i = 0;
	while (++i < len)
	{
		if (l[i] < l[min_index])
			min_index = i;
	}
	return (min_index);
}

int			is_sort(int *l, int init_len)
{
	int		i;

	i = -1;
	while (++i < (l[init_len] - 1))
	{
		if (l[i] > l[i + 1])
			return (1);
	}
	return (0);
}
