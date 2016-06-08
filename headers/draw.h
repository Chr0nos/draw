/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 13:27:50 by snicolet          #+#    #+#             */
/*   Updated: 2016/06/08 18:38:44 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H
# include <string.h>
# include <SDL2/SDL.h>
# include "colors.h"
# include "tpoint.h"
# include "t_v4f.h"
# include "drawsdl.h"
# include "tperspective.h"

enum			e_color
{
	COLOR_WHITE = 0x00ffffff,
	COLOR_BLUE = 0x000000ff,
	COLOR_RED = 0x00ff0000,
	COLOR_GREEN = 0x0000ff00,
	COLOR_PURPLE = 0x009900cc,
	COLOR_CYAN = 0x0000ccff,
	COLOR_YELLOW = 0x00ffff00,
	COLOR_BROWN = 0x00220000,
	COLOR_BLACK = 0
};

enum			e_hook
{
	KEYDOWN = 2,
	KEYUP = 3,
	MOUSEDOWN = 4,
	MOUSEUP = 5,
	MOUSEMOVE = 6,
	EXPOSE = 12,
	CLOSE = 17
};

typedef struct	s_tab
{
	size_t		size;
	size_t		line_len;
	int			*tab;
}				t_tab;

typedef struct	s_draw_vector
{
	float		x;
	float		y;
	float		z;
}				t_vector;

typedef struct	s_matrix
{
	t_vector	x;
	t_vector	y;
	t_vector	z;
	t_vector	offset;
}				t_matrix;

typedef struct	s_area
{
	t_point		start;
	t_point		end;
}				t_area;

typedef struct	s_line
{
	t_point		start;
	t_point		end;
	int			dx;
	int			dy;
}				t_line;

typedef t_area	t_rect;
typedef struct	s_circle
{
	t_point		center;
	int			radius;
}				t_circle;

t_matrix		draw_make_matrix_x(t_vector pos, float rad, t_vector scale);
t_matrix		draw_make_matrix_y(t_vector pos, float rad, t_vector scale);
t_matrix		draw_make_matrix_z(t_vector pos, float rad, t_vector scale);
t_matrix		draw_make_matrix_perspective(t_perspective s, t_vector c);
t_matrix		draw_make_matrix_iso(int x, int y, int w, int h);
t_matrix		draw_make_matrix_ortho(t_vector s, t_vector c);
t_matrix		draw_matrix_multiply_matrix(t_matrix m1, const t_matrix *m2);
t_matrix		draw_make_matrix_identity(void);
t_matrix		draw_matrix_multiply_axes(t_vector axes, t_vector scale,
	t_vector offset);

t_m4			draw_make_matrix_m4_identity(void);
t_m4			draw_make_matrix_m4_iso(int x, int y, int w, int h);
t_m4			draw_make_matrix_m4_ortho(const t_v4d s, const t_v4d c);
t_v4d			draw_vector_transform_m4(t_v4d v, const t_m4 *m);
t_m4			draw_matrix_multiply_matrix_m4(t_m4 m1, const t_m4 *m2);
t_m4			draw_make_matrix_m4_x(t_v4d pos, double rad, t_v4d scale);
t_m4			draw_make_matrix_m4_y(t_v4d pos, double rad, t_v4d scale);
t_m4			draw_make_matrix_m4_z(t_v4d pos, double rad, t_v4d scale);
t_m4			draw_matrix_multiply_axes_m4(t_v4d axes, t_v4d scale,
	t_v4d offset);
t_v4f			draw_v4f_add(t_v4f a, t_v4f b);
t_v4d			draw_v4d_add(t_v4d a, t_v4d b);
t_v4d			draw_matrix_multiply_m4(t_v4d pt, const t_m4 *m);
t_v4f			draw_convert_v4d_to_v4f(t_v4d v);
t_m4			draw_make_rot_m4(t_v4d axis, double rad, t_v4d pos,
	t_v4d scale);
t_m4			draw_make_euler_m4(t_v4d euler, t_v4d pos, t_v4d scale);

t_matrix		draw_make_matrix_rot_x(double rad);
t_matrix		draw_make_matrix_rot_y(double rad);
t_matrix		draw_make_matrix_rot_z(double rad);

t_vector		draw_make_vector(float x, float y, float z);
t_vector		draw_vector_transform(t_vector v, const t_matrix *m);
t_vector		draw_vector_add(t_vector a, t_vector b);
t_vector		draw_vector_sub(t_vector a, t_vector b);
t_vector		draw_vector_inv(t_vector a);
float			draw_vector_dot(t_vector a, t_vector b);
t_vector		draw_vector_mult(t_vector a, t_vector b);

float			draw_v4f_dot(t_v4f a, t_v4f b);
double			draw_v4d_dot(t_v4d a, t_v4d b);
t_v4d			draw_v4d_inv(t_v4d v);
t_v4f			draw_v4f_inv(t_v4f v);
t_v4d			draw_v4d_mult(t_v4d a, t_v4d b);
t_v4f			draw_v4f_mult(t_v4f a, t_v4f b);

t_line			draw_make_line(int x1, int y1, int x2, int y2);
t_rect			draw_make_rect(int x1, int y1, int x2, int y2);
t_circle		draw_make_circle(int x1, int y1, int radius);
t_point			draw_make_px(int x, int y);

void			draw_putpoint(t_point *point);
void			draw_rect(t_draw *d, t_rect rect, unsigned int color);
void			draw_rect_fill(t_draw *d, t_rect rect,
	unsigned int color);
void			draw_rect_mist(t_draw *d, const t_rect rect,
	size_t pixels, unsigned int color);
void			draw_line(t_draw *d, t_line line, unsigned int color);
void			draw_circle(t_draw *d, const t_circle *circle,
		unsigned int color);
void			draw_perimeter(t_draw *d, const t_point *tab, size_t size,
		unsigned int color);
void			draw_pxtab(t_draw *d, t_point *tab, size_t size,
		unsigned int color);
t_point			*draw_move_pxlist(t_point *tab, size_t size, int x, int y);
t_point			*draw_matrix_topxtab(t_point *tab, size_t size, t_matrix *t);
t_point			draw_raster_px(t_vector v, t_matrix *transform);
t_vector		draw_matrix_multiply(t_vector point, const t_matrix *t);
t_line			draw_raster_line(t_vector v1, t_vector v2, t_matrix *transform);
t_rgb			draw_color_hsv(int t, float s, float v);
int				draw_color_rgb2int(t_rgb *rgb);
void			draw_setcolor(t_draw *d, unsigned int color);

/*
** pixels manipulations
*/

void			draw_reset_surface(SDL_Surface *surface, unsigned int color);
void			draw_px(t_draw *d, const t_point px);
void			draw_pxc(t_draw *d, const t_point px, unsigned int color);
unsigned int	draw_getpxs(SDL_Surface *surface, t_point px);
unsigned int	draw_getpx(t_draw *d, t_point px);
void			draw_pxi(unsigned int *pixels, const t_point px,
		const unsigned int pitch, const unsigned int color);

int				draw_init_openglcontext(t_draw *d);
int				draw_init(t_draw *d, t_point geometry, const char *title);
t_point			draw_getgeometry(SDL_Window *window);
void			*draw_pixelsconvert(unsigned int *dest, const void *src,
		int bpp, size_t size);

void			draw_putvector(t_vector v, unsigned int p);
void			draw_putv4f(t_v4f v, unsigned int p);
void			draw_putv4d(t_v4d v, unsigned int p);
void			draw_putm4(t_m4 m, unsigned int p);

#endif
