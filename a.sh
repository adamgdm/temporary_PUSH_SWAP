i=0
while [ $i -ne 100 ]; do
	ARG=$(ruby -e "puts (100..200).to_a.shuffle.join(' ')")
	./push_swap $ARG | ./checker_Mac $ARG
	i=$((i+1))
done
