#include "Szorny.h"

double gcd(double a, double b)
{
	if (a < b)
		return gcd(b, a);
	if (fabs(b) < 0.001)
		return a;
	else
		return (gcd(b, a - floor(a / b) * b));
}

int Szorny::getDmg()const {
	return dmg;
}

int Szorny::getMaxHp()const {
	return hp;
}

int Szorny::getHp()const {
	return hp;
}

std::string Szorny::getName()const {
	return nev;
}

double Szorny::getSpeed() const {
	return speed;
}

void Szorny::tamad(Szorny& a) {
	a.hp = a.hp - this->dmg;
	if (a.hp < 0) a.hp = 0;
}


Szorny Szorny::parseUnit(Jsonparser & json) {
	std::string name = json.getErtek("name");
	int hp = stoi(json.getErtek("hp"));
	int dmg = stoi(json.getErtek("dmg"));
  	double speed = stod(json.getErtek("speed"));
	return Szorny(name,hp,dmg,speed);
}

Szorny& Szorny::operator=(const Szorny &szorny) {
    maxhp = szorny.getMaxHp();
    hp = szorny.getHp();
    dmg = szorny.getDmg();
    nev = szorny.getName();
    speed = szorny.getSpeed();
    return *this;
}

void Szorny::harc(Szorny &s1,Szorny &s2) {
	double szamlalo = 0;
	double lepes = gcd(s1.getSpeed(), s2.getSpeed());
	s1.tamad(s2);
	if (s2.getHp() > 0) {
		s2.tamad(s1);
	}
	while ((s1.getHp() > 0) && (s2.getHp()>0)) {
		szamlalo = szamlalo + lepes;
		if (gcd(szamlalo, s1.getSpeed()) == s1.getSpeed() && gcd(szamlalo, s2.getSpeed()) == s2.getSpeed()) {
			s1.tamad(s2);
			if (s2.getHp() > 0) s2.tamad(s1);
		}
		else if (gcd(szamlalo, s1.getSpeed()) == s1.getSpeed())s1.tamad(s2);
		else if (gcd(szamlalo, s2.getSpeed()) == s2.getSpeed())s2.tamad(s1);
	}
}

