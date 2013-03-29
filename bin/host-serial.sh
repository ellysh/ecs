#!/bin/bash

./clean.sh
./virt-host --dev /dev/ttyUSB0 --baud 57600 \
           --scenario a20-test.vh --type serial > debug.log
