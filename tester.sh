#!/bin/bash
make

gen_arr(){
	if [ $1 -le 0 ]; then
		return 1
	fi
	I=0
	ARG=""
	while [ $I -le $(($1 - 1)) ]; do
		NUMBER=$(($RANDOM % ($1 * 6) - ($1 * 3)))
		if [[ ! " ${dup_array[@]} " =~ " ${NUMBER} " ]]; then
			dup_array[$I]=$NUMBER
			ARG+=" "
			ARG+=$NUMBER
			((I++))
		fi
	done
	echo $ARG
}

checkin(){
	COUNTER=0
	ARR_SIZE=$1
	while [ $COUNTER -lt $2 ]; do
		if [ $(($COUNTER)) -eq 0 ]
		then
			# echo ""
			echo -ne "${PURPLE}Test with "
			echo -n $ARR_SIZE
			echo -e " numbers-------------------------------------------${RESET}"
			if [ $ARR_SIZE -eq 3 ]
			then
				echo -e "${PURPLE}MAX ACTIONS=3${RESET}"
			fi
			if [ $ARR_SIZE -eq 5 ]
			then
				echo -e "${PURPLE}MAX ACTIONS=12${RESET}"
			fi
			if [ $ARR_SIZE -eq 100 ]
			then
				echo -e "${PURPLE}MAX ACTIONS=1500 (L700) ${RESET}"
			fi
			if [ $ARR_SIZE -eq 500 ]
			then
				echo -e "${PURPLE}MAX ACTIONS=11500 (L5500) ${RESET}"
			fi
		fi
		gen_arr $ARR_SIZE

		./push_swap $ARG | ./checker $ARG
		echo -ne "${YELLOW}n="
		./push_swap $ARG | wc -l
		echo -e "${RESET}"
		((COUNTER++))
	done
}

YELLOW='\033[0;33m'
PURPLE='\033[0;35m'
RESET='\033[0m'

TEST_N=3

checkin 5 $TEST_N
checkin 10 $TEST_N
checkin 100 $TEST_N
# checkin 500 $TEST_N
