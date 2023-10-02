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

# problems with push command when stack is 1 node long (prob come from delone)
SLEEP := 1

CC := gcc
CCARGS := -g3  -L. -lft -D SLEEP=$(SLEEP) #-Wall -Wextra -Werror

VGARG := --log-file=valgrind.txt --leak-check=full --show-leak-kinds=all --track-origins=yes -s
PSARG := 123 234 345 456 567 678 789

NAME := push_swap
SRCS := main.c srcs/parsing.c srcs/ops_swap.c srcs/ops_push.c srcs/ops_rot.c
INCLS := includes/pushswap.h

# main program
$(NAME) : libft.a $(SRCS) $(INCLS)
	$(CC) $(SRCS) $(CCARGS) -o $(NAME)

# compile main program and run it
exe : $(NAME)
	./$(NAME) $(PSARG)

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
	rm -f $(NAME) libft.a
	cd libft && $(MAKE) fclean

all : $(NAME)

# recompile
re : fclean all

vg : ${NAME}
	valgrind $(VGARG) ./$(NAME) $(PSARG)