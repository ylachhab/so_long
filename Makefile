# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylachhab <ylachhab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 09:24:19 by ylachhab          #+#    #+#              #
#    Updated: 2023/02/14 09:35:09 by ylachhab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

FLAGS  = -Wall -Wextra -Werror

CC = cc

RM = rm -f

SRC  =	check_map.c\
		ft_parsing.c\
		flood_fill.c\
		ft_draw.c\
		ft_func_utils.c\
		ft_key_move.c\
		ft_move.c\
		so.long.c\
		stock_map.c\
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \

OBJS = $(SRC:.c=.o)

all: $(NAME)

printf/libftprintf.a :
	make -C printf all

%.o: %.c so_long.h
	$(CC) $(FLAGS) -c $< -o $@

$(NAME) : printf/libftprintf.a $(OBJS)
	$(CC) $(FLAGS) $(OBJS) printf/libftprintf.a -lmlx -framework OpenGl -framework Appkit -o $(NAME)

clean:
	$(RM) $(OBJS)
	make -C printf clean

fclean: clean
	$(RM) $(NAME)
	make -C printf fclean

re: fclean all