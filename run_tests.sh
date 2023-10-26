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
	printf "\nFT Checker:"
	echo "${OUT}" | ./ft_checker ${RAND}
	printf "My Checker:"
    echo "${OUT}" | ./checker ${RAND}
	printf "\nsorted ${ARGN} elements using ${CMDN} operations"
}

perform_test "$1" "$2" "$3"
