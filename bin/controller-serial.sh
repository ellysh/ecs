#!/bin/bash

./clean.sh
./virt-controller --dev /dev/ --portr 4001 \
                  --scenario a20-init-pair.vdc --type udp > debug.log
