#include "libft.h"

static	char	*init_sp(void)
{
	char	*sp;

	if (!(sp = ft_strnew(4)))
		return (NULL);
	sp[0] = ' ';
	sp[1] = '\t';
	sp[2] = '\n';
	return (sp);
}

char			*ft_strtrim(char const *s)
{
	int		len;
	int		start;
	int		end;
	char	*sp;

	if (!(sp = init_sp()))
		return (NULL);
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (!len)
		return (ft_strnew(1));
	if (len && (!ft_strchr(sp, s[0]) && !ft_strchr(sp, s[len - 1])))
		return (ft_strdup(s));
	start = 0;
	while (s[start] && ft_strchr(sp, s[start]))
		start++;
	end = len - 1;
	while (s[end] && ft_strchr(sp, s[end]))
		end--;
	if (end < start)
		return (ft_strnew(1));
	len = end - start + 1;
	return (ft_strsub(s, start, len));
}
