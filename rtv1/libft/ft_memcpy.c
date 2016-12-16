#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*ptr1;
	const char	*ptr2;

	ptr1 = dst;
	ptr2 = src;
	i = -1;
	while (++i < n)
		ptr1[i] = ptr2[i];
	return (dst);
}
