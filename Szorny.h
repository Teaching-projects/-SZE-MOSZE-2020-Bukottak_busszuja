#pragma once
#include "Jsonparser.h"


class Szorny
{
public:
	Szorny(std::string nev, int hp, int dmg) :nev(nev), hp(hp), dmg(dmg) {}
	int getDmg()const;
	int getHp()const;
	std::string getName()const;
	void tamad(Szorny &)const;
	static Szorny parseUnit(Jsonparser &);
private:
	std::string nev;
	int hp;
	int dmg;

};
