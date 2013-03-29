#!/bin/bash

./clean.sh
./virt-host --ipl 10.0.0.1 --ipr 10.0.0.2 --portl 4001 --portr 4001 \
           --scenario a20-test.vh --type udp > debug.log
