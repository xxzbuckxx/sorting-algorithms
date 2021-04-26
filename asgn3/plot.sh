#!/bin/bash
make
for i in b s q Q
do
	./mathlib-test -${i:1:1} | head -2 | tail -1 > /tmp/$i.dat
done
make clean
gnuplot <<XX
set terminal jpeg size 1200, 800
set pointsize 0.2
# set title "Differences in Approximation"
# set xlabel "x"
# set ylabel "Small Numeric Library - Standard C Library"
# show title
# show xlabel
# show ylabel

set output "bubble.jpg"
set title "Differences in Approximation of Arctan(x)"
plot "/tmp/b.dat" with points lc rgbcolor "#724CEF" title "diff. btwn. std. lib and this lib's arctan(x)"

set output "shell.jpg"
set title "Differences in Approximation of ln(x)"
plot "/tmp/s.dat" with points lc rgbcolor "#724CEF" title "diff. btwn. std. lib and this lib's log(x)"

set output "quick_stack.jpg"
set title "Differences in Approximation of Arcsin(x)"
plot "/tmp/q.dat" with points lc rgbcolor "#724cEF" title "diff. btwn. std. lib and this lib's arcsin(x)"

set output "quick_queue.jpg"
set title "Differences in Approximation of Arccos(x)"
plot "/tmp/Q.dat" with points lc rgbcolor "#724cEF" title "diff. btwn. std. lib and this lib's arccos(x)"
XX

