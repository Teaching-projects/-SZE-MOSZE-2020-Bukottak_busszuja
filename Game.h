/**
 * \class Game
 *
 * \brief Game class
 *
 * \author Haban Andras, Tranta Mate, Toth Norbert
 *
 * Created on: 2020/12/07 17:38
*/
#ifndef GAME_H
#define GAME_H

#include "Monster.h"
#include "Hero.h"
#include "MarkedMap.h"
#include <vector>

struct Arenaszorny {
	Monster *monster; 						///< Szorny strukturaja a jatekban
	int posx;								
	int posy;
};

struct Arenahos {
	Hero *hero;							 	///< Hos strukturaja a jatekban
	int posx;
	int posy;
};

class Game {								
public:
    Game(): terkep(Map()) {};												///< Egy jatekot inicializal ures terkeppel
	Game(const std::string& mapFileName) : terkep(Map(mapFileName)) {};		///< Egy jatekot inicializal egy megadott terkeppel
	void setMap(Map map);													///< Egy jatekhoz terkepet rendel
	void putHero(Hero &hero, int x, int y);									///< Egy host elhelyez a terkepen a jatekon belul
	void putMonster(Monster &monster, int x, int y);						///< Egy szornyet elhelyez a terkepen a jatekon belul 
	int getMonsterdb(int x, int y);											///< Lekeri a szornyek szamat egy adott pozicion
	void run();																///< Elinditja a jatekot

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
	Map terkep;															///< Palya terkep
	std::vector <Arenaszorny> arenaszornyek;							///< Jatekban szereplo szornyek
	Arenahos hos;														///< Jatekban szereplo hos
	bool mapready = false;												///< Valtozo ami megadja, hogy van-e palya rendelve a jatekhoz
	bool heroready = false;												///< Valtozo ami megadja, hogy van-e hos a jatekhoz rendelve
	bool monsterready = false;											///< Valtozo ami megadja, hogy van-e szorny rendelve a jatekhoz
	bool gamerunning = false;											///< Változo ami megadja, hogy van-e eppen futo jaték
	void CheckForFight();												///< leellenorzi, hogy a hos poziciojan van-e szorny es ha van akkor kuzdelmet indit 
	void drawmap();														///< kirajzolja a palyat a kimenetre
	void readInput();													///< felhasznalo imputjat varja és az alapjan mozgat host
	void TranslateUserInput(char, int&, int&, bool&);					///< az inputot alakitja mozgassa

};

#endif
