#!bin/bash

my_m=$(ruby -e "puts (1..100).to_a.shuffle.join(' ')")
echo $my_m
##./push_swap $my_m
res=$(./push_swap $my_m | wc -l)
##./push_swap $my_m
./push_swap $my_m | ./checker_Mac $my_m
##echo $res

##res=$(./push_swap $my_m | wc -l)
##echo $my_m
echo -e "\nRESULT = \033[1;35m$res"
