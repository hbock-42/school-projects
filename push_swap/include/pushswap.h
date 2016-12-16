#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct	s_two_l
{
	int		*l1;
	int		*l2;
}				t_two_l;

void			ft_error();
void			ft_putendl(char *s);
int				*fill_la(int tab_len, char **tab, int *i_tab);
int				ft_atoi(char *str);
int				*r_left(int *l, int tab_len);
int				*r_right(int *l, int tab_len);
t_two_l			p(int *l2, int *l1, int init_len);
int				find_min(int *l, int len);
int				*noob_algo(int *la, int *lb, int init_len);
int				*reverse_l(int *la, int *lb, int init_len);
int				is_sort(int	*l, int init_len);

#endif
