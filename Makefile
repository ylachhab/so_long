# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylachhab <ylachhab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 09:24:19 by ylachhab          #+#    #+#              #
#    Updated: 2023/02/18 01:34:07 by ylachhab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

NAME_B = so_long_bonus

FLAGS  = -Wall -Wextra -Werror

CC = cc

RM = rm -f

SRC  =	src/check_map.c \
		src/ft_parsing.c \
		src/flood_fill.c \
		src/ft_draw.c \
		src/ft_func_utils.c \
		src/ft_key_move.c \
		src/ft_move.c \
		src/so_long.c \
		src/stock_map.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c

SRC_B = bonus/check_map_bonus.c\
		bonus/ft_parsing_bonus.c\
		bonus/flood_fill_bonus.c\
		bonus/ft_draw_bonus.c\
		bonus/ft_animation_bonus.c\
		bonus/ft_func_utils_bonus.c\
		bonus/ft_func_utils_bonus2.c\
		bonus/ft_key_move_bonus.c\
		bonus/ft_move_bonus.c\
		bonus/so_long_bonus.c\
		bonus/stock_map_bonus.c\
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c

OBJS = $(SRC:.c=.o)

OBJB = $(SRC_B:.c=.o)

all: $(NAME)

printf/libftprintf.a :
	make -C printf all

src/%.o : src/%.c src/so_long.h
	$(CC) $(FLAGS) -c $< -o $@

gnl/%.o : gnl/%.c gnl/get_next_line.h
	$(CC) $(FLAGS) -c $< -o $@

bonus/%.o : bonus/%.c bonus/so_long_bonus.h
	$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJS) printf/libftprintf.a
	$(CC) $(FLAGS) $(OBJS) printf/libftprintf.a -lmlx -framework OpenGl -framework Appkit -o $(NAME)

bonus : all $(OBJB) printf/libftprintf.a
	$(CC) $(FLAGS) $(OBJB) printf/libftprintf.a -lmlx -framework OpenGl -framework Appkit -o $(NAME_B)

clean:
	$(RM) $(OBJS) $(OBJB)
	make -C printf clean

fclean: clean
	$(RM) $(NAME) $(NAME_B)
	make -C printf fclean

re: fclean all