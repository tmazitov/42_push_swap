separator=" -> "

for test in $( ls ./tests | grep "test")
do
	test_value=$(cat ./tests/${test} | tr " " "\n")
	echo $test_value
	pushswap_result=$(./pushswap ${test_value})
	echo =======
	# echo $pushswap_result
	# pushswap_values = $(echo $pushswap_result | tr $SEPARATOR)
	# for value in $pushswap_values
	# do
	# 	echo $value
	# done
done