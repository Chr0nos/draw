/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geo.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qloubier <qloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 19:19:23 by qloubier          #+#    #+#             */
/*   Updated: 2016/08/22 17:00:04 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEO_H
# define GEO_H

# include <math.h>
# include "t_v2.h"
# include "t_v3.h"
# include "t_v4.h"
# include "tperspective.h"

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

t_matrix		geo_mk_rotx(t_vector pos, float rad, t_vector scale);
t_matrix		geo_mk_roty(t_vector pos, float rad, t_vector scale);
t_matrix		geo_mk_rotz(t_vector pos, float rad, t_vector scale);
t_matrix		geo_mk_perspective(t_perspective s, t_vector c);
t_matrix		geo_mk_iso(int x, int y, int w, int h);
t_matrix		geo_mk_ortho(t_vector s, t_vector c);
t_matrix		geo_mult_m3(t_matrix m1, const t_matrix *m2);
t_matrix		geo_mk_identity(void);
t_matrix		geo_mk_rotxyz(t_vector axes, t_vector scale,
	t_vector offset);

t_m4			geo_mk4_identity(void);
t_m4			geo_mk4_iso(int x, int y, int w, int h);
t_m4			geo_mk4_ortho(const t_v4d s, const t_v4d c);
t_v4d			geo_m4trans(t_v4d v, const t_m4 *m);
t_m4			geo_mult_m4(t_m4 m1, const t_m4 *m2);
t_m4			geo_inv_m4(const t_m4 m);
t_m4			geo_mk4_rotx(t_v4d pos, double rad, t_v4d scale);
t_m4			geo_mk4_roty(t_v4d pos, double rad, t_v4d scale);
t_m4			geo_mk4_rotz(t_v4d pos, double rad, t_v4d scale);
t_m4			geo_mk4_rot(t_v4d axis, double rad, t_v4d pos,
				t_v4d scale);
t_m4			geo_mk4_euler(t_v4d euler, t_v4d pos, t_v4d scale);
t_m4			geo_mk4_rotxyz(t_v4d axes, t_v4d scale,
	t_v4d offset);
t_v4f			geo_addv4f(t_v4f a, t_v4f b);
t_v4d			geo_addv4(t_v4d a, t_v4d b);
t_v4f			geo_normv4f(t_v4f v);
t_v4d			geo_normv4(t_v4d v);
t_v4d			geo_apply_m4(t_v4d pt, const t_m4 *m);
t_matrix		geo_mk_rot_x(double rad);
t_matrix		geo_mk_rot_y(double rad);
t_matrix		geo_mk_rot_z(double rad);

t_vector		geo_mkv(float x, float y, float z);
t_vector		geo_trans(t_vector v, const t_matrix *m);
t_vector		geo_addv(t_vector a, t_vector b);
t_vector		geo_subv(t_vector a, t_vector b);
t_vector		geo_invv(t_vector a);
float			geo_dotv(t_vector a, t_vector b);
t_vector		geo_multv(t_vector a, t_vector b);
t_vector		geo_normv(t_vector v);

float			geo_dotv4f(t_v4f a, t_v4f b);
double			geo_dotv4(t_v4d a, t_v4d b);
t_v4d			geo_invv4(t_v4d v);
t_v4f			geo_invv4f(t_v4f v);
t_v4d			geo_multv4(t_v4d a, t_v4d b);
t_v4f			geo_multv4f(t_v4f a, t_v4f b);
t_v4d			geo_subv4(t_v4d a, t_v4d b);
t_v4f			geo_subv4f(t_v4f a, t_v4f b);
double			geo_distv4(const t_v4d a, const t_v4d b);
double			geo_lenv4(t_v4d v);
t_v4d			geo_dtov4d(double x);
t_vector		geo_apply(t_vector point, const t_matrix *t);
t_v4d			geo_crossv4(t_v4d a, t_v4d b);

void			geo_putvector(t_vector v, unsigned int p);
void			geo_putv4f(t_v4f v, unsigned int p);
void			geo_putv4d(t_v4d v, unsigned int p);
void			geo_putm4(t_m4 m, unsigned int p);
t_v2f			geo_v2f_mult(t_v2f px, const float x);
t_v2f			geo_v2f_div(t_v2f px, const float x);
float			geo_dotv2f(t_v2f a, t_v2f b);
t_v2f			geo_addv2f(t_v2f a, t_v2f b);
float			geo_perlin(t_v2f px);
t_v4d			geo_barycentric_coordinates(t_v4d a, t_v4d b, t_v4d c, t_v4d p);

t_v2f			geo_smoothstep(t_v2f a, t_v2f b, t_v2f x);
float			geo_clamp(float x, float min, float max);
float			geo_mix(float a, float b, float pc);
int				geo_floatcmp(float a, float b);

#endif
