#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include "Szorny.h"

class Kalandor : public Szorny {
public:
	Kalandor(std::string nev, int hp, int dmg);
	Kalandor(Szorny sz);
	int getXp() const;
	int getLvl() const;
	void tamad(Szorny &);
	Kalandor& operator=(const Szorny&);
	int xp;
	int lvl;
	void lvlUp(int xptoLvl);
	void xpGain();

};
