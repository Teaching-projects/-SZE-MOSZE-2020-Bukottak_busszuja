/**
 * \Class MarkedMap
 *
 * \brief MarkedMap Class
 *
 * \author Habán András, Tranta Máté, Tóth Norbert
 *
 * Created on: 2020/12/07 18:30
*/
#ifndef MARKEDMAP_H
#define MARKEDMAP_H

#include "Map.h"
#include <regex>

typedef struct Koordinata { ///< Pálya koordinátája
	int x;   
	int y;	 
}Koordinata;

class MarkedMap :public Map
{
public:
	MarkedMap(const std::string &fajlnev) :Map(fajlnev) {} 		///< MarkedMap konstruktora
	virtual ~MarkedMap();										///< MarkedMap destruktora
	Koordinata getHeroPosition();								///< Visszaadja a pályán lévõ hõs koordinátáját
	std::vector<Koordinata> getMonsterPositions(char c) const;	///< Vektor ami tárolja a pályán lévõ adott tipusú szörnyek koordinátáit
	int getMonsterNumber();										///< Lekéri a pályán lévõ szörnyek típusának számát
};

#endif
