#!/bin/bash

./clean.sh
./virt-host --ipl 127.0.0.1 --ipr 127.0.0.1 --portl 4001 --portr 4002 \
           --scenario a20-test.vh --type udp > debug_host.log
