#pragma once
#include<iostream>
#include<string>


class Szorny
{
public:
	Szorny(std::string nev, int hp, int dmg):nev(nev),hp(hp),dmg(dmg) {}
	int getDmg()const;
	int getHp()const;
	std::string getName()const;
	void tamad(Szorny &)const;
private:
    const std::string nev;
	int hp;
	const int dmg;

};
