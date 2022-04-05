# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ereginia <ereginia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/12 17:20:51 by ereginia          #+#    #+#              #
#    Updated: 2022/04/05 11:55:45 by ereginia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = so_long

LIBFTNAME = libft.a

LIBFTPATH = libft/

CFLAGS = -Werror -Wall -Wextra

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

SRC_DIR = srcs/

SRC_BONUS_DIR = srcs_bonus/

SRCS = so_long.c ft_map_checker.c ft_map_parser.c ft_get_fd.c\
		get_next_line.c ft_mov_handler.c ft_shell_out.c ft_render.c\
		ft_destroy.c

SRCS_B = so_long_bonus.c ft_map_checker_bonus.c ft_map_parser_bonus.c ft_get_fd_bonus.c\
		get_next_line_bonus.c ft_mov_handler_bonus.c ft_map_out_bonus.c ft_render_bonus.c\
		ft_destroy_bonus.c ft_anim_bonus.c

OBJS = ${addprefix ${SRC_DIR}, ${SRCS:.c=.o}}

OBJS_B = ${addprefix ${SRC_BONUS_DIR}, ${SRCS_B:.c=.o}}

HEADER = so_long.h

HEADER_B = so_long_bonus.h

${NAME}: ${OBJS}
	make -C ${LIBFTPATH}
	$(CC) ${CFLAGS} ${MLXFLAGS} -I $(LIBFTPATH) ${OBJS} $(LIBFTPATH)${LIBFTNAME} -o ${NAME}

all: $(NAME)

%.o: %.c	$(HEADER) $(HEADER_B)
			$(CC) -I$(LIBFTPATH) -c $(CFLAGS) -o $@ $<

bonus: $(NAME) ${OBJS_B} ${HEADER_B}
	make -C ${LIBFTPATH}
	${CC} ${CFLAGS} ${MLXFLAGS} -I$(LIBFTPATH) ${OBJS_B} $(LIBFTPATH)${LIBFTNAME} -o ${NAME}

clean:
	make clean -C ${LIBFTPATH}
	rm -rf *.o

fclean: clean
	make fclean -C ${LIBFTPATH}
	rm -f $(LIBFTNAME) ${OBJS} ${OBJS_B} $(NAME)

re: fclean ${NAME}

PHONY: all bonus clean fclean re