#!/bin/bash
IFS=$'\n'

rm scenario_1_output.txt

printf 'Ee' | ./output test scenario1.json >> scenario_1_output.txt

