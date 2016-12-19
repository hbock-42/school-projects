/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reallocat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hugo <Hugo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/14 10:01:21 by Hbock             #+#    #+#             */
/*   Updated: 2015/06/26 14:12:27 by Hugo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

int			ft_strlen(char *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char		*ft_strcpy(char *dst, char *src)
{
	int		i;

	i = -1;
	while (src[++i])
		dst[i] = src[i];
	dst[i] = 0;
	return (dst);
}

char		*ft_strcat(char *dst, char *to_add)
{
	int		len_dst;
	int		i;

	len_dst = ft_strlen(dst);
	i = -1;
	while (to_add[++i])
		dst[len_dst + i] = to_add[i];
	dst[len_dst + i] = 0;
	return (dst);
}

char		*ft_reallocat(char *dst, char *to_add)
{
	char	*tmp;
	int		l1;
	int		l2;

	l1 = ft_strlen(dst);
	l2 = ft_strlen(to_add);
	tmp = malloc(sizeof(char) * (l1 + 1));
	tmp = ft_strcpy(tmp, dst);
	free(dst);
	dst = malloc(sizeof(char) * (l1 + l2 + 1));
	dst = ft_strcpy(dst, tmp);
	free(tmp);
	dst = ft_strcat(dst, to_add);
	return (dst);
}
