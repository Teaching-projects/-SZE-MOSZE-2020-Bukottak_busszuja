#!/bin/bash
IFS=$'\n'

rm kimenetek.txt

printf 'Ee' | ./output test scenario1.json >> scenario_1_output.txt

