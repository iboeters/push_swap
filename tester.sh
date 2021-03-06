#!/bin/bash
make bonus

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
				echo -e "${PURPLE}MAX ACTIONS=1500${RESET}"
				echo -e "${PURPLE}1: 1500   2: 1300   3: 1100   4: 900   5: 700${RESET}"
			fi
			if [ $ARR_SIZE -eq 500 ]
			then
				echo -e "${PURPLE}MAX ACTIONS=11500${RESET}"
				echo -e "${PURPLE}1: 11500   2: 10000   3: 8500   4: 7000   5: 5500${RESET}"

			fi
		fi
		gen_arr $ARR_SIZE


		./push_swap $ARG | ./checker $ARG
		echo -ne "${YELLOW}n="
		./push_swap $ARG | wc -l
		echo -e "${RESET}"
		# sleep 1
		((COUNTER++))
	done
}

edgecases(){
	ARG=""
	echo "empty string"
	./push_swap $ARG | ./checker $ARG
	echo -ne "${YELLOW}n="
	./push_swap $ARG | wc -l
	echo -e "${RESET}"

	ARG="2147483647 3 1"
	echo $ARG
	./push_swap $ARG | ./checker $ARG
	echo -ne "${YELLOW}n="
	./push_swap $ARG | wc -l
	echo -e "${RESET}"

	ARG="2147483648 3 1"
	echo $ARG
	./push_swap $ARG | ./checker $ARG
	echo -ne "${YELLOW}n="
	./push_swap $ARG | wc -l
	echo -e "${RESET}"

	ARG="-2147483648 3 1"
	echo $ARG
	./push_swap $ARG | ./checker $ARG
	echo -ne "${YELLOW}n="
	./push_swap $ARG | wc -l
	echo -e "${RESET}"

	ARG="-2147483649 3 1"
	echo $ARG
	./push_swap $ARG | ./checker $ARG
	echo -ne "${YELLOW}n="
	./push_swap $ARG | wc -l
	echo -e "${RESET}"

	ARG="   "
	echo $ARG
	./push_swap $ARG | ./checker $ARG
	echo -ne "${YELLOW}n="
	./push_swap $ARG | wc -l
	echo -e "${RESET}"

	ARG="4 4 5"
	echo $ARG
	./push_swap $ARG | ./checker $ARG
	echo -ne "${YELLOW}n="
	./push_swap $ARG | wc -l
	echo -e "${RESET}"
}

YELLOW='\033[0;33m'
PURPLE='\033[0;35m'
RESET='\033[0m'

TEST_N=3

checkin 3 $TEST_N
checkin 5 $TEST_N
checkin 10 $TEST_N
checkin 15 $TEST_N
checkin 50 $TEST_N
checkin 100 $TEST_N
checkin 500 $TEST_N
edgecases
