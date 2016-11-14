# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/29 12:33:23 by snicolet          #+#    #+#              #
#    Updated: 2016/11/14 22:38:44 by snicolet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#OPSYS=$(shell uname -s)
OPSYS=Darwin
CC=clang
FLAGS=-Wall -Wextra -Werror -Weverything -Ofast -Wno-padded -Wno-reserved-id-macro -Wno-documentation-unknown-command -Wno-documentation
LIBFT=../libft/
INC=-I $(LIBFT) -I../ -I./headers -I/usr/local/include
NAME=libdraw.a

BUILD_DIR=build

DRAW_DIR=draw
DRAW=draw_line.c \
	draw_rect.c \
	draw_rect_fill.c \
	draw_rect_mist.c \
	draw_circle.c \
	draw_px.c \
	draw_make_line.c \
	draw_make_rect.c \
	draw_make_circle.c \
	draw_make_px.c \
	draw_putpoint.c \
	draw_perimeter.c \
	draw_move_pxlist.c \
	draw_matrix_topxtab.c \
	draw_pxtab.c \
	draw_raster_px.c draw_raster_line.c \
	draw_colors.c \
	draw_init.c \
	draw_getgeometry.c \
	draw_reset_surface.c \
	draw_pixelconvert.c \
	draw_px_surface.c \
	draw_convert_v4.c \
	draw_swap.c \
	draw_quit.c \
	draw_color_lerp.c \
	draw_blitsurface.c \
	draw_make_surface.c \
	draw_perlin.c \
	draw_suv.c

GEO_DIR=geo
GEO=geo_mk_mat.c \
	geo_mk_projection.c \
	geo_mkv.c \
	geo_mult_mat.c \
	geo_mult.c \
	geo_cross.c \
	geo_apply.c \
	geo_trans.c \
	geo_mk_rot.c \
	geo_add.c \
	geo_sub.c \
	geo_mult.c \
	geo_dot.c \
	geo_inv.c geo_norm.c \
	geo_mk4_mat.c \
	geo_mk4_rot.c \
	geo_dist.c \
	geo_putvector.c \
	geo_len.c \
	geo_inv_mat.c \
	geo_perlin.c \
	geo_div.c \
	geo_mix.c \
	geo_clamp.c \
	geo_smoothstep.c \
	geo_barycentric_coordinates.c \
	geo_floatcmp.c \
	geo_fract.c \
	geo_min.c \
	geo_max.c \
	geo_center.c \
	geo_mk4_projection.c \
	geo_quat_rot.c \
	geo_quat_mult.c \
	geo_quat_inv.c \
	geo_quat_tomatrix.c \
	geo_quat_identity.c

BLEND_DIR=blend
BLEND=to_rgb.c \
	blend_add.c \
	blend_sub.c \
	blend_normal.c \
	blend_overlay.c \
	blend_darken.c \
	blend_lighten.c \
	blend_multiply.c

ALLDIR=$(BUILD_DIR)/$(BUILD_DIR) \
	$(BUILD_DIR)/$(DRAW_DIR) \
	$(BUILD_DIR)/$(BLEND_DIR) \
	$(BUILD_DIR)/$(GEO_DIR)

ALLOBJS=$(DRAW:%.c=$(BUILD_DIR)/$(DRAW_DIR)/%.o) \
		$(BLEND:%.c=$(BUILD_DIR)/$(BLEND_DIR)/%.o) \
		$(GEO:%.c=$(BUILD_DIR)/$(GEO_DIR)/%.o)

ALLSRCS=$(DRAW:%.c=$(DRAW_DIR)/%.c) \
	$(BLEND:%.c=$(BLEND_DIR)/%.c) \
	$(GEO:%.c=$(GEO_DIR)/%.c)

ifeq ($(OPSYS), Darwin)
	SDLLIB=/Library/Frameworks/SDL2.framework/Versions/A/Headers/SDL.h
	SDLHERE=$(shell test -f $(SDLLIB))
	ifeq ("$(wildcard $(SDLLIB))", "")
		INC += -I ~/.brew/include/
	endif
endif

all: $(NAME)

$(NAME): $(ALLDIR) $(ALLOBJS)
	$(AR) rc $(NAME) $(ALLOBJS)
	ranlib $(NAME)

$(ALLDIR):
	mkdir -p $@

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(BUILD_DIR)/%.o: %.c
	$(CC) -c $< -o $@ $(FLAGS) $(INC)

norminette:
	norminette $(ALLSRCS)

dirs: $(ALLDIR)
	@echo Done.

.PHONY: re fclean clean
