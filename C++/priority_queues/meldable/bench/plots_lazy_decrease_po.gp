set xlabel "number of elements"
set ylabel "time in micro-seconds per. operation"
set key bottom right

set logscale x
#set logscale y
set pointsize 0.5
set xr [1000.0:10000000.0]
set output "./figures/lazy_decrease_po.ps"
set terminal postscript eps color

plot "./data/lazy_vec_decrease.dat" using 1:($2/$1) title 'Lazy Binary Queue - Vector' w linespoints pointtype 8 linecolor rgb "#808000", \
     "./data/lazy_decrease.dat" using 1:($2/$1) title 'Lazy Binary Queue - List' w linespoints pointtype 9 linecolor rgb "#DC143C", \
     "./data/fibonacci_decrease.dat" using 1:($2/$1) title 'Boost Fibonacci' w linespoints pointtype 7 linecolor rgb "#8A2BE2", \
#pause -1 "cont";
