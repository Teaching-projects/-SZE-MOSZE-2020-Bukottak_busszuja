#ifndef MARKEDMAP_H
#define MARKEDMAP_H

#include "Map.h"

typedef struct Koordinata {
	int x;
	int y;
}Koordinata;

class MarkedMap :public Map
{
public:
	MarkedMap(std::string fajlnev) :Map(fajlnev) {}
	virtual ~MarkedMap();
	Koordinata getHeroPosition();
	std::vector<Koordinata> getMonsterPositions(char c) const;

};
#endif
