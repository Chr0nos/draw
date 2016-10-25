/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 13:27:50 by snicolet          #+#    #+#             */
/*   Updated: 2016/08/23 08:40:15 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H
# define ABS(x) ((x < 0) ? -x : x)
# include <string.h>
# include <SDL2/SDL.h>
# include "geo.h"
# include "colors.h"
# include "tpoint.h"
# include "drawsdl.h"
# include "t_v2.h"
# include "t_v3.h"
# include "t_v4.h"

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

typedef struct	s_area
{
	t_v2i		start;
	t_v2i		end;
}				t_area;

typedef struct	s_line
{
	t_v2i		start;
	t_v2i		end;
	int			dx;
	int			dy;
}				t_line;

typedef t_area	t_rect;
typedef struct	s_circle
{
	t_v2i		center;
	int			radius;
}				t_circle;

t_v4f			draw_convert_v4d_to_v4f(t_v4d v);
void			draw_swap(double *a, double *b);

t_line			draw_make_line(int x1, int y1, int x2, int y2);
t_rect			draw_make_rect(int x1, int y1, int x2, int y2);
t_circle		draw_make_circle(int x1, int y1, int radius);
t_v2i			draw_make_px(int x, int y);

void			draw_putpoint(t_v2i *point);
void			draw_rect(t_draw *d, t_rect rect, unsigned int color);
void			draw_rect_fill(t_draw *d, t_rect rect,
	unsigned int color);
void			draw_rect_mist(t_draw *d, const t_rect rect,
	size_t pixels, unsigned int color);
void			draw_line(t_draw *d, t_line line, unsigned int color);
void			draw_circle(t_draw *d, const t_circle *circle,
		unsigned int color);
void			draw_perimeter(t_draw *d, const t_v2i *tab, size_t size,
		unsigned int color);
void			draw_pxtab(t_draw *d, t_v2i *tab, size_t size,
		unsigned int color);
t_v2i			*draw_move_pxlist(t_v2i *tab, size_t size, int x, int y);
t_v2i			*draw_matrix_topxtab(t_v2i *tab, size_t size, t_matrix *t);
t_v2i			draw_raster_px(t_v3f v, t_matrix *transform);
t_line			draw_raster_line(t_v3f v1, t_v3f v2, t_matrix *transform);
unsigned int	draw_color_hsv(int t, float s, float v);
int				draw_color_rgb2int(t_rgb *rgb);
void			draw_setcolor(t_draw *d, unsigned int color);

/*
** pixels manipulations
*/

void			draw_reset_surface(SDL_Surface *surface, unsigned int color);
void			draw_px(t_draw *d, const t_v2i px);
void			draw_pxc(t_draw *d, const t_v2i px, unsigned int color);
unsigned int	draw_getpxs(SDL_Surface *surface, t_v2i px);
unsigned int	draw_getpx(t_draw *d, t_v2i px);
void			draw_pxi(unsigned int *pixels, const t_v2i px,
		const unsigned int pitch, const unsigned int color);

int				draw_init_openglcontext(t_draw *d);
int				draw_init(t_draw *d, t_v2i geometry, const char *title);
t_v2i			draw_getgeometry(SDL_Window *window);
void			*draw_pixelsconvert(unsigned int *dest, const void *src,
		int bpp, size_t size);

void			draw_quit(t_draw *d);

unsigned int	draw_color_lerp(unsigned int a, unsigned int b, float pc);
unsigned int	draw_color_lerp_alpha(unsigned int a, unsigned int b, float pc);
unsigned int	draw_color_lerp_max(unsigned int a, unsigned int b,
		unsigned int max, float pc);

void			draw_blitsurface(SDL_Surface *dest, SDL_Surface *src,
	t_v2i offset);
void			draw_blitsurface_opc(SDL_Surface *dest, SDL_Surface *src,
		t_v2i offset, const float opc);
SDL_Surface		*draw_make_surface(const t_v2i size);
void			draw_blitsurface_dbg_alpha(SDL_Surface *dest, SDL_Surface *src,
	t_v2i offset);
void			draw_blitsurface_blend(SDL_Surface *dest, SDL_Surface *src,
		t_v2i offset, unsigned int (*blend)(unsigned int, unsigned int));
void			draw_perlin(SDL_Surface *surface);
void			draw_perlin_aa(SDL_Surface *surface);
void			draw_perlin_alpha(SDL_Surface *surface, t_v2f zoom);
unsigned int	draw_suv(SDL_Surface *surface, t_v2f uv);
unsigned int	draw_suv_smooth(SDL_Surface *surface, t_v2f uv);

#endif
