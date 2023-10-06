#!/bin/bash
#make -s fclean
make -s dep
make -j4 push_swap
make -j4 SILENT=1 PRINTSTACK=1 checker

#printf "\ntest 1: (0->250)*25\n"
#RAND=$(python -c 'import random as r; print(*r.sample(range(0, 250), 25), sep=" ");')
#echo ${RAND}
#./push_swap ${RAND} | ./checker ${RAND}
#printf "\n"

printf "\ntest 2: (-125->125)*25\n"
RAND=$(python -c 'import random as r; print(*r.sample(range(-125, 125), 25), sep=" ");')
echo ${RAND}
./push_swap ${RAND} | ./checker ${RAND}
printf "\n"

#RAND=$(python -c 'import random as r; print(*r.sample(range(-250, 0), 25), sep=" ");')
#./push_swap ${RAND}