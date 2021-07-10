#!/bin/bash
echo 'building'
g++ -O3 -I ./utils/ -I ./nodes/ -I ./registries -I ./registries/stores/ -I ./registries/policies -I ./realizers -I ./containers -I ./ -I ./bench -std=c++11 -o magic_q.out magic_q.c++
g++ -O3 -I ./utils/ -I ./nodes/ -I ./registries -I ./registries/stores/ -I ./registries/policies -I ./realizers -I ./containers -I ./ -I ./bench -std=c++11 -o regular_q.out regular_q.c++
g++ -O3 -I ./utils/ -I ./nodes/ -I ./registries -I ./registries/stores/ -I ./registries/policies -I ./realizers -I ./containers -I ./ -I ./bench -std=c++11 -o eager_q.out eager_q.c++
g++ -O3 -I ./utils/ -I ./nodes/ -I ./registries -I ./registries/stores/ -I ./registries/policies -I ./realizers -I ./containers -I ./ -I ./bench -std=c++11 -o lazy_q.out lazy_q.c++
g++ -O3 -I ./utils/ -I ./nodes/ -I ./registries -I ./registries/stores/ -I ./registries/policies -I ./realizers -I ./containers -I ./ -I ./bench -std=c++11 -o lazy_q_vec.out lazy_q_vec.c++
g++ -O3 -I ./utils/ -I ./nodes/ -I ./registries -I ./registries/stores/ -I ./registries/policies -I ./realizers -I ./containers -I ./ -I ./bench -I /usr/include/boost/heap -std=c++11 -o boost_heaps.out boost_heaps.c++
echo 'benchmarks'
#sleep 240
./eager_q.out
./magic_q.out
#sleep 240
./regular_q.out
#sleep 240
#sleep 240
./lazy_q.out
#sleep 240
./lazy_q_vec.out
#sleep 240
./boost_heaps.out
#sleep 240

