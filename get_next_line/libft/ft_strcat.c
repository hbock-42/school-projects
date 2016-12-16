#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int	len;
	int	i;

	len = ft_strlen(s1);
	i = -1;
	while (s2[++i])
	{
		s1[len + i] = s2[i];
	}
	s1[len + i] = 0;
	return (s1);
}
