#!/bin/bash

perform_test() {
    local python_command="import random as r; print(*r.sample(range($1, $2), $3), sep=\" \");"

	echo "==================="
    echo "running test: ($1->$2)*$3"
    RAND=$(python3 -c "$python_command")
	echo "${RAND// / | }"
	OUT=$(./push_swap ${RAND})
	ARGN=$(echo "${RAND} " | wc -w)
    CMDN=$(echo "${OUT}" | wc -l)
	echo "sorted ${ARGN} elements using ${CMDN} operations"
    echo "${OUT}" | ./checker ${RAND}
	echo "${OUT}" | ./checker_mac ${RAND}
}

make -s -j4 dep
make -s -j4 push_swap
make -s checker_mac
make -s -j4 SILENT=1 PRINTSTACK=1 checker
perform_test "$1" "$2" "$3"
