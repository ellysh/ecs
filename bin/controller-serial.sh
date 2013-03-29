#!/bin/bash

./clean.sh
./virt-controller --dev /tmp/ttyS0 --baud 57600 \
                  --scenario a20-test.vdc --type serial > debug.log
