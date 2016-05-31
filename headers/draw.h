/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 13:27:50 by snicolet          #+#    #+#             */
/*   Updated: 2016/05/31 01:47:16 by snicolet         ###   ########.fr       */
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
t_matrix		draw_make_matrix_iso(int x, int y, int w, int h);
t_matrix		draw_make_matrix_ortho(t_vector s, t_vector c);
t_matrix		draw_matrix_multiply_matrix(t_matrix m1, const t_matrix *m2);
t_matrix		draw_make_matrix_identity(void);
t_matrix		draw_matrix_multiply_axes(t_vector axes, t_vector scale,
	t_vector offset);

t_matrix		draw_make_matrix_rot_x(double rad);
t_matrix		draw_make_matrix_rot_y(double rad);
t_matrix		draw_make_matrix_rot_z(double rad);

t_vector		draw_make_vector(float x, float y, float z);
t_vector		draw_vector_transform(t_vector v, const t_matrix *m);
t_vector		draw_vector_add(t_vector a, t_vector b);
t_vector		draw_vector_sub(t_vector a, t_vector b);

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
t_v4f			draw_matrix_multiply_m4(t_v4f pt, const t_m4 *m);
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

int				draw_init(t_draw *d, t_point geometry, const char *title);
t_point			draw_getgeometry(SDL_Window *window);
void			*draw_pixelsconvert(unsigned int *dest, const void *src,
		int bpp, size_t size);

#endif
