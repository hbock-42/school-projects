#ifndef FDF_H
# define FDF_H

/*
*** defines
*/

# define ABS(x) (((x) < 0) ? -(x) : x)
# define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
# define SQ_SIZE 30
# define WIN_X 1600
# define WIN_Y 1200
# define PARA_CONST 0.8
# define ISO_C1 0.8
# define ISO_C2 0.8

/*
** includes
*/

# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include "../dependencies/minilibx_macos/mlx.h"

/*
** structures
*/

typedef struct	s_map
{
	char		*map_name;
	int			fd;
	int			**map;
	int			height;
	int			width;
}				t_map;

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_line
{
	int			dx;
	int			dy;
	int			color;
	int			coef_sign;
}				t_line;

typedef struct	s_rgb
{
	float		red;
	float		green;
	float		blue;
}				t_rgb;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	int			bpp;
	int			size_line;
	int			endian;
	char		*addr;
	int			map_x;
	int			map_y;
	int			**map;
	t_coord		**para_map;
	t_coord		**iso_map;
	int			x_shift;
	int			y_shift;
	int			pers;
	int			maximize;
	float		para_const;
	float		para_const_sq;
	float		iso_c1;
	float		iso_c2;
}				t_env;

/*
** prototypes
*/

/*
** map
*/

int				get_map(t_map *m);
int				del_cmap(char ***cmap, int max_del);
int				create_imap(char ***cmap, t_map *m);

/*
*** fdf
*/

int				init_env(t_env *e, t_map *m);
void			parallel_fdf(t_env *e);
void			iso_fdf(t_env *e);
void			draw_fdf(t_env *e, t_coord **map);
void			print_line(t_coord a, t_coord b, t_env *e, int color);
void			line_hori(t_env *e, t_coord a, t_coord b, int color);
void			line_vert(t_env *e, t_coord a, t_coord b, int color);
void			change_pers(t_env *e);
void			draw_fdf(t_env *e, t_coord **map);
void			put_img_to_win(t_env *e);
void			put_pixel_to_img(t_env *e, int x, int y, int color);
void			depth_change(t_env *e, int sign);
void			reset_window(t_env *e);
void			map_shift(t_env *e, int modif);
void			const_modif(t_env *e, int modif);
void			hook_event(t_env *e);
void			free_map(t_env *e, t_coord **map);
void			leave(t_env *e);
void			print_usages(void);
void			on_screen_ctrl(t_env *e);

/*
** errors
*/

int				m_error(char *s);

#endif
