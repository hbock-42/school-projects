#include "../include/fdf.h"

int			del_imap(t_map *m, int max_del)
{
	int		i;

	i = -1;
	if (max_del >= 0)
	{
		while (++i < max_del)
			free(m->map[i]);
	}
	free(m->map);
	return (-1);
}

static int	get_width(char *line, char ***splitted)
{
	int		width;

	if ((*splitted = ft_strsplit(line, ' ')) == NULL)
		return (0);
	width = 0;
	while ((*splitted)[width] != NULL)
		width++;
	return (width);
}

static void	fill_width(char ***splitted, t_map *m, int y)
{
	int		x;

	x = -1;
	while (++x < m->width)
	{
		m->map[y][x] = ft_atoi((*splitted)[x]);
		free((*splitted)[x]);
	}
	free(*splitted);
}

static int	fill_line(char ***cmap, t_map *m, int yline)
{
	int		width;
	char	**splitted;

	if ((width = get_width((*cmap)[yline], &splitted)) != m->width && m->width)
		return (del_cmap(cmap, m->height));
	if ((m->map[yline] = (int*)malloc(sizeof(int) * width)) == NULL)
		return (del_cmap(cmap, m->height));
	m->width = width;
	fill_width(&splitted, m, yline);
	return (1);
}

int			create_imap(char ***cmap, t_map *m)
{
	int		i;

	if ((m->map = (int**)malloc(sizeof(int*) * m->height)) == NULL)
		return (del_cmap(cmap, m->height));
	m->width = 0;
	i = -1;
	while (++i < m->height)
	{
		if (fill_line(cmap, m, i) == -1)
			return (del_imap(m, i - 1));
	}
	return (0);
}
