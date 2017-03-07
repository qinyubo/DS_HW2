#!/bin/bash

CC=g++

cd ./code

echo "Compiling code"

$(CC) ./q1.cpp -o q1
$(CC) ./q2_1.cpp -o q2_1
$(CC) ./q2_2.cpp -o q2_2
$(CC) ./q3_1.cpp -o q3_1
$(CC) ./q3_2.cpp -o q3_2
$(CC) ./q5_1.cpp -o q5_1
$(CC) ./q5_2.cpp -o q5_2

echo "DONE compilation!"

echo "Start executing code:"

#run code
./q1 *+abc

./q2_1

./q2_2

./q3_1

./q3_2

./q5_1

./q5_2

echo "DONE!"
