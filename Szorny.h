#pragma once
#include<iostream>
#include<string>

using namespace std;


class Szorny
{
public:
	Szorny(string a, int b, int c):nev(a),hp(b),dmg(c) {}
	int getDmg()const;
	int getHp()const;
	string getName()const;
	void kiir()const;
	void tamad(Szorny &);
private:
    string nev;
	int hp;
	int dmg;

};
