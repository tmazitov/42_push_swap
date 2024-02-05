#!/bin/bash

PRINT_INPUT=false
PRINT_OUTPUT=false

CHECKER_PATH=/home/tlenovo/tools/pushswap_checker
PUSHSWAP_PATH=/home/tlenovo/projects/study/42_push_swap/push_swap

# FILEPATH: /home/tlenovo/projects/study/42_push_swap/test.sh
RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color


echo "\n${BLUE}PARSING TESTS${NC}\n"

for file in ./tests/*teste*; do
	numbers=$(cat "$file")
	result=$($PUSHSWAP_PATH $numbers)
	if [ $PRINT_INPUT = true ]; then
		echo "Input\t: $(echo "$numbers" | tr '\n' ' ')"
	fi
	if [ $PRINT_OUTPUT = true ]; then
		echo "Output\t: $(echo "$result" | tr '\n' ' ')"
	fi
	
	case $result in 
		*Error*) printf "%30s : ${GREEN}OK${NC}\n" $file;; 
		*) 	printf "%30s : ${RED}KO${NC}\n" $file;; 
	esac
	# if [ -z "${$result##*Error*}"]; then
	# 	echo "$file:\t ${GREEN}OK${NC}"
	# else
	# 	echo "$file:\t ${RED}KO${NC}"
	# fi 
done

echo "\n${BLUE}MAIN TESTS${NC}\n"

# Loop through all files in the ./tests folder that contain the word "test"
for file in ./tests/*test_*; do
	# Extract the numbers from the file
	numbers=$(cat "$file")

	# Execute the program "pushswap" with the numbers as arguments
	result=$(./pushswap $numbers)
	
	if [ $PRINT_INPUT = true ]; then
		echo "Input\t: $(echo "$numbers" | tr '\n' ' ')"
	fi
	if [ $PRINT_OUTPUT = true ]; then
		echo "Output\t: $(echo "$result" | tr '\n' ' ')"
	fi

	cheker_result=$($PUSHSWAP_PATH $numbers | $CHECKER_PATH $numbers)

	case $cheker_result in 
		*OK*) printf "%21s : ${GREEN}$cheker_result${NC}\n" $file;; 
		*) 	printf "%21s : ${RED}$cheker_result${NC}\n" $file;; 
	esac
done
