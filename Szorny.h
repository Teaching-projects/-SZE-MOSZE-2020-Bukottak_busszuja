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
	static Szorny parseUnit(const std::string);

};
