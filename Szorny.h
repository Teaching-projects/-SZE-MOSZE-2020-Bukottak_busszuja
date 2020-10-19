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

class Szorny {
protected:
	std::string nev; ///< A hõs neve
  int maxhp; ///< A hõs maximum életpontja
  int hp; 	///< A hõs életpontjai
  int dmg;	///< A hõs ütésének erõsege
  double speed;	///< A hõs ütéseinek gyorsasága
  void tamad(Szorny &)const; ///< Egy darab ütést visz be
  friend class Kalandor;
public:
	Szorny(std::string nev, int hp, int dmg, double speed) :nev(nev), maxhp(hp), hp(maxhp), dmg(dmg), speed(speed) {}  ///< Szörny osztály konstruktora
	int getDmg()const;	///< Lekéri a hõs DMG-ét
  int getMaxHp() const; ///< Lekéri a hõs maximum HP-ját
	int getHp()const;	///< Lekéri a hõs HP-ját
	static void harc(Szorny &,Szorny &); ///< A parancsori argumentumban megadott két hõst harcoltatja
	double getSpeed()const;	///< Lekéri a hõs atackspeedjét
	std::string getName()const;		///< Lekéri a hõs nevét
	static Szorny parseUnit(const std::string &filename);	///< Beolvassa a hõs értékeit
  Szorny& operator=(const Szorny&); ///< Lehetővé teszi egy hõs értékeinek beállítását egy másikéra
  Szorny(const Szorny& s2) : nev(s2.nev), maxhp(s2.maxhp), hp(s2.hp), dmg(s2.dmg), speed(s2.speed) {}; ///< Lehetővé teszi egy hõs létrehozását egy másiknak a lemásolásával
};
