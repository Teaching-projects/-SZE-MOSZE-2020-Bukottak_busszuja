#!/bin/bash
IFS=$'\n'

rm kimenetek.txt

./a.out units/Hosarkany.json units/Sotetvarazslo.json >> kimenetek.txt
./a.out units/Hosarkany.json units/Arnykiraly.json >> kimenetek.txt 
./a.out units/Sotetvarazslo.json units/Hosarkany.json >> kimenetek.txt 
./a.out units/Sotetvarazslo.json units/Arnykiraly.json >> kimenetek.txt 
./a.out units/Arnykiraly.json units/Sotetvarazslo.json >> kimenetek.txt 
./a.out units/Arnykiraly.json units/Hosarkany.json >> kimenetek.txt 

