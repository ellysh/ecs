#!/bin/bash

COUNT=30
INDEX=0

while [ $INDEX -le $COUNT ]
do
    ./virt-controller --dev /tmp/ttyS$INDEX --baud 57600 --scenario a20-test.vc --type serial --cycle --timeout 20 > $INDEX.log &
    INDEX="$(expr $INDEX + 2)"
done
