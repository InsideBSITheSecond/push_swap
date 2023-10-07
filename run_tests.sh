#!/bin/bash
make -s fclean
make -s dep
make -j4 push_swap
make -j4 SILENT=1 PRINTSTACK=0 checker

printf "\ntest 1: (0->250)*25\n"
RAND=$(python -c 'import random as r; print(*r.sample(range(0, 250), 25), sep=" ");')
#echo ${RAND}
./push_swap ${RAND} | wc -l
./push_swap ${RAND} | ./checker ${RAND}
printf "============="

printf "\ntest 2: (-125->125)*25\n"
RAND=$(python -c 'import random as r; print(*r.sample(range(-125, 125), 25), sep=" ");')
#echo ${RAND}
./push_swap ${RAND} | wc -l
./push_swap ${RAND} | ./checker ${RAND}
printf "============="

printf "\ntest 3: (-1250->1250)*250\n"
RAND=$(python -c 'import random as r; print(*r.sample(range(-1250, 1250), 250), sep=" ");')
#echo ${RAND}
./push_swap ${RAND} | wc -l
./push_swap ${RAND} | ./checker ${RAND}
printf "============="

printf "\ntest 4: (-12500->12500)*2500\n"
RAND=$(python -c 'import random as r; print(*r.sample(range(-12500, 12500), 2500), sep=" ");')
#echo ${RAND}
./push_swap ${RAND} | wc -l
./push_swap ${RAND} | ./checker ${RAND}
printf "============="