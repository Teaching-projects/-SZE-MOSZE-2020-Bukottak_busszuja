#!/bin/bash
IFS=$'\n'

rm scenario_1_output.txt

printf 'Eeeeeeee' | ./output scenario scenario1.json >> scenario_1_output.txt

