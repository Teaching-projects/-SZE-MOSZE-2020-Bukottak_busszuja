/**
 * \class Game
 *
 * \brief Game class
 *
 * \author Habán András, Tranta Máté, Tóth Norbert
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
	Monster *monster; 						///< Szörny struktúrája a játékban
	int posx;								
	int posy;
};

struct Arenahos {
	Hero *hero;							 	///< Hõs struktúrája a játékban
	int posx;
	int posy;
};

class Game {								
public:
    Game(): terkep(Map()) {};												///< Egy játékot inicializál üres térképpel
	Game(const std::string& mapFileName) : terkep(Map(mapFileName)) {};		///< Egy játékot inicializál egy megadott térképpel
	void setMap(Map map);													///< Egy játékhoz térképet rendel
	void putHero(Hero &hero, int x, int y);									///< Egy hõst elhelyez a térképen a játékon belül
	void putMonster(Monster &monster, int x, int y);						///< Egy szörnyet elhelyez a térképen a játékon belül 
	int getMonsterdb(int x, int y);											///< Lekéri a szörnyek számát egy adott pozicion
	void run();																///< Elindítja a játékot

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
	Map terkep;															///< Pálya térkép
	std::vector <Arenaszorny> arenaszornyek;							///< Játékban szereplõ szörnyek
	Arenahos hos;														///< Játékban szereplõ hõs
	bool mapready = false;												///< Változó ami megadja, hogy van-e pálya rendelve a játékhoz
	bool heroready = false;												///< Változó ami megadja, hogy van-e hõs a játékhoz rendelve
	bool monsterready = false;											///< Változó ami megadja, hogy van-e szörny rendelve a játékhoz
	bool gamerunning = false;											///< Változó ami megadja, hogy van-e éppen futó játék
	void CheckForFight();												///< leellenõrzi, hogy a hõs pozicióján van-e szörny és ha van akkor küzdelmet indít 
	void drawmap();														///< kirajzolja a pályát a kimenetre
	void readInput();													///< felhasználó imputját várja és az alapján mozgat hõst
	void TranslateUserInput(char, int&, int&, bool&);					///< az inputot alakítja mozgássá

};

#endif
