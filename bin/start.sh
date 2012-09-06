#!/bin/bash

./clean.sh
./virt-dashboard --ipl 192.168.0.101 --ipr 192.168.0.101 --portl 4002 --portr 4001 \
                 --rs 1 --scenario a20-kts25sm-3-4001-1.vdc > debug.log
