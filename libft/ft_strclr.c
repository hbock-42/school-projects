#include "libft.h"

void	ft_strclr(char *s)
{
	if (s != NULL)
		bzero(s, ft_strlen(s));
}
