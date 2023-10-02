make -s SLEEP=0
mycmd=(./push_swap 123 234 345 456 567 678 789)

if "${mycmd[@]}" | grep -q 'UwU'; then
   echo "program execution ended"
fi
