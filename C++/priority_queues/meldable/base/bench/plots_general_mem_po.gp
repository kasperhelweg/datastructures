set xlabel "number of elements"
set ylabel "time in micro-seconds per. operation"
set key bottom right

set logscale x
#set logscale y
set pointsize 0.5
set xr [1000.0:10000000.0]
set yr [0.0:0.3]
set output "./figures/general_mem_po.ps"
set terminal postscript eps color

plot "./data/magic_emplace.dat" using 1:($2/$1) title 'Magic Binary Queue' w linespoints pointtype 9 linecolor rgb "#DC143C", \
     "./data/regular_emplace.dat" using 1:($2/$1) title 'Regular Binary Queue' w linespoints pointtype 4 linecolor rgb "#008000", \
     "./data/lazy_vec_emplace.dat" using 1:($2/$1) title 'Lazy Binary Queue' w linespoints pointtype 8 linecolor rgb "#808000", \
     "./data/eager_emplace.dat" using 1:($2/$1) title 'Eager Binary Queue' w linespoints pointtype 7 linecolor rgb "#8A2BE2", \
     
#pause -1 "cont";
