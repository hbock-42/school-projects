#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*ptr1;
	const char	*ptr2;

	if (len <= 0)
		return (dst);
	ptr1 = dst;
	ptr2 = src;
	if (dst - src <= 0)
	{
		i = -1;
		while (++i < len)
			ptr1[i] = ptr2[i];
		dst = ptr1;
	}
	else
	{
		while (--len > 0)
			ptr1[len] = ptr2[len];
		ptr1[len] = ptr2[len];
		dst = ptr1;
	}
	return (dst);
}
