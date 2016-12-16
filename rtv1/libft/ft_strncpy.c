#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	lsrc;

	i = -1;
	while (src[++i] && i < len)
		dst[i] = src[i];
	if ((lsrc = ft_strlen(src)) < len)
	{
		while (i < len)
			dst[i++] = 0;
	}
	return (dst);
}
