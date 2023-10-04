set -e

make -s SLEEP=0 OPSONLY=1 re
cmd=(./push_swap 123 234 345 456 567 678 789)
#cmd=(./push_swap dqzfabg)

if "${cmd[@]}" | grep -q 'pa'; then
   echo "program execution ended"
fi