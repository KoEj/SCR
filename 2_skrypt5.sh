#!/bin/bash
trap "echo trapped" {1..15}

while true; do
 i=$[$i+1]
 echo $i;
 sleep 3
done


