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
cd ../notes/asgn2\ writeup
gnuplot <<XX
set terminal jpeg
set output "arcsin.jpg"
plot "/tmp/asin.dat" with linespoints title "diff. btwn. std. lib and this lib's arcsin(x)"
set output "arccos.jpg"
plot "/tmp/acos.dat" with linespoints title "diff. btwn. std. lib and this lib's arccos(x)"
set output "arctan.jpg"
plot "/tmp/atan.dat" with linespoints title "diff. btwn. std. lib and this lib's arctan(x)"
set output "exp.jpg"
plot "/tmp/log.dat" with linespoints title "diff. btwn. std. lib and this lib's log(x)"
XX

