#!/bin/bash

IFS=$'\n'
cmd="$(valgrind --leak-check=yes printf 'Eeeeeeee' | ./output scenario scenario1.json)"
echo $cmd
