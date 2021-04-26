#!/bin/bash
cd ../ && make
for i in q Q; do
	typeset -i n
	echo "" > /tmp/$i.size.dat
	for ((n=1;n<=9;++n)); do
		number=$(./sorting -$i -n $n)
		echo "$number" >> /tmp/$i.size.dat
	done
done
make clean & cd .WRITEUP
gnuplot <<XX
set terminal jpeg size 1200, 800
set pointsize 0.2
set title "Sorting Algorithm Comparisons vs Items"
set xlabel "Number of Items"
set ylabel "Comparisons"
show title
show xlabel
show ylabel

set output "quick_stack_size.jpg"
plot "/tmp/Q.size.dat" with points lc rgbcolor "#3DDC97" title "Quick Sort (Stack)"

set output "quick_queue_size.jpg"
plot "/tmp/Q.size.dat" with points lc rgbcolor "#FF495C" title "Quick Sort (Queue)"
XX
