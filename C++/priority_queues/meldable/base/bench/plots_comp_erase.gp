set xlabel "number of elements( log-scale )"
set ylabel "compares per. element"
set key top left

set pointsize 0.7
set logscale x
#set logscale y
set xr [1000:10000000]
#set yr [0:12]
set output "./figures/erase_comp.ps"
set terminal postscript eps color

plot "./data/binomial_erase.dat" using 1:(ceil($3)) title 'Boost Binomial Queue' w linespoints pointtype 6 linecolor rgb "#008B8B", \
     "./data/fibonacci_erase.dat" using 1:(ceil($3)) title 'Boost Fibonacci Heap' w linespoints pointtype 5 linecolor rgb "#DAA520", \
     "./data/lazy_erase.dat" using 1:(ceil($3)) title 'Lazy Binary Queue Delete Comps' w linespoints pointtype 8  linecolor rgb "#808000", \
     "./data/magic_erase.dat" using 1:(ceil($3)) title 'Magic Binary Queue Delete Comps' w linespoints pointtype 9 linecolor rgb "#DC143C", \
     "./data/regular_erase.dat" using 1:(ceil($3)) title 'Regular Binary Queue Delete Comps' w linespoints pointtype 4 linecolor rgb "#008000", \
     "./data/eager_erase.dat" using 1:(ceil($3)) title 'Eager Binary Queue Delete Comps' w linespoints pointtype 7 linecolor rgb "#8A2BE2", \
     
     

#pause -1 "cont";
