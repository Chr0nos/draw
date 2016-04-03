# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/29 12:33:23 by snicolet          #+#    #+#              #
#    Updated: 2016/04/03 22:00:21 by snicolet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=clang
FLAGS=-Wall -Wextra -Werror -Weverything -Ofast -Wno-padded -Wno-reserved-id-macro -Wno-documentation-unknown-command -Wno-documentation
LIBFT=../libft/
SDL=~/.brew/include/
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
	draw_colors.o

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
	$(CC) -c $< $(FLAGS) -I $(LIBFT) -I../ -I $(SDL)

.PHONY: re fclean clean
