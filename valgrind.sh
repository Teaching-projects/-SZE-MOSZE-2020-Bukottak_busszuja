#!/bin/bash

IFS=$'\n'
echo "$(valgrind --leak-check=yes printf 'Ee' | ./output test scenario1.json)"