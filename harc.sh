#!/bin/bash
IFS=$'\n'

rm kimenetek.txt

./output units/Hosarkany.json units/Sotetvarazslo.json >> kimenetek.txt
./output units/Hosarkany.json units/Arnykiraly.json >> kimenetek.txt 
./output units/Sotetvarazslo.json units/Hosarkany.json >> kimenetek.txt 
./output units/Sotetvarazslo.json units/Arnykiraly.json >> kimenetek.txt 
./output units/Arnykiraly.json units/Sotetvarazslo.json >> kimenetek.txt 
./output units/Arnykiraly.json units/Hosarkany.json >> kimenetek.txt
