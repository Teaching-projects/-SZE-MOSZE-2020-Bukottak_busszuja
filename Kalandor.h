/**
 * \class kalandor
 *
 * \brief kalandor class a szorny osztalytol abban kulonbozik hogy kepes szintlepesre
 *
 * \author Haban Andras, Tranta Mate, Toth Norbert
 *
 * Created on: 2020/10/28 11:14
*/
#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include "Szorny.h"

class Kalandor : public Szorny {
    public:
        Kalandor(const std::string& nev, int hp, int dmg, double speed, int xp=0, int lvl=1) : Szorny(nev, hp, dmg, speed), xp(xp), lvl(lvl) {}; ///< A kalandor osztaly konstruktora
        Kalandor(const Szorny& sz) : Szorny(sz.getName(), sz.getHp(), sz.getDmg(), sz.getSpeed()), xp(0), lvl(1) {}; 							 ///< Beolvassa a kalandor �rt�keit
        int getXp() const;  ///< lekeri az aktualis tapasztalatpotjait a kalandornak
        int getLvl() const; ///< lekeri az aktualis szintjet a kalandorak
        Kalandor& operator=(const Szorny&); ///< a fuggveny arra valo hogy egyenloseget lehessen teni szorny es kalandor kozott
    protected:
        int xp; 	///< A kalandor tapasztalat pontjai egesz ertek visszateressel
        int lvl;	///< A kalandor szint erteke eg�sz ertek visszateressel
        void lvlUp(int xptoLvl);	///< A szintlepest intezo fuggveny, ha eleri az xp az xptolvl-t szintet l�p
        void xpGain(int gain);	///< tapasztalat n�veked�st intezo f�ggv�ny, az xp-t gain=dmg eg�sz ertekkel noveli
        void tamad(Szorny&);	///< egy darab �t�st visz be, paramet�re egy szorny objektum
};
