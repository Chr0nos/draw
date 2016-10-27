# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/29 12:33:23 by snicolet          #+#    #+#              #
#*   Updated: 2016/10/27 04:06:48 by snicolet         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

#OPSYS=$(shell uname -s)
OPSYS=Darwin
CC=clang
FLAGS=-Wall -Wextra -Werror -Weverything -Ofast -Wno-padded -Wno-reserved-id-macro -Wno-documentation-unknown-command -Wno-documentation
LIBFT=../libft/
INC=-I $(LIBFT) -I../ -I./headers -I/usr/local/include
NAME=libdraw.a
OBJ=draw_line.o \
	draw_rect.o draw_rect_fill.o draw_rect_mist.o \
	draw_circle.o \
	draw_px.o \
	draw_make_line.o \
	draw_make_rect.o \
	draw_make_circle.o \
	draw_make_px.o \
	draw_putpoint.o \
	draw_perimeter.o \
	draw_move_pxlist.o \
	draw_matrix_topxtab.o \
	draw_pxtab.o \
	draw_raster_px.o draw_raster_line.o \
	draw_colors.o \
	draw_init.o \
	draw_getgeometry.o \
	draw_reset_surface.o \
	draw_pixelconvert.o \
	draw_px_surface.o \
	draw_convert_v4.o \
	draw_swap.o \
	draw_quit.o \
	draw_color_lerp.o \
	draw_blitsurface.o \
	draw_make_surface.o \
	draw_perlin.o \
	draw_suv.o \
	geo/geo_mk_mat.o \
	geo/geo_mk_projection.o \
	geo/geo_mkv.o \
	geo/geo_mult_mat.o \
	geo/geo_mult.o \
	geo/geo_cross.o \
	geo/geo_apply.o \
	geo/geo_trans.o \
	geo/geo_mk_rot.o \
	geo/geo_add.o geo/geo_sub.o geo/geo_mult.o geo/geo_dot.o \
	geo/geo_inv.o geo/geo_norm.o \
	geo/geo_mk4_mat.o \
	geo/geo_mk4_rot.o \
	geo/geo_dist.o \
	geo/geo_putvector.o \
	geo/geo_len.o \
	geo/geo_inv_mat.o \
	geo/geo_perlin.o \
	geo/geo_div.o \
	geo/geo_mix.o \
	geo/geo_clamp.o \
	geo/geo_smoothstep.o \
	geo/geo_barycentric_coordinates.o \
	geo/geo_floatcmp.o \
	geo/geo_fract.o \
	geo/geo_min.o \
	geo/geo_max.o \
	blend/to_rgb.o \
	blend/blend_add.o \
	blend/blend_sub.o \
	blend/blend_normal.o \
	blend/blend_overlay.o \
	blend/blend_darken.o \
	blend/blend_lighten.o \
	blend/blend_multiply.o

ifeq ($(OPSYS), Darwin)
	SDLLIB=/Library/Frameworks/SDL2.framework/Versions/A/Headers/SDL.h
	SDLHERE=$(shell test -f $(SDLLIB))
	ifeq ("$(wildcard $(SDLLIB))", "")
		INC += -I ~/.brew/include/
	endif
endif

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.c
	$(CC) -c $< -o $@ $(FLAGS) $(INC)

.PHONY: re fclean clean
