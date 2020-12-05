#!/bin/bash
IFS=$'\n'

rm test_1_output.txt
rm test_2_output.txt

printf 'Ee' | ./output test testmap.txt >> test_1_output.txt
printf 'EeEsSsWwWn' | ./output test testmap2.txt >> test_2_output.txt

