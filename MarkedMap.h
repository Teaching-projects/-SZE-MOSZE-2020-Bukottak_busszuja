/**
 * \Class MarkedMap
 *
 * \brief MarkedMap Class
 *
 * \author Hab�n Andr�s, Tranta M�t�, T�th Norbert
 *
 * Created on: 2020/12/07 18:30
*/
#ifndef MARKEDMAP_H
#define MARKEDMAP_H

#include "Map.h"
#include <regex>

typedef struct Koordinata { ///< P�lya koordin�t�ja
	int x;   
	int y;	 
}Koordinata;

class MarkedMap :public Map
{
public:
	MarkedMap(const std::string &fajlnev) :Map(fajlnev) {} 		///< MarkedMap konstruktora
	virtual ~MarkedMap();										///< MarkedMap destruktora
	Koordinata getHeroPosition();								///< Visszaadja a p�ly�n l�v� h�s koordin�t�j�t
	std::vector<Koordinata> getMonsterPositions(char c) const;	///< Vektor ami t�rolja a p�ly�n l�v� adott tipus� sz�rnyek koordin�t�it
	int getMonsterNumber();										///< Lek�ri a p�ly�n l�v� sz�rnyek t�pus�nak sz�m�t
};

#endif
