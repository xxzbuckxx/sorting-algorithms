#!/bin/bash
cd ../ && make
for i in q Q; do
	typeset -i n
	echo "" > /tmp/$i.size.dat
	for ((n=1;n<=1000;++n)); do
		number=$(./sorting -$i -n $n)
		echo "$number" >> /tmp/$i.size.dat
	done
done
make clean & cd .WRITEUP
gnuplot <<XX
set terminal jpeg size 1200, 800
set pointsize 0.2
set title "Quick Sort Datastrucutre size vs Items"
set xlabel "Number of Items"
set ylabel "Max Datastructure size"
show title
show xlabel
show ylabel

# set output "quick_stack_size.jpg"
# plot "/tmp/q.size.dat" with points lc rgbcolor "#3DDC97" title "Quick Sort (Stack)"

# set output "quick_queue_size.jpg"
# plot "/tmp/Q.size.dat" with points lc rgbcolor "#FF495C" title "Quick Sort (Queue)"

set output "quick_comparison_size.jpg"
plot "/tmp/q.size.dat" with points lc rgbcolor "#3DDC97" title "Quick Sort (Stack)", \
	"/tmp/Q.size.dat" with points lc rgbcolor "#FF495C" title "Quick Sort (Queue)"
XX
