#include "MarkedMap.h"

MarkedMap::~MarkedMap()
{
	palya.clear();
}

Koordinata MarkedMap::getHeroPosition() {
	Koordinata hos;
	for (unsigned int i = 0; i < palya.size(); i++) {
		for (unsigned int j = 0; j < palya[i].size(); j++) {
			if (palya[i][j] == 'H') {
				hos.x = j;
				hos.y = i;
			}
		}
	}
	return hos;
}

std::vector<Koordinata>MarkedMap::getMonsterPositions(char c)const {
	std::vector<Koordinata> v;
	for (unsigned int i = 0; i < palya.size(); i++) {
		for (unsigned int j = 0; j < palya[i].size(); j++) {
			if (palya[i][j] == c) {
				Koordinata szorny;
				szorny.x = j;
				szorny.y = i;
				v.push_back(szorny);
			}
		}
	}
	return v;
}