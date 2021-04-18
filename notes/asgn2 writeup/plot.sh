#!/bin/bash
cd ../../asgn2/ && make clean
make
for i in asin acos atan log
do
	if [ ${i:0:1} == "a" ]
	then
		./mathlib-test -${i:1:1} > /tmp/$i.dat
	else
		./mathlib-test -${i:0:1} > /tmp/$i.dat
	fi
done
make clean && cd ../notes/asgn2\ writeup
gnuplot <<XX
set terminal jpeg size 1200, 800
set pointsize 0.2
set title "Differences in Approximation"
set xlabel "x"
set ylabel "Small Numeric Library vs Standard C Library"
show title
show xlabel
show ylabel
set output "arctan.jpg"
set title "Differences in Approximation of Arctan(x)"
plot "/tmp/atan.dat" with points lc rgbcolor "#724CEF" title "diff. btwn. std. lib and this lib's arctan(x)"
set output "exp.jpg"
set title "Differences in Approximation of ln(x)"
plot "/tmp/log.dat" with points lc rgbcolor "#724CEF" title "diff. btwn. std. lib and this lib's log(x)"
set arrow from -0.7, graph 0 to -0.7, graph 1 nohead lc "#55bbbbbb"
set arrow from 0.7, graph 0 to 0.7, graph 1 nohead lc "#55bbbbbb"
set output "arcsin.jpg"
set title "Differences in Approximation of Arcsin(x)"
plot "/tmp/asin.dat" with points lc rgbcolor "#724cEF" title "diff. btwn. std. lib and this lib's arcsin(x)"
set output "arccos.jpg"
set title "Differences in Approximation of Arccos(x)"
plot "/tmp/acos.dat" with points lc rgbcolor "#724cEF" title "diff. btwn. std. lib and this lib's arccos(x)"
XX

