# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snicolet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/29 12:33:23 by snicolet          #+#    #+#              #
#*   Updated: 2016/01/14 11:21:02 by snicolet         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

CC=clang
FLAGS=-Wall -Wextra -Werror -Weverything
LIBFT=../libft/
MLX=../minilibx_macos
NAME=libdraw.a
OBJ=draw_line.o \
	draw_rect.o draw_rect_fill.o draw_rect_mist.o draw_rect_invert.o \
	draw_circle.o \
	draw_px.o draw_get_px.o \
	draw_new_image.o \
	draw_init.o \
	draw_flush_image.o \
	draw_make_line.o \
	draw_make_rect.o \
	draw_make_circle.o \
	draw_make_px.o \
	draw_putpoint.o \
	draw_reset_image.o \
	draw_loop.o \
	draw_clear.o \
	draw_perimeter.o \
	draw_sethook.o \
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
	draw_colors.o

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(MLX)
	$(AR) rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ) $(MLXOBJ)

fclean: clean
	rm -f $(NAME)
	make -C $(MLX) clean
	rm -f $(MLX)/libmlx.a

re: fclean all

%.o: %.c
	$(CC) -c $< $(FLAGS) -I $(MLX) -I $(LIBFT) -I../

.PHONY: re fclean clean
