#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*ptr1;
	const unsigned char	*ptr2;

	ptr1 = dst;
	ptr2 = src;
	i = -1;
	while (++i < n)
	{
		if (ptr2[i] != (unsigned char)c)
			ptr1[i] = ptr2[i];
		else
		{
			ptr1[i] = ptr2[i];
			return (dst + i + 1);
		}
	}
	return (NULL);
}
