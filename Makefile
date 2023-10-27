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

# need to make it so we stop creating new nodes in push operations
# this can be done by creating: 
#ft_cdllinsert_after(t_cdllist *node, t_cdllist *toinsert)
#ft_cdllinsert_before(t_cdllist *node, t_cdllist *toinsert)
#ft_cdllinsert_between(t_cdllist *prev, t_cdllist *next, t_cdllist *toinsert)

# Behaviour variables
PRINTSTACK := 0
PRINTERROR := 0
SILENT := 0

# Used by cross-compatibility
UNAME := $(shell uname)

# Compiler variables
CC := gcc
CCARGS := -o3 -L. -lft -Wall -Werror -Wextra

# Some args
VGARG := --log-file=valgrind.txt --leak-check=full --show-leak-kinds=all --track-origins=yes -s
PSARG := 1 2 3 4 5 6 7 8 9 10
PSARG := 231 789 123 567 345 925 456 678 234
PSARG := 789 123 567 345 456 678 234
PSARG := 789 -123 -567 345 234 456 -678

# Output names
PS := push_swap
CCHECKER := checker

# Sources
SRCS := srcs/parsing.c srcs/ops_swap.c srcs/ops_push.c srcs/ops_rot.c srcs/debug.c srcs/init.c srcs/sorting.c srcs/issorted.c srcs/suicide.c
INCLS := includes/pushswap.h

# Linux-OSX cross-compatibility
ifeq ($(UNAME), Linux)
	CHECKER := checker_linux
	CHECKERURL := https://cdn.intra.42.fr/document/document/14174/checker_linux
endif
ifeq ($(UNAME), Darwin)
	CHECKER := checker_Mac
	CHECKERURL := https://cdn.intra.42.fr/document/document/14173/checker_Mac
endif

# Push_swap program
$(PS) : libft.a push_swap.c $(SRCS) $(INCLS)
	$(CC) push_swap.c -D PRINTERROR=$(PRINTERROR) -D PRINTSTACK=$(PRINTSTACK) -D SILENT=$(SILENT) $(SRCS) $(CCARGS) -o $(PS)

# Checker program
$(CCHECKER) : libft.a checker.c $(SRCS) $(INCLS)
	$(CC) checker.c -D PRINTERROR=$(PRINTERROR) -D PRINTSTACK=$(PRINTSTACK) -D SILENT=$(SILENT) $(SRCS) $(CCARGS) -o $(CCHECKER)

# Compile main program and run it
exe : $(PS) $(CCHECKER)
	./$(PS) $(PSARG) | ./$(CCHECKER) $(PSARG)

# Dependencies
dep : libft.a
	
# Libft compilation
libft.a : libft/Makefile
	cd libft && $(MAKE) -j16
	cp libft/libft.a .

# Get libft submodule from my github
libft/Makefile :
	git submodule update --init libft

# Partial clean
clean :
	cd libft && $(MAKE) clean

# Full clean
fclean : clean
	rm -f $(PS) libft.a ft_checker $(CCHECKER) 
	rm -rf psv push_swap_tester
	cd libft && $(MAKE) fclean

# All
all : $(PS) $(CCHECKER) ft_checker psv/build/bin/visualizer push_swap_tester/complexity

# Recompile
re : fclean all

# Automated valgrind run
vg : ${PS}
	valgrind $(VGARG) ./$(PS) $(PSARG)

# Checker provided by intra cdn
ft_checker :
	wget $(CHECKERURL)
	chmod +x $(CHECKER)
	mv $(CHECKER) ft_checker

# PUSH_SWAP COMPLEXITY TESTER
push_swap_tester :
	git clone https://github.com/SimonCROS/push_swap_tester.git
push_swap_tester/complexity : push_swap_tester
	cd push_swap_tester && $(MAKE) en
complexity : $(PS) $(CCHECKER) push_swap_tester/complexity
	./push_swap_tester/complexity 100 100 1080 ./checker

# PUSH_SWAP_VISUALIZER
psv :
	git clone https://github.com/o-reo/push_swap_visualizer.git psv
psv/build/bin/visualizer : psv
	mkdir psv/build
	cd psv/build && cmake .. && $(MAKE)
visualizer : psv/build/bin/visualizer
	 ./psv/build/bin/visualizer

# PHONY
.PHONY : complexity checker_Mac checker_linux vg re all fclean visualizer clean dep exe