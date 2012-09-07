#!/bin/bash

./clean.sh
./virt-controller --ipl 127.0.0.1 --ipr 127.0.0.1 --portl 4002 --portr 4001 \
                  --rs 1 --scenario a20-init.vdc > debug.log
