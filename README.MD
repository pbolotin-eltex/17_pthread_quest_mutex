# pthread_quest_mutex pthread_quest_onethread

## Compile

make

## Description

In directory after compilation are files:

1. pthread_quest_mutex - 1000 threads increment the variable using mutex.

2. pthread_quest_onethread - only 1 thread increment the variable.

Both version do it up to 1'000'000'000 value of variable.

3. pthread_quest_time_compare.sh - bash script to compare 1. and 2.

It show that 2. is faster using only one thread to increment.
