#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = b;
	i = -1;
	while (++i < len)
		ptr[i] = (unsigned char)c;
	return (b);
}
