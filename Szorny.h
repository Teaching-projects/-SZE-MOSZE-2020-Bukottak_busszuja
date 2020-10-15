/**
 * \class Szörny
 * 
 * \brief Szörny class
 * 
 * \author Habán András, Tranta Máté, Tóth Norbert
 * 
 * Created on: 2020/10/14 17:15
*/
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include <cmath>

class Szorny
{
public:
	Szorny(std::string nev, int hp, int dmg,double speed) :nev(nev), hp(hp), dmg(dmg),speed(speed) {}  ///< Szörny osztály konstruktora
	int getDmg()const;	///< Lekéri a hõs DMG-ét
	int getHp()const;	///< Lekéri a hõs HP-ját
	static void harc(Szorny &,Szorny &); ///< A parancsori argumentumban megadott két hõst harcoltatja
	double getSpeed()const;	///< Lekéri a hõs atackspeedjét
	std::string getName()const;		///< Lekéri a hõs nevét
	static Szorny parseUnit(const std::string);	///< Beolvassa a hõs értékeit
private:
	std::string nev; ///< A hõs neve
	int hp; 	///< A hõs életpontjai
	int dmg;	///< A hõs ütésének erõsege
	double speed;	///< A hõs ütéseinek gyorsasága
	void tamad(Szorny &)const; ///< Egy darab ütést visz be
};
