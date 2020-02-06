#!/bin/bash

current=`echo $$`
i=1
while((current>0))
do
    echo "$i->$current"
    current=`ps -o ppid= $current`
    i=$((i+1))
done
