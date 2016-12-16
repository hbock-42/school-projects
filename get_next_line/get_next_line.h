#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32
# define EOF (-1)

/*
** includes
*/

# include "libft/libft.h"

typedef struct		s_static_s
{
	char			static_s[BUFF_SIZE + 1];
	int				first_gnl_use;
}					t_static_s;

/*
** prototypes
*/

int					get_next_line(const int fd, char **line);

#endif
