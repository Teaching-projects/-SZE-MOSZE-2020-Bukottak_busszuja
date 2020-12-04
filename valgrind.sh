#!/bin/bash

IFS=$'\n'
cmd="$(valgrind --leak-check=yes printf 'Ee' | ./output test scenario1.json)"
echo $cmd
