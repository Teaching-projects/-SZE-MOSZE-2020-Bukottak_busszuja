#include "Map.h"
#include<fstream>

Map::Map(const std::string & filename) {
	std::ifstream f(filename);
	std::string sor;
	if (f.is_open()) {
		while (!f.eof()) {
			getline(f, sor);
			palya.push_back(sor);
		}
		f.close();
	}
	else throw WrongIndexException("Nem letezo fajl lett megadva!");
}

void Map::kiir()const {
	for (int i = 0; i < palya.size(); i++) {
		std::cout << palya[i] << std::endl;
	}
}

Map::~Map()
{
	palya.clear();
}


Map::type Map::get(int x, int y) const {
	if (y >= palya.size() || y < 0 || x < 0 || x >= palya[y].length()) throw WrongIndexException("Nem letezo index lett megadva!");
	if (palya[y][x] == ' ') return Map::type::Free;
	if (palya[y][x] == '#') return Map::type::Wall;
}