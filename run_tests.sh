#!/bin/bash

perform_test() {
    local python_command="import random as r; print(*r.sample(range($1, $2), $3), sep=\" \");"
    local printf_string="\ntest 1: ($1->$2)*$3\n"

	printf "==================="
    printf "$printf_string"
    RAND=$(python3 -c "$python_command")
    ./push_swap ${RAND} | wc -l
    time ./push_swap ${RAND} | ./checker ${RAND}
	printf "==================="
}

make -s fclean
make -s dep
make -j4 push_swap
make -j4 SILENT=1 PRINTSTACK=0 checker
perform_test "$1" "$2" "$3"
