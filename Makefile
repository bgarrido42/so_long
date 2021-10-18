# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgarrido <marvin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/17 12:05:42 by bgarrido          #+#    #+#              #
#    Updated: 2021/10/13 15:30:30 by bgarrido         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.a

FILES =  main						\
		 utils						\
		 errors						\
		 map/map_creator			\
		 map/movements				\
		 map/movements2				\
		 map/event_handler			\
		 includes/gnl/get_next_line	\
		 includes/gnl/gnl_util		\

RM = rm -rf
CC = clang
CFLAGS = -Wall -Werror -Wextra 
#CFLAGS += -fsanitize=address -g3
FFLAGS = -framework OpenGL -framework AppKit

SRCS = $(addsuffix .c, $(FILES))
OBJS = $(addsuffix .o, $(FILES))

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(MAKE) -C ./mlx/
	mv ./mlx/libmlx.a .
	$(MAKE) -C ./includes/libft/
	$(CC) $(CFLAGS) $(OBJS) -L . -lmlx ./includes/libft/libft.a $(FFLAGS) -o so_long.a

clean:
	$(MAKE) -C ./mlx/ clean
	$(RM) $(OBJS)

all: $(NAME)

re: clean all

fclean: clean
	$(RM) $(NAME)
	$(RM) libmlx.a

.PHONY: all re clean fclean
