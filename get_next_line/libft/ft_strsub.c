#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ns;
	size_t	i;

	if (!len)
		return (ft_strnew(0));
	ns = NULL;
	if (s != NULL && ft_strlen(s) && len)
	{
		i = -1;
		if ((ns = ft_strnew(len)) == NULL)
			return (NULL);
		while (++i < len && s[start + i])
			ns[i] = s[start + i];
	}
	return (ns);
}
