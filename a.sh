i=0
while [ $i -ne 100 ]; do
	ARG=$(ruby -e "puts (100..300).to_a.shuffle.join(' ')")
	echo $ARG
	./push_swap $ARG | ./checker_Mac $ARG
	i=$((i+1))
done
