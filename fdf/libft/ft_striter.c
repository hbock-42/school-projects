#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	int	i;

	i = -1;
	if (f != NULL && s != NULL)
	{
		while (s[++i])
			f(&s[i]);
	}
}
