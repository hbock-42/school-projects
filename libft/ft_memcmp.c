#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;

	ptr1 = s1;
	ptr2 = s2;
	if (n == 0)
		return (0);
	i = 0;
	while (i < (n - 1) && ptr1[i] == ptr2[i])
		i++;
	return (ptr1[i] - ptr2[i]);
}
