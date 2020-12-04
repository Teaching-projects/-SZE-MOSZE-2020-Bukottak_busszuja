#!/bin/bash

IFS=$'\n'
echo "$(valgrind --leak-check=full --error-exitcode=3 printf 'Ee' | ./output test scenario1.json)"
