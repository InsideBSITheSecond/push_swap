# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llegrand <llegrand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/14 15:50:01 by llegrand          #+#    #+#              #
#    Updated: 2023/09/14 15:50:01 by llegrand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc
CCARGS := -g3  -L. -lft #-Wall -Wextra -Werror

NAME := push_swap
SRCS := main.c srcs/parsing.c
INCLS := includes/pushswap.h

# main program
$(NAME) : libft.a $(SRCS) $(INCLS)
	$(CC) $(SRCS) $(CCARGS) -o $(NAME)

# compile main program and run it
exe : $(NAME)
	./$(NAME) 0 4 8 15 16 23 42 69 420

dep : libft.a
	
# libft compilation
libft.a : libft/Makefile
	cd libft && $(MAKE) -j16
	cp libft/libft.a .

# get libft submodule from my github
libft/Makefile :
	git submodule update --init libft

# partial clean
clean :
	cd libft && $(MAKE) clean

# full clean
fclean : clean
	rm -f $(NAME) libft.a lib$(MLX).a
	cd libft && $(MAKE) fclean

all : $(NAME)

# recompile
re : fclean all
