#include "libft.h"

static int	num_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static int	ft_power(int n, unsigned int power)
{
	if (power == 0)
		return (1);
	if (power > 1)
		return (n * ft_power(n, power - 1));
	return (n);
}

void		ft_putnbr(int n)
{
	int	i;
	int	len;
	int	sign;
	int	divisor;

	len = num_len(n);
	sign = (n < 0) ? -1 : 1;
	if (sign < 0)
		ft_putchar('-');
	divisor = ft_power(10, len - 1);
	i = -1;
	while (++i < len)
	{
		ft_putchar('0' + ((n / divisor) % 10) * sign);
		divisor /= 10;
	}
}
