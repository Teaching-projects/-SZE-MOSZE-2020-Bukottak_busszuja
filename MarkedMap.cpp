#include "MarkedMap.h"

MarkedMap::~MarkedMap()
{
	palya.clear();
}

Koordinata MarkedMap::getHeroPosition() {
	Koordinata heroCoord;
	for (unsigned int i = 0; i < palya.size(); i++) {
		for (unsigned int j = 0; j < palya[i].size(); j++) {
			if (palya[i][j] == 'H') {
				heroCoord.x = j;
				heroCoord.y = i;
			}
		}
	}
	return heroCoord;
}

std::vector<Koordinata>MarkedMap::getMonsterPositions(char c)const {
	std::vector<Koordinata> monsterCoordVector;
	for (unsigned int i = 0; i < palya.size(); i++) {
		for (unsigned int j = 0; j < palya[i].size(); j++) {
			if (palya[i][j] == c) {
				Koordinata monsterCoord;
				monsterCoord.x = j;
				monsterCoord.y = i;
				monsterCoordVector.push_back(monsterCoord);
			}
		}
	}
	return monsterCoordVector;
}
