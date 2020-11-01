/**
 * \class Szorny
 *
 * \brief Szorny class
 *
 * \author Haban Andras, Tranta Mate, To�th Norbert
 *
 * Created on: 2020/10/14 17:15
*/
#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include <cmath>
#include "Jsonparser.h"  

class Szorny {
    protected:
        std::string nev;                                                                                                    ///< A szony neve
        int maxhp;                                                                                                          ///< A szony maximum eletpontja
        int hp;                                                                                                             ///< A szorny eletpontjai
        int dmg;                                                                                                            ///< A szorny utesenek erosege
        double speed;                                                                                                       ///< A szorny uteseinek gyorsasaga
        virtual void tamad(Szorny&);                                                                                          ///< Egy darab ütést visz be
        friend class Kalandor;
    public:
        Szorny(std::string nev, int hp, int dmg, double speed) :nev(nev), maxhp(hp), hp(maxhp), dmg(dmg), speed(speed) {}   ///< Szorny osztaly konstruktora
        int getDmg()const;                                                                                                  ///< Lekeri a szorny sebzeset
        int getMaxHp() const;                                                                                               ///< Lekeri a szorny maximum HP-jat
        int getHp()const;                                                                                                   ///< Lekeri a szorny HP-jat
        double getSpeed()const;                                                                                             ///< Lekeri a szorny atackspeedjet
        std::string getName()const;                                                                                         ///< Lekeri a szorny nevet
        static Szorny parseUnit(Jsonparser &);                                                               ///< Beolvassa a szorny ertekeit
        Szorny& operator=(const Szorny&);                                                                                   ///< Lehetove teszi egy szorny ertekeinek beallitasat egy masikera
        Szorny(const Szorny& s2) : nev(s2.nev), maxhp(s2.maxhp), hp(s2.hp), dmg(s2.dmg), speed(s2.speed) {};                ///< Lehetove teszi egy szorny letrehozasat egy masiknak a lemasolasaval
        static void harc(Szorny &,Szorny &);                                                                                ///< A parancsori argumentumban megadott két hõst harcoltatja
};
