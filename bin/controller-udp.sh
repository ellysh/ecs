#!/bin/bash

#./clean.sh
./virt-controller --ipl 127.0.0.1 --ipr 127.0.0.1 --portl 4002 --portr 4001 \
                  --scenario a20-test.vc --type udp --timeout 5 > debug.log
