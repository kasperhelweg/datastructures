set xlabel "number of elements( log-scale )"
set ylabel "compares per. element"
set key bottom right

set pointsize 0.7
set yr [0:100]
set logscale x
set xr [1000:10000000]
set output "./figures/comp_pop.ps"
set terminal postscript eps color

plot "./data/magic_pop.dat" using 1:(ceil($3)) title 'Magic Binary Queue' w linespoints pointtype 9 linecolor rgb "#DC143C", \
     "./data/fibonacci_pop.dat" using 1:(ceil($3)) title 'Boost Fibonacci Heap' w linespoints pointtype 5 linecolor rgb "#DAA520", \
     "./data/regular_pop.dat" using 1:(ceil($3)) title 'Regular Binary Queue' w linespoints pointtype 4 linecolor rgb "#008000", \
     "./data/lazy_pop.dat" using 1:(ceil($3)) title 'Lazy Binary Queue' w linespoints pointtype 8  linecolor rgb "#808000", \
     "./data/binomial_pop.dat" using 1:(ceil($3)) title 'Boost Binomial Queue' w linespoints pointtype 6 linecolor rgb "#008B8B", \
     "./data/eager_pop.dat" using 1:(ceil($3)) title 'Eager Binary Queue' w linespoints pointtype 7 linecolor rgb "#8A2BE2", \
     
     

#pause -1 "cont";

