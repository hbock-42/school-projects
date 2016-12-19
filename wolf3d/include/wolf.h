#ifndef WOLF_H
# define WOLF_H

# define ABS(x) (((x) < 0) ? -(x) : x)
# define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
# define WIN_X 800
# define WIN_Y 600
# define BUFF 1024
# define CUBE 700
# define POSX_START 22
# define POSY_START 12
# define DIRX_START -1
# define DIRY_START 0
//Plane must be perpendicular to dir
# define PLANEX_START 0
# define PLANEY_START 0.66
# define COLOR1 0xF0C60C
# define COLOR2 0xF00CA8
# define COLOR3 0x0C36F0
# define COLOR4 0x0CF054
# define INI_SPEED 0.2
# define INI_ROT_SPEED 0.05

# include "../dependencies/minilibx_macos/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <errno.h>
# include <unistd.h>
# include <math.h>
# include <time.h>

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef enum		e_event
{
	GO_UP =		0,
	GO_DOWN =		1,
	ROT_LEFT =		2,
	ROT_RIGHT =		3,
}					t_event;

typedef struct	s_d_coord
{
	double		x;
	double		y;
}				t_d_coord;

typedef struct	s_dda
{
	int			map_x;
	int			map_y;
	int			hit;
	int			step_x;
	int			step_y;
	int			side;
	double		ini_distx;
	double		ini_disty;
	double		delta_distx;
	double		delta_disty;
	double		orth_proj_dist;
}				t_dda;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	int			bpp;
	t_dda		*d;
	int			size_line;
	int			endian;
	char		*addr;
	int			map_x;
	int			map_y;
	int			**map;
	t_d_coord	*pos;
	t_d_coord	*dir;
	t_d_coord	*ray_pos;
	t_d_coord	*ray_dir;
	t_d_coord	*plane;
	t_event		*event;
	double		camera_x;
	int			wall_height;
	int			cube;
	double		speed;
	double		rot_speed;
	double		frame_time;
	int			fps;
	void		**textures;
}				t_env;

t_env			*env_init(t_env *e);
int				ft_atoi(const char *str);
int				ft_isdigit(int c);
void			*ft_memcpy(void *s1, const void *s2, size_t n);
char			*ft_reallocat(char *dst, char *to_add);
void			put_pixel_to_img(t_env *e, int x, int y, int color);
void			put_img_to_win(t_env *e);
void			free_map(t_env *e, t_coord **map);
char			*ft_reallocat(char *dst, char *to_add);
char			*default_reading(char *file, t_env *e);
char			**ft_strsplit(char const *s, char c);
void			create_int_map(char *cmap, t_env *e);
int				ft_isnumber(char *s);
void			reset_window(t_env *e);
void			wolf(t_env *e);
void			calc_view_ray(t_env *e, int x);
t_dda			*dda_algorithm(t_env *e);
int				calc_wall(t_env *e);
void			draw_column(t_env *e, int x);
void			hook_event(t_env *e);
void			reset_image(t_env *e);
void			p_move(t_env *e, int modif);
t_dda			*init_dda_struct(t_env *e);
int				calc_color(t_env *e);
int				calc_shadow_color(int color, double dist);

#endif