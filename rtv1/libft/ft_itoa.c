#include "libft.h"

static int		num_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	int		len;
	int		sign;
	char	*nbr;

	len = num_len(n);
	if (!(nbr = ft_strnew(len)))
		return (NULL);
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		nbr[0] = '-';
	}
	while (len-- >= 0)
	{
		nbr[len] = '0' + ((n % 10) * sign);
		n /= 10;
		if (len == 1 && sign < 0)
			len = 0;
	}
	return (nbr);
}
