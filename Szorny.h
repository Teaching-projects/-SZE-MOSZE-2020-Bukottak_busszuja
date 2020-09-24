#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>

class Szorny
{
public:
	Szorny(std::string nev, int hp, int dmg) :nev(nev), hp(hp), dmg(dmg) {}
	Szorny(){}
	int getDmg()const;
	int getHp()const;
	std::string getName()const;
	void tamad(Szorny &)const;
	void parseUnit(std::ifstream &);
private:
	std::string nev;
	int hp;
	int dmg;

};
