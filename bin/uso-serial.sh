#!/bin/bash

./clean.sh
./virt-uso --dev /dev/ttyUSB0 --baud 57600 \
           --scenario a20-test.vdu --type serial > debug.log
