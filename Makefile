# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/29 12:33:23 by snicolet          #+#    #+#              #
#    Updated: 2016/06/17 17:20:29 by snicolet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#OPSYS=$(shell uname -s)
OPSYS=Darwin
CC=clang
FLAGS=-Wall -Wextra -Werror -Weverything -Ofast -Wno-padded -Wno-reserved-id-macro -Wno-documentation-unknown-command -Wno-documentation
LIBFT=../libft/
INC=-I $(LIBFT) -I../ -I./headers
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
	draw_make_matrix.o \
	draw_make_matrix_projection.o \
	draw_make_vector.o \
	draw_matrix_multiply.o \
	draw_matrix_multiply_matrix.o \
	draw_matrix_topxtab.o \
	draw_pxtab.o \
	draw_raster_px.o draw_raster_line.o \
	draw_vector_transform.o \
	draw_colors.o \
	draw_init.o \
	draw_getgeometry.o \
	draw_reset_surface.o \
	draw_pixelconvert.o \
	draw_px_surface.o \
	draw_make_matrix_rot.o \
	draw_vector_add.o draw_vector_sub.o draw_vector_mult.o draw_vector_dot.o \
	draw_vector_inv.o draw_vector_norm.o \
	draw_make_matrix_m4.o \
	draw_putvector.o \
	draw_make_matrix_rot_m4.o \
	draw_convert_v4.o \
	draw_swap.o \
	draw_quit.o \
	draw_vector_dist.o \
	draw_color_lerp.o

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
	$(CC) -c $< $(FLAGS) $(INC)

.PHONY: re fclean clean
