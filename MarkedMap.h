/**
 * \Class MarkedMap
 *
 * \brief MarkedMap Class
 *
 * \author Haban Andras, Tranta Mate, Toth Norbert
 *
 * Created on: 2020/12/07 18:30
*/
#ifndef MARKEDMAP_H
#define MARKEDMAP_H

#include "Map.h"
#include <regex>

typedef struct Koordinata { ///< Palya koordinataja
	int x;   
	int y;	 
}Koordinata;

class MarkedMap :public Map
{
public:
	MarkedMap(const std::string &fajlnev) :Map(fajlnev) {} 		///< MarkedMap konstruktora
	virtual ~MarkedMap();										///< MarkedMap destruktora
	Koordinata getHeroPosition();								///< Visszaadja a palyan levo hos koordinatajat
	std::vector<Koordinata> getMonsterPositions(char c) const;	///< Vektor ami tarolja a palyan levo adott tipusu szornyek koordinatait
	int getMonsterNumber();										///< Lekeri a palyan levo szornyek tipusanak szamat
};

#endif
