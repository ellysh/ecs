#!/bin/bash

./clean.sh
./virt-controller --dev /dev/ttyUSB0 --baud 57600 \
                  --scenario a20-test.vdc --type serial > debug.log
