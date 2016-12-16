#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	lend;
	size_t	lens;
	size_t	i;
	size_t	ret;

	lend = ft_strlen(dst);
	lens = ft_strlen(src);
	ret = size <= lend ? size + lens : lend + lens;
	i = -1;
	while (src[++i] && (i + lend + 1) < size)
	{
		dst[lend + i] = src[i];
	}
	dst[lend + i] = 0;
	return (ret);
}
