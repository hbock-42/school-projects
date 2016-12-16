#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	(void)len;
	if (!ft_strlen(little))
		return ((char*)big);
	i = -1;
	while (big[++i] && i < len)
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (little[j] && big[i + j] && i + j < len && little[j] ==
				big[i + j])
				j++;
			if (little[j] == 0)
				return ((char*)big + i);
		}
	}
	return (NULL);
}
