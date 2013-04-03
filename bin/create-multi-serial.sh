#!/bin/bash

COUNT=30
INDEX=0

while [ $INDEX -le $COUNT ]
do
    socat PTY,link=/tmp/ttyS$INDEX,raw,echo=0 PTY,link=/tmp/ttyS`expr $INDEX + 1`,raw,echo=0 &
    INDEX="$(expr $INDEX + 2)"
done
