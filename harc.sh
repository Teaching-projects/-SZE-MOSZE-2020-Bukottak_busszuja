#!/bin/bash
IFS=$'\n'

rm kimenetek.txt

./output scenario1.json >> scenario_1_output.txt
./output scenario2.json >> scenario_2_output.txt 
