#!/bin/bash
cd ../ && make
for i in b s q Q; do
	typeset -i n
	echo "" > /tmp/$i.dat
	for ((n=1;n<=1000;++n)); do
		Line=$(./sorting -$i -n $n | head -2 | tail -1 | cat)
		read -a strarr <<< "$Line"
		echo "${strarr[0]} ${strarr[2]}" >> /tmp/$i.dat
	done
done
make clean & cd .WRITEUP
gnuplot <<XX
set terminal jpeg size 1200, 800
set pointsize 0.2
set title "Sorting Algorithm Comparisons vs Items"
set xlabel "Number of Items"
# set ylabel "Comparisons"
show title
show xlabel
show ylabel

set output "bubble.jpg"
plot "/tmp/b.dat" with points lc rgbcolor "#724CEF" title "Bubble Sort"

set output "shell.jpg"
plot "/tmp/s.dat" with points lc rgbcolor "#724CEF" title "Shell Sort"

set output "quick_stack.jpg"
plot "/tmp/q.dat" with points lc rgbcolor "#724cEF" title "Quick Sort (Stack)"

set output "quick_queue.jpg"
plot "/tmp/Q.dat" with points lc rgbcolor "#724cEF" title "Quick Sort (Queue)"

set output "comparison.jpg"
plot "/tmp/b.dat" with points lc rgbcolor "#256EFF" title "bubble", \
	"/tmp/s.dat" with points lc rgbcolor "#46237A" title "shell", \
	"/tmp/q.dat" with points lc rgbcolor "#3DDC97" title "quick stack", \
	"/tmp/Q.dat" with points lc rgbcolor "#FF495C" title "quick queue"
XX
