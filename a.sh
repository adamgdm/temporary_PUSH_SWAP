i=0
while [ $i -ne 100 ]; do
	ARG=$(ruby -e "puts (3..6).to_a.shuffle.join(' ')")
	./push_swap $ARG | ./checker_Mac $ARG && echo and && ./push_swap $ARG | ./checker $ARG 
	i=$((i+1))
done
