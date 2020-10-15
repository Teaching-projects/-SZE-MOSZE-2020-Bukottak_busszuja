#pragma once
#include<iostream>
#include<string>
#include<fstream>

class Szorny {
protected:
	std::string nev;
    int maxhp;
    int hp;
	int dmg;
    friend class Kalandor;
public:
	Szorny(std::string nev, int hp, int dmg);
	int getDmg()const;
	int getMaxHp() const;
	int getHp()const;
	std::string getName()const;
	void tamad(Szorny &);
	static Szorny parseUnit(const std::string &filename);
	Szorny& operator=(const Szorny&);
	Szorny(const Szorny& s2) : nev(s2.nev), maxhp(s2.maxhp), hp(s2.hp), dmg(s2.dmg) {};

};
