# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/25 23:28:11 by bedarenn          #+#    #+#              #
#    Updated: 2024/01/23 15:37:58 by bedarenn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

DIR_GNL = gnl/

DIR_SRCS = srcs/
DIR_OBJS = objs/
DIR_INCL = headers/
DIR_LIBS = libs/
DIR_WATI = $(DIR_SRCS)libwati/

GNL = \
	get_next_line.c \
	new_buffer.c \
	manage_buffer.c \
	read_file.c \
	get_file.c

SRCS = \
	$(addprefix $(DIR_GNL), $(GNL)) \
	main.c \
	init_var.c \
	struct_assessor.c \
	get_parts.c \
	get_parts_tools.c \
	get_map.c \
	get_map_tools.c \
	get_color.c \
	custom_color.c \
	print_line.c \
	print_map.c \
	get_matrix.c \
	multiply_matrix.c \
	key_hook.c

OBJS = $(addprefix $(DIR_OBJS), $(SRCS:%.c=%.o))

CFLAGS = -Wall -Wextra -Werror #-g
IFLAGS = -I$(DIR_INCL)
LFLAGS = -L$(DIR_LIBS) -lmlx -lXext -lX11 -lwati -lm

NAME = fdf

all: libwati $(NAME)

$(NAME): $(OBJS)
	$(CC) $^ $(LFLAGS) -o $@

$(DIR_OBJS)%.o: $(DIR_SRCS)%.c
	@mkdir -p $(DIR_OBJS) $(DIR_OBJS)/$(DIR_GNL)
	$(CC) $(CFLAGS) $(IFLAGS) -c $^ -o $@ 

clean:
	rm -rf $(DIR_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

libwati:
	make -C $(DIR_WATI)
	@cp $(DIR_WATI)libwati.h $(DIR_INCL)
	@cp $(DIR_WATI)libwati.a $(DIR_LIBS)

run: fclean
	$(CC) $(CFLAGS) $(IFLAGS) $(SRCS:%.c=$(DIR_SRCS)%.c) $(LFLAGS) -o $(NAME)

.PHONY: all clean fclean re