#!/bin/bash

#./clean.sh
./virt-host --dev /tmp/ttyS1 --baud 57600 \
           --scenario a20-test.vh --type serial > debug_host.log
