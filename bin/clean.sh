#!/bin/bash

killall -9 virt-controller
killall -9 socat

rm -rf *.log *.txt *.dbg
#rm -rf /tmp/ttyS*
