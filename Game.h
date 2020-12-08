/**
 * \class Game
 *
 * \brief Game class
 *
 * \author Hab�n Andr�s, Tranta M�t�, T�th Norbert
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
	Monster *monster; 						///< Sz�rny strukt�r�ja a j�t�kban
	int posx;								
	int posy;
};

struct Arenahos {
	Hero *hero;							 	///< H�s strukt�r�ja a j�t�kban
	int posx;
	int posy;
};

class Game {								
public:
    Game(): terkep(Map()) {};												///< Egy j�t�kot inicializ�l �res t�rk�ppel
	Game(const std::string& mapFileName) : terkep(Map(mapFileName)) {};		///< Egy j�t�kot inicializ�l egy megadott t�rk�ppel
	void setMap(Map map);													///< Egy j�t�khoz t�rk�pet rendel
	void putHero(Hero &hero, int x, int y);									///< Egy h�st elhelyez a t�rk�pen a j�t�kon bel�l
	void putMonster(Monster &monster, int x, int y);						///< Egy sz�rnyet elhelyez a t�rk�pen a j�t�kon bel�l 
	int getMonsterdb(int x, int y);											///< Lek�ri a sz�rnyek sz�m�t egy adott pozicion
	void run();																///< Elind�tja a j�t�kot

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
	Map terkep;															///< P�lya t�rk�p
	std::vector <Arenaszorny> arenaszornyek;							///< J�t�kban szerepl� sz�rnyek
	Arenahos hos;														///< J�t�kban szerepl� h�s
	bool mapready = false;												///< V�ltoz� ami megadja, hogy van-e p�lya rendelve a j�t�khoz
	bool heroready = false;												///< V�ltoz� ami megadja, hogy van-e h�s a j�t�khoz rendelve
	bool monsterready = false;											///< V�ltoz� ami megadja, hogy van-e sz�rny rendelve a j�t�khoz
	bool gamerunning = false;											///< V�ltoz� ami megadja, hogy van-e �ppen fut� j�t�k
	void CheckForFight();												///< leellen�rzi, hogy a h�s pozici�j�n van-e sz�rny �s ha van akkor k�zdelmet ind�t 
	void drawmap();														///< kirajzolja a p�ly�t a kimenetre
	void readInput();													///< felhaszn�l� imputj�t v�rja �s az alapj�n mozgat h�st
	void TranslateUserInput(char, int&, int&, bool&);					///< az inputot alak�tja mozg�ss�

};

#endif
