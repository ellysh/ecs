#!/bin/bash

./virt-dashboard --ipl 192.168.122.124 --ipr 192.168.0.101 --port 4001 --rs 1 --scenario a20.vdc
#gdb --args ./virt-dashboard --ipl 192.168.122.124 --ipr 192.168.0.101 --port 4001 --rs 1 --scenario a20.vdc