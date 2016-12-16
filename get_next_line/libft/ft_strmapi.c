#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			snew[i] = f(i, s[i]);
	}
	return (snew);
}
