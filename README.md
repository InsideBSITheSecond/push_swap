# push_swap

main branch
[![base compilation](https://github.com/InsideBSITheSecond/push_swap/actions/workflows/compile.yml/badge.svg?branch=master)](https://github.com/InsideBSITheSecond/push_swap/actions/workflows/compile.yml) [![base tests](https://github.com/InsideBSITheSecond/push_swap/actions/workflows/run_tests.yml/badge.svg?branch=master)](https://github.com/InsideBSITheSecond/push_swap/actions/workflows/run_tests.yml)

dev branch
[![base compilation](https://github.com/InsideBSITheSecond/push_swap/actions/workflows/compile.yml/badge.svg?branch=dev)](https://github.com/InsideBSITheSecond/push_swap/actions/workflows/compile.yml) [![base tests](https://github.com/InsideBSITheSecond/push_swap/actions/workflows/run_tests.yml/badge.svg?branch=dev)](https://github.com/InsideBSITheSecond/push_swap/actions/workflows/run_tests.yml)

# usage
## automated
./run_tests [min] [max] [count]
## manual
### push_swap only
./push_swap [args]
### push_swap & checker
#### fish:
set ARG "[args]"; ./push_swap $ARG | ./checker $ARG
#### bash:
$ARG="[args]"; ./push_swap $ARG | ./checker $ARG
