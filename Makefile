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

#int overflow
#we dont check illegal args if argc == 2

# need to support argc == 2 
# need to make it so we stop creating new nodes in push operations
# this can be done by creating: 
#ft_cdllinsert_after(t_cdllist *node, t_cdllist *toinsert)
#ft_cdllinsert_before(t_cdllist *node, t_cdllist *toinsert)
#ft_cdllinsert_between(t_cdllist *prev, t_cdllist *next, t_cdllist *toinsert)

# list order ?
# triple check parsing
# sometimes sorting is fucked
# compare my checker output the the provided one
# &&&&&&& COMBINE THEM IN GIT ACTIONS

PRINTSTACK := 0
SILENT := 0
UNAME := $(shell uname)

CC := gcc
CCARGS := -w -g3  -L. -lft -D PRINTSTACK=$(PRINTSTACK) -D SILENT=$(SILENT) #-Wall -Wextra -Werror

VGARG := --log-file=valgrind.txt --leak-check=full --show-leak-kinds=all --track-origins=yes -s
PSARG := 1 2 3 4 5 6 7 8 9 10
PSARG := 231 789 123 567 345 925 456 678 234
PSARG := 789 123 567 345 456 678 234
PSARG := 789 -123 -567 345 234 456 -678

PS := push_swap
CCHECKER := checker
SRCS := srcs/parsing.c srcs/ops_swap.c srcs/ops_push.c srcs/ops_rot.c srcs/debug.c srcs/init.c srcs/putnbr_base.c srcs/sorting.c srcs/issorted.c srcs/suicide.c
INCLS := includes/pushswap.h

ifeq ($(UNAME), Linux)
	CHECKER := checker_linux
endif
ifeq ($(UNAME), Darwin)
	CHECKER := checker_mac
endif


# main program
$(PS) : libft.a push_swap.c $(SRCS) $(INCLS)
	$(CC) push_swap.c $(SRCS) $(CCARGS) -o $(PS)

$(CCHECKER) : libft.a checker.c $(SRCS) $(INCLS)
	$(CC) checker.c $(SRCS) $(CCARGS) -o $(CCHECKER)

# compile main program and run it
exe : $(PS) $(CCHECKER)
	./$(PS) $(PSARG) | ./$(CCHECKER) $(PSARG)

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

vis :
	git clone https://github.com/o-reo/push_swap_visualizer.git psv
	mkdir psv/build
	cd psv/build && cmake .. && $(MAKE) && ./bin/visualizer

# full clean
fclean : clean
	rm -f $(PS) libft.a $(CHECKER) $(CCHECKER)
	cd libft && $(MAKE) fclean

all : $(PS) $(CCHECKER)

# recompile
re : fclean all

vg : ${PS}
	valgrind $(VGARG) ./$(NAME) $(PSARG)

ft_checker : $(CHECKER) $(PS)
	./$(PS) $(PSARG) | ./$(CHECKER) $(PSARG)

checker_linux :
	wget https://cdn.intra.42.fr/document/document/14174/checker_linux
	chmod +x $(CHECKER)

checker_mac :
	wget https://cdn.intra.42.fr/document/document/14173/checker_Mac
	mv checker_Mac checker_mac
	chmod +x $(CHECKER)



rand :
	
