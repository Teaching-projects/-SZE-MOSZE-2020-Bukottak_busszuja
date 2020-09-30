#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>

class Szorny
{
public:
	Szorny(std::string nev, int hp, int dmg) :nev(nev), hp(hp), dmg(dmg) {}
	int getDmg()const;
	int getHp()const;
	std::string getName()const;
	void tamad(Szorny &)const;
	static Szorny parseUnit(const std::string);
private:
	std::string nev;
	int hp;
	int dmg;

};
