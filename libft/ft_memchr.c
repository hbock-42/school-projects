#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*ptr;

	ptr = s;
	i = -1;
	while (++i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void*)ptr + i);
	}
	return (NULL);
}
