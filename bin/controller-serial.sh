#!/bin/bash

#./clean.sh
./virt-controller --dev /tmp/ttyS0 --baud 57600 --timeout 20 \
                  --scenario a20-test.vc --type serial > debug.log
