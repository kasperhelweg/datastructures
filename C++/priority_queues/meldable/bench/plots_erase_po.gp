set xlabel "number of elements( log-scale )"
set ylabel "time in micro-seconds per. element"
set key top left

set logscale x
#set logscale y
set pointsize 0.7
set xr [1000.0:1000000.0]
set output "./figures/erase_po.ps"
set terminal postscript eps color

plot "./data/binomial_erase.dat" using 1:($2/$1) title 'Boost Binomial Queue' w linespoints pointtype 6 linecolor rgb "#008B8B", \
     "./data/regular_erase.dat" using 1:($2/$1) title 'Regular Binary Queue' w linespoints pointtype 4 linecolor rgb "#008000", \
     "./data/magic_erase.dat" using 1:($2/$1) title 'Magic Binary Queue' w linespoints pointtype 9 linecolor rgb "#DC143C", \

#pause -1 "cont";
