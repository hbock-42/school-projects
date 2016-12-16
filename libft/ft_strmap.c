#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	char			*snew;

	snew = NULL;
	i = -1;
	if (f != NULL && s != NULL)
	{
		if (!(snew = ft_strnew(ft_strlen(s))))
			return (NULL);
		while (s[++i])
			snew[i] = f(s[i]);
	}
	return (snew);
}
