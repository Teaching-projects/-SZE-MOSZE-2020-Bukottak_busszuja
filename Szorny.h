#pragma once
#include<iostream>
#include<string>

using namespace std;


class Szorny
{
public:
	Szorny(string nev, int hp, int dmg):nev(nev),hp(hp),dmg(dmg) {}
	int getDmg()const;
	int getHp()const;
	string getName()const;
	void tamad(Szorny &)const;
private:
    const string nev;
	int hp;
	int dmg;

};
