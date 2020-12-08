#include "MarkedMap.h"

bool is_digits(const std::string &str)
{
    return std::all_of(str.begin(), str.end(), ::isdigit); // C++11
}

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

int MarkedMap::getMonsterNumber() {
    int monsterNumber = 1;

    for (unsigned int i = 0; i < palya.size(); i++) {
		for (unsigned int j = 0; j < palya[i].size(); j++) {
			if (isdigit(palya[i][j])) {
                if (std::stoi(&palya[i][j]) > monsterNumber)
                    monsterNumber = std::stoi(&palya[i][j]);
			}
		}
	}

    return monsterNumber;
}
