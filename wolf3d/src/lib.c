/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hugo <Hugo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 03:20:50 by hbock             #+#    #+#             */
/*   Updated: 2015/06/26 14:12:21 by Hugo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

static int				ft_calc(char *str)
{
	int					res;

	res = 0;
	while (ft_isdigit((int)(*str)))
	{
		res = *str - '0' + res * 10;
		str++;
	}
	return (res);
}

int						ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}

int						ft_isnumber(char *s)
{
	int					i;

	i = -1;
	while (s[++i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
	}
	return (1);
}

int						ft_atoi(const char *str)
{
	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	if ((*str == '-' && !ft_isdigit((int)*(str + 1)))
		|| (*str == '+' && !ft_isdigit((int)*(str + 1))))
		return (0);
	if (*str == '-' && ft_isdigit((int)*(str + 1)))
	{
		str++;
		return (-ft_calc((char *)(str)));
	}
	if (*str == '+' && ft_isdigit((int)*(str + 1)))
		str++;
	return (ft_calc((char *)(str)));
}

void					*ft_memcpy(void *s1, const void *s2, size_t n)
{
	unsigned char		*tmp;
	const unsigned char	*tmp2;
	size_t				i;

	tmp = s1;
	tmp2 = s2;
	i = 0;
	while (n)
	{
		tmp[i] = tmp2[i];
		i++;
		n--;
	}
	return (s1);
}
