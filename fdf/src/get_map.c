#include "../include/fdf.h"

static int	get_map_height(t_map *m)
{
	int		ret;
	int		height;
	char	*line;

	height = 0;
	if ((m->fd = open(m->map_name, O_RDONLY)) == -1)
		return (-1);
	while ((ret = get_next_line(m->fd, &line)))
	{
		free(line);
		height++;
	}
	close(m->fd);
	if (ret == -1)
		return (-1);
	return (height);
}

int			del_cmap(char ***cmap, int max_del)
{
	int		i;

	i = -1;
	while (++i < max_del)
		free((*cmap)[i]);
	free(*cmap);
	return (-1);
}

static int	read_map(char ***cmap, t_map *m)
{
	int		height;
	int		i;
	int		ret;
	char	*line;

	if ((height = get_map_height(m)) == -1)
		return (-1);
	if ((*cmap = (char**)malloc(sizeof(**cmap) * height)) == NULL)
		return (-1);
	if ((m->fd = open(m->map_name, O_RDONLY)) == -1)
		return (-1);
	i = 0;
	while ((ret = get_next_line(m->fd, &line)) > 0)
	{
		(*cmap)[i] = line;
		i++;
	}
	close(m->fd);
	if (ret == -1)
		return (del_cmap(cmap, i));
	m->height = height;
	return (0);
}

int			get_map(t_map *m)
{
	char	**cmap;

	if (read_map(&cmap, m) == -1)
		return (-1);
	if (create_imap(&cmap, m) == -1)
		return (-1);
	return (0);
}
