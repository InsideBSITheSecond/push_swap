# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run_tests.sh                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: insidebsi <insidebsi@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/05 00:16:33 by insidebsi         #+#    #+#              #
#    Updated: 2023/10/05 00:16:34 by insidebsi        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#set -e

make SLEEP=0
cmd=(./push_swap 123 234 345 456 567 678 789)
#cmd=(./push_swap dqzfabg)

if "${cmd[@]}" | grep -q 'pa'; then
   echo "program execution ended"
fi