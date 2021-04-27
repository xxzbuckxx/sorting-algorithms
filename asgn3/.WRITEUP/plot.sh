#!/bin/bash
cd ../ && make
for i in b s q Q; do
	typeset -i n
	echo "" > /tmp/$i.dat
	for ((n=1;n<=1000;++n)); do
		comparisons=$(./sorting -$i -n $n | head -2 | tail -1 | cat)
		read -a strarr <<< "$comparisons"
		echo "${strarr[0]} ${strarr[2]}" >> /tmp/$i.dat
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
set xrange [0:1000]

set output "bubble.jpg"
# set key top left Left reverse
# f(x) = x**2 - x
plot "/tmp/b.dat" with points lc rgbcolor "#256EFF" title "Bubble Sort"
	 # f(x) with lines lc rgbcolor "#CCCC00" title "x^2 - x"

set key top right

set output "shell.jpg"
plot "/tmp/s.dat" with points lc rgbcolor "#46237A" title "Shell Sort"

set output "quick_stack.jpg"
plot "/tmp/q.dat" with points lc rgbcolor "#3DDC97" title "Quick Sort (Stack)"

set output "quick_queue.jpg"
plot "/tmp/Q.dat" with points lc rgbcolor "#FF495C" title "Quick Sort (Queue)"

set output "comparison.jpg"
plot "/tmp/b.dat" with points lc rgbcolor "#256EFF" title "bubble", \
	"/tmp/s.dat" with points lc rgbcolor "#46237A" title "shell", \
	"/tmp/q.dat" with points lc rgbcolor "#3DDC97" title "quick stack", \
	"/tmp/Q.dat" with points lc rgbcolor "#FF495C" title "quick queue"

# set output "comparison_small.jpg"
# plot "/tmp/b_small.dat" with linespoints lc rgbcolor "#256EFF" title "bubble", \
# 	"/tmp/s_small.dat" with linespoints lc rgbcolor "#46237A" title "shell", \
# 	"/tmp/q_small.dat" with linespoints lc rgbcolor "#3DDC97" title "quick stack", \
# 	"/tmp/Q_small.dat" with linespoints lc rgbcolor "#FF495C" title "quick queue"
XX
