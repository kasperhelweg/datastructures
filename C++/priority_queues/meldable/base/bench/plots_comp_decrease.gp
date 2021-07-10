set xlabel "number of elements( log-scale )"
set ylabel "compares per. operation"
set key top left

set logscale x
set pointsize 0.7
set xr [1000:10000000]
#set yr [0:10]
set output "./figures/decrease_comp.ps"
set terminal postscript eps color

plot "./data/fibonacci_decrease.dat" using 1:(ceil($3)) title 'Boost Fibonacci Heap' w linespoints pointtype 5 linecolor rgb "#DAA520", \
     "./data/regular_decrease.dat" using 1:(ceil($3)) title 'Regular Binary Queue' w linespoints pointtype 4 linecolor rgb "#008000", \
     "./data/magic_decrease.dat" using 1:(ceil($3)) title 'Magic Binary Queue' w linespoints pointtype 9 linecolor rgb "#DC143C", \
     "./data/eager_decrease.dat" using 1:(ceil($3)) title 'Eager Binary Queue' w linespoints pointtype 7 linecolor rgb "#8A2BE2", \
     "./data/binomial_decrease.dat" using 1:(ceil($3)) title 'Boost Binomial Queue' w linespoints pointtype 6 linecolor rgb "#008B8B", \
     "./data/lazy_decrease.dat" using 1:(floor($3)) title 'Lazy Binary Queue' w linespoints pointtype 8  linecolor rgb "#808000", \
#pause -1 "cont";
