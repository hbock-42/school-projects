#include "libft.h"

static char	*clear_spaces(const char *str)
{
	int i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
		str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		i++;
	return ((char*)str + i);
}

int			ft_atoi(const char *str)
{
	char	*s;
	int		sign;
	int		i;
	int		nb;

	sign = 1;
	i = -1;
	nb = 0;
	s = clear_spaces(str);
	if (s[0] != '+' && s[0] != '-' && !ft_isdigit(s[0]))
		return (0);
	if (s[0] == '+')
	{
		i = 0;
	}
	else if (s[0] == '-')
	{
		sign = -1;
		i = 0;
	}
	while (s[++i] && ft_isdigit(s[i]))
		nb = nb * 10 + (s[i] - 48);
	return (sign * nb);
}
