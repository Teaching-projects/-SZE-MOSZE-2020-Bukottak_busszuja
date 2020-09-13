#pragma once
#include<iostream>
#include<string>

using namespace std;


class Szorny
{
public:
	Szorny(string,int,int);
	~Szorny();
	int getDmg()const;
	int getHp()const;
	string getName()const;
	void kiir()const;
	void tamadas(Szorny &);
private:
	int hp;
	void setHp(int);
	int dmg;
	string nev;
};

