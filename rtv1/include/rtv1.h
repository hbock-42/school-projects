/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hugo <Hugo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 11:49:44 by hbock             #+#    #+#             */
/*   Updated: 2016/11/15 14:10:32 by Hugo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# define VIEW_PLANE_WIDTH 0.5
# define VIEW_PLANE_HEIGHT 0.35
# define VIEW_PLANE_DIST 1.0
# define WIN_X 1300
# define WIN_Y 900
# define SPHERE 0
# define PLANE 1
# define CYLINDER 2
# define CONE 3
# define INFI 100000
# define EPSILONE 0.01
# define PLANE_SPEC_VALUE 1
# define SPHERE_SPEC_VALUE 1
# define CYLINDER_SPEC_VALUE 1
# define CONE_SPEC_VALUE 1
# define MAT_SPEC_POWER 4

/*
** mlx define
*/

# define DESTROYNOTIFY 17
# define STRUCTURENOTIFYMASK (1L<<17)

# include "../libft/libft.h"
# include <math.h>
# include "../dependencies/minilibx_macos/mlx.h"
# include <fcntl.h>

typedef struct	s_vec
{
	double		x;
	double		y;
	double		z;
}				t_vec;

typedef struct	s_rgb
{
	double		r;
	double		g;
	double		b;
}				t_rgb;

typedef struct	s_env
{
	void		*mlx;
	void		*img;
	void		*win;
	int			bpp;
	int			size_line;
	int			endian;
	char		*addr;
	int			inter[4];
	t_vec		view_plane_ori;
	t_vec		eye_pos;
	t_vec		eye_dir;
	t_vec		right_vec;
	t_vec		up_vec;
	t_vec		pix_ray;
	t_rgb		*rgb_tab;
	double		x_indent;
	double		y_indent;
}				t_env;

typedef struct	s_light
{
	t_vec		o;
}				t_light;

typedef struct	s_sphere
{
	t_vec		c;
	double		r;
}				t_sphere;

typedef struct	s_plane
{
	double		a;
	double		b;
	double		c;
	double		d;
	t_vec		point;
}				t_plane;

typedef struct	s_cylind
{
	t_vec		o;
	t_vec		eye_pos;
	t_vec		eye_dir;
	double		rotx;
	double		roty;
	double		rotz;
	double		r;
}				t_cylind;

typedef struct	s_cone
{
	t_vec		o;
	t_vec		eye_pos;
	t_vec		eye_dir;
	double		rotx;
	double		roty;
	double		rotz;
	double		alpha;
	double		tan_alpha;
}				t_cone;

typedef struct	s_obj
{
	t_light		*light;
	int			light_max;
	t_sphere	*sphere;
	int			sphere_max;
	t_plane		*plane;
	int			plane_max;
	t_cylind	*cylind;
	int			cylind_max;
	t_cone		*cone;
	int			cone_max;
	int			id;
	int			type;
	int			type_fix;
	double		t;
	t_vec		hitpoint;
	t_vec		light_dir;
	t_vec		neg_light_dir;
	double		lambert;
	double		phong;
	double		dot;
}				t_obj;

typedef struct	s_ray
{
	t_vec		o;
	t_vec		dir;
}				t_ray;

typedef	struct	s_parse
{
	int			id_sp;
	int			id_pl;
	int			id_cy;
	int			id_co;
	int			id_li;
}				t_parse;

typedef struct	s_quad
{
	double		a;
	double		b;
	double		c;
	double		delta;
	double		t1;
	double		t2;
}				t_quad;

int				init_env(t_env *e, t_obj *obj);

/*
**vector calcul
*/

t_vec			vec_add(t_vec v1, t_vec v2);
t_vec			vec_sub(t_vec v1, t_vec v2);
t_vec			vec_numb(t_vec v, double r);
t_vec			vec_new(double x, double y, double z);
t_vec			vec_normalize(t_vec v);
double			vec_length(t_vec v);
double			vec_dot(t_vec u, t_vec v);
t_vec			rot_x(double alpha, t_vec v);
t_vec			rot_y(double alpha, t_vec v);
t_vec			rot_z(double alpha, t_vec v);
t_vec			rot_xyz(t_vec v, double x, double y, double z);

/*
**other
*/

void			calc_inter(t_env *e, t_obj *obj, int shadow);
void			inter_sphere(int id, t_obj *obj, t_ray ray);
void			inter_plane(int id, t_obj *obj, t_ray ray);
void			inter_cylinder(int id, t_obj *obj, t_ray ray);
void			inter_cone(int id, t_obj *obj, t_ray ray);
void			raylaunch(t_env *e, t_obj *obj);
void			hook_event(t_env *e);
void			shadow(t_env *e, t_obj *obj, int x, int y);
int				m_error(char *s);
void			draw(t_env *e);

/*
**color
*/

int				color_convert_rgb(t_rgb rgb);
void			color_set(t_rgb *pixel, double r, double g, double b);
t_rgb			color_product(t_rgb c, double x);
t_rgb			new_color_set(double r, double g, double b);
t_rgb			color_add(t_rgb c1, t_rgb c2);
void			calc_color(t_env *e, t_obj *obj, int x, int y);
double			phong(t_vec normal, t_vec light_dir, t_vec eye_dir, int type);

/*
**parser
*/

int				read_scene(t_env *e, t_obj *obj, char *scene);
int				check_name(char *name);
int				allocate_obj(t_obj *obj, int fd);
int				int_lenght(int n);
int				fill_vector(char *s, char *needle, t_vec *v);
int				parse_light(t_obj *obj, char *line, t_parse *p);
int				parse_sphere(t_obj *obj, char *line, t_parse *p);
int				parse_plane(t_obj *obj, char *line, t_parse *p);
int				parse_plane_1(t_obj *obj, char *line, t_parse *p);
void			fill_plane_0(t_obj *obj, t_parse *p, t_vec point, t_vec normal);
int				parse_cylinder(t_obj *obj, char *line, t_parse *p);
int				parse_cone(t_obj *obj, char *line, t_parse *p);
int				parse_eye(t_env *e, char *line);
int				check_sphere(char *line);
int				check_plane(char *line);
int				check_cylinder(char *line);
int				check_cone(char *line);
int				check_light(char *line);

#endif
