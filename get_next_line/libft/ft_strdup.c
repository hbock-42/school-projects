#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*cpy;

	i = ft_strlen(s1);
	if (!(cpy = (char *)malloc(sizeof(*cpy) * (i + 1))))
		return (NULL);
	i = -1;
	while (s1[++i])
		cpy[i] = s1[i];
	cpy[i] = 0;
	return (cpy);
}
