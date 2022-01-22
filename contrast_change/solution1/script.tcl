############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
############################################################
open_project contrast_change
add_files core.cpp
add_files core.h
add_files -tb test_core.cpp
open_solution "solution1" -flow_target vivado
set_part {xcvc1802-viva1596-1LHP-i-L}
create_clock -period 10 -name default
#source "./contrast_change/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
