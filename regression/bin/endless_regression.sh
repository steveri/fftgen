#!/bin/bash

bin=/nobackup/steveri/github/fftgen/bin

# at interval=1 sec, get about 600 results/day
# what happens at 60?
interval=60

while true; do 
  nice -16 $bin/do_one_random_test.sh
  sleep $interval
done
