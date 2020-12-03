#!/bin/bash

IFS=$'\n'
cmd="$(cppcheck *.cpp --enable=all 2> report.txt && cat report.txt && if grep -q "(warning)" "./report.txt"; then exit 1; fi && if grep -q "(error)" "./report.txt"; then exit 1; fi)"
echo $cmd
