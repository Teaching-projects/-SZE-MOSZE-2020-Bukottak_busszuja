#include "Szorny.h"



Szorny::Szorny(string a,int b,int c)
{
	this->nev = a;
	this->hp = b;
	this->dmg = c;
}


Szorny::~Szorny()
{
}

int Szorny::getDmg()const {
	return this->dmg;
}

int Szorny::getHp()const {
	return this->hp;
}

string Szorny::getName()const {
	return this->nev;
}

void Szorny::kiir()const {
	cout << this->nev << ": HP: " << this->hp << ", DMG: " << this->dmg << endl;
}

void Szorny::setHp(int a) {
	this->hp = a;
}

void Szorny::tamadas(Szorny & a) {
	int pont1 = this->hp;
	int pont2 = a.getHp();
	while (pont1 > 0 && pont2 > 0) {
		cout << this->nev << " -> " << a.getName() << endl;
		a.setHp(a.getHp() - this->dmg);
		pont2 = a.getHp();
		this->kiir();
		a.kiir();
		if (pont1 > 0 && pont2 > 0) {
			cout << a.getName() << " -> " << this->nev << endl;
			this->hp = this->hp - a.getDmg();
			pont1 = this->hp;
			if (pont1 < 0)this->hp = 0;
			if (pont2 < 0) a.setHp(0);
			this->kiir();
			a.kiir();
		}
	}
	if (this->hp==0) cout << this->nev << " meghalt. " << a.getName() << " nyert." << endl;
	if (a.getHp() == 0) cout << a.getName() << " meghalt. " << this->nev << " nyert." << endl;
}