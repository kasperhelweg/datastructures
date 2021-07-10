#!/bin/bash

# general plots
gnuplot plots_push_po.gp
gnuplot plots_pop_po.gp
gnuplot plots_erase_po.gp
gnuplot plots_emplace_po.gp
gnuplot plots_decrease_po.gp

# general observations
gnuplot plots_general_list_vec_pop.gp
gnuplot plots_general_list_vec_push.gp
gnuplot plots_general_list_vec_erase.gp
gnuplot plots_general_list_vec_decrease.gp

gnuplot plots_general_mem_po.gp
gnuplot plots_general_nomem_po.gp


# lazy types 
gnuplot plots_lazy_pop_po.gp
gnuplot plots_lazy_emplace_po.gp
gnuplot plots_lazy_push_po.gp
gnuplot plots_lazy_erase_po.gp
gnuplot plots_lazy_decrease_po.gp

# compare plots
#gnuplot plots_comp_push.gp
gnuplot plots_comp_pop.gp
gnuplot plots_comp_erase.gp
gnuplot plots_comp_emplace.gp
gnuplot plots_comp_decrease.gp

# special sequences
gnuplot plots_seq_a_po.gp
gnuplot plots_seq_b_po.gp
