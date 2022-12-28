# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aanghel <aanghel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 16:38:58 by aanghel           #+#    #+#              #
#    Updated: 2022/12/28 16:44:10 by aanghel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minirt

SRCS = 

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