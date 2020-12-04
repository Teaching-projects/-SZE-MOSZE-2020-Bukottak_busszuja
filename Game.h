#ifndef GAME_H
#define GAME_H

#include "Monster.h"
#include "Hero.h"
#include "Map.h"
#include <vector>

struct Arenaszorny {
	Monster *monster;
	int posx;
	int posy;
};

struct Arenahos {
	Hero *hero;
	int posx;
	int posy;
};

class Game {
public:
	Game():mapready(false),heroready(false),monsterready(false),gamerunning(false){}
	Game(std::string);
	void setMap(Map map);
	void putHero(Hero &hero, int x, int y);
	void putMonster(Monster &monster, int x, int y);
	int getMonsterdb(int x, int y);
	void run();

	class AlreadyHasHeroException : public std::runtime_error {
        public:
            AlreadyHasHeroException(const std::string& hibauzenet) : std::runtime_error(hibauzenet) {}
	};

	class AlreadyHasUnitsException : public std::runtime_error {
        public:
            AlreadyHasUnitsException(const std::string& hibauzenet) : std::runtime_error(hibauzenet) {}
	};

	class OccupiedException : public std::runtime_error {
        public:
            OccupiedException(const std::string& hibauzenet) : std::runtime_error(hibauzenet) {}
	};

	class NotInitializedException : public std::runtime_error {
        public:
            NotInitializedException(const std::string& hibauzenet) : std::runtime_error(hibauzenet) {}
	};

	class GameAlreadyStartedException : public std::runtime_error {
        public:
            GameAlreadyStartedException(const std::string& hibauzenet) : std::runtime_error(hibauzenet) {}
	};
private:
	Map terkep;
	std::vector <Arenaszorny> arenaszornyek;
	Arenahos hos;
	bool mapready;
	bool heroready;
	bool monsterready;
	bool gamerunning;
	void CheckForFight();
	void drawmap();
	void readInput();
	void TranslateUserInput(char, int&, int&, bool&);

};

#endif
