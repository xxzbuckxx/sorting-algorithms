#!/bin/bash
cd ../ && make
for i in b s q Q; do
	typeset -i n
	echo "" > /tmp/${i}_time.dat
	for ((n=1;n<=100;++n)); do
	./sorting -$i -n $n >> /tmp/${i}_time.dat
	done
done
make clean & cd .WRITEUP
gnuplot <<XX
set terminal jpeg size 1200, 800
set pointsize 0.2
set title "Sorting Algorithm Execution Time vs Items"
set xlabel "Number of Items"
set ylabel "Time (in seconds)"
show title
show xlabel
show ylabel

set output "bubble_time.jpg"
# set key top left Left reverse
# f(x) = x**2 - x
plot "/tmp/b_time.dat" with points lc rgbcolor "#256EFF" title "Bubble Sort"
	 # f(x) with lines lc rgbcolor "#CCCC00" title "x^2 - x"

set key top right

set output "shell_time.jpg"
plot "/tmp/s_time.dat" with points lc rgbcolor "#46237A" title "Shell Sort"

set output "quick_stack_time.jpg"
plot "/tmp/q_time.dat" with points lc rgbcolor "#3DDC97" title "Quick Sort (Stack)"

set output "quick_queue_time.jpg"
plot "/tmp/Q_time.dat" with points lc rgbcolor "#FF495C" title "Quick Sort (Queue)"

set output "comparison_time.jpg"
plot "/tmp/b_time.dat" with linespoints lc rgbcolor "#256EFF" title "bubble", \
	"/tmp/s_time.dat" with linespoints lc rgbcolor "#46237A" title "shell", \
	"/tmp/q_time.dat" with linespoints lc rgbcolor "#3DDC97" title "quick stack", \
	"/tmp/Q_time.dat" with linespoints lc rgbcolor "#FF495C" title "quick queue"

# set output "comparison_small.jpg"
# plot "/tmp/b_small.dat" with linespoints lc rgbcolor "#256EFF" title "bubble", \
# 	"/tmp/s_small.dat" with linespoints lc rgbcolor "#46237A" title "shell", \
# 	"/tmp/q_small.dat" with linespoints lc rgbcolor "#3DDC97" title "quick stack", \
# 	"/tmp/Q_small.dat" with linespoints lc rgbcolor "#FF495C" title "quick queue"
XX
