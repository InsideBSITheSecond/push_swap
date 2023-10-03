set -e

make -s SLEEP=0 OPSONLY=1 RETURNSTATUS=1 
#cmd=(./push_swap 123 234 345 456 567 678 789)
cmd=(./push_swap "123f"the 234 345 456 567 678 789)

if "${cmd[@]}" | grep -q 'UwU'; then
   echo "program execution ended"
fi