# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcatapan <pcatapan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 16:38:58 by aanghel           #+#    #+#              #
#    Updated: 2022/12/28 19:07:25 by pcatapan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minirt

SRCS = src/*.c \

OBJS = $(SRC:%.c=%.o)

CC = gcc

FLAGS = #-Wall -Werror -Wextra

MLX = -l mlx -framework openGL -framework AppKit

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean: 
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re