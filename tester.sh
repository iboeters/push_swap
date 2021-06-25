#!/bin/bash
make

gen_arr(){
	if [ $1 -le 0 ]; then
		return 1
	fi
	I=0
	ARG=""
	while [ $I -le $1 ]; do
		NUMBER=$(($RANDOM % 1000 - 500))
		if [[ ! " ${dup_array[@]} " =~ " ${NUMBER} " ]]; then
			dup_array[$I]=$NUMBER
			ARG+=" "
			ARG+=$NUMBER
			((I++))
		fi
	done
	echo $ARG
}

COUNTER=0
ARR_SIZE=0

YELLOW='\033[0;33m'
PURPLE='\033[0;35m'
RESET='\033[0m'

while [ $COUNTER -le $((30 + 1)) ]; do
	if [ $(($COUNTER % 5)) -eq 0 ]
	then
		((ARR_SIZE += 10))
		echo ""
		echo -ne "${PURPLE}Test with "
		echo -n $ARR_SIZE
		echo -e " numbers-------------------------------------------${RESET}"
	fi
	gen_arr $ARR_SIZE

	./push_swap $ARG | ./checker $ARG
	echo -ne "${YELLOW}n="
	./push_swap $ARG | wc -l
	echo -e "${RESET}"
	((COUNTER++))
done
