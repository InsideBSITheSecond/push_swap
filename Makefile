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

# need to support argc == 2 
# need to make it so we stop creating new nodes in push operations
# this can be done by creating: 
#ft_cdllinsert_after(t_cdllist *node, t_cdllist *toinsert)
#ft_cdllinsert_before(t_cdllist *node, t_cdllist *toinsert)
#ft_cdllinsert_between(t_cdllist *prev, t_cdllist *next, t_cdllist *toinsert)


SLEEP := 0
UNAME := $(shell uname)

CC := gcc
CCARGS := -g3  -L. -lft -D SLEEP=$(SLEEP) #-Wall -Wextra -Werror

VGARG := --log-file=valgrind.txt --leak-check=full --show-leak-kinds=all --track-origins=yes -s
PSARG := 1 2 3 4 5 6 7 8 9 10
PSARG := 231 789 123 567 345 925 456 678 234
PSARG := 789 123 567 345 456 678 234

NAME := push_swap
SRCS := main.c srcs/parsing.c srcs/ops_swap.c srcs/ops_push.c srcs/ops_rot.c srcs/debug.c srcs/init.c srcs/putnbr_base.c srcs/radix.c
INCLS := includes/pushswap.h

ifeq ($(UNAME), Linux)
	CHECKER := checker_linux
endif
ifeq ($(UNAME), Darwin)
	CHECKER := checker_mac
endif

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
	rm -rf psv
	rm -f $(CHECKER)

vis :
	git clone https://github.com/o-reo/push_swap_visualizer.git psv
	mkdir psv/build
	cd psv/build && cmake .. && $(MAKE) && ./bin/visualizer

# full clean
fclean : clean
	rm -f $(NAME) libft.a
	cd libft && $(MAKE) fclean

all : $(NAME)

# recompile
re : fclean all

vg : ${NAME}
	valgrind $(VGARG) ./$(NAME) $(PSARG)

test : run_tests.sh $(CHECKER)
	echo $(CHECKER)
	./run_tests.sh

check : $(CHECKER) $(NAME)
	./$(NAME) $(PSARG) | ./$(CHECKER) $(PSARG)

checker_linux :
	wget https://cdn.intra.42.fr/document/document/14174/checker_linux
	chmod +x $(CHECKER)

checker_mac :
	wget https://cdn.intra.42.fr/document/document/14173/checker_Mac
	mv checker_Mac checker_mac
	chmod +x $(CHECKER)