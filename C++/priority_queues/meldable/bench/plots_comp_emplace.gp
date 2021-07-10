set xlabel "number of elements"
set ylabel "compares per. element"
set key bottom right

set pointsize 0.7
set logscale x
set yr [0:4]
set xr [1000.0:10000000.0]

set output "./figures/emplace_comp.ps"
set terminal postscript eps color

plot "./data/magic_push.dat" using 1:(ceil($3)) title 'Magic Binary Queue' w linespoints pointtype 9 linecolor rgb "#DC143C", \
     "./data/regular_push.dat" using 1:(ceil($3)) title 'Regular Binary Queue' w linespoints pointtype 8 linecolor rgb "#008000", \
     "./data/eager_push.dat" using 1:(ceil($3)) title 'Eager Binary Queue' w linespoints pointtype 7 linecolor rgb "#8A2BE2", \
     "./data/binomial_emplace.dat" using 1:(ceil($3)) title 'Boost Binomial Queue' w linespoints pointtype 6 linecolor rgb "#008B8B", \
     "./data/lazy_vec_push.dat" using 1:(ceil($3)) title 'Lazy Binary Queue' w linespoints pointtype 8 linecolor rgb "#808000", \
     "./data/fibonacci_emplace.dat" using 1:(ceil($3)) title 'Boost Fibonacci Heap' w linespoints pointtype 5 linecolor rgb "#DAA520", \
     
#pause -1 "cont";
