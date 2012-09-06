#!/bin/bash

./clean.sh
./virt-controller --ipl 192.168.0.101 --ipr 192.168.0.101 --portl 4002 --portr 4001 \
                  --rs 1 --scenario a20-init.vdc > debug.log
