#include "Game.h"

void Game::setMap(Map map) {
	if (gamerunning)throw GameAlreadyStartedException("A jatek mar elindult,mar nem lehet palyat megadni!");
	if (heroready || monsterready) throw AlreadyHasUnitsException("Van mar palyaterkep,ami mar rendelkezik egysegekkel!");
	terkep = map;

	mapready = true;
	heroready = false;
	monsterready = false;
	gamerunning = false;
}

void Game::putHero(Hero &hero, int x, int y) {
	if (gamerunning)throw GameAlreadyStartedException("A jatek mar elindult,mar nem lehet feltenni host!");
	if (mapready == false)throw Map::WrongIndexException("Meg nincs palyaterkep beallitva!");
	if (heroready)throw AlreadyHasHeroException("Mar egy hos van az arenaban!");
	if (terkep.get(x, y) == Map::type::Wall) throw OccupiedException("Falra nem kerulhet Hero!");
	hos.hero = new Hero(hero);
	hos.posx = x;
	hos.posy = y;
	heroready = true;
}

void Game::putMonster(Monster &monster, int x, int y) {
	if (mapready == false)throw Map::WrongIndexException("Meg nincs palyaterkep beallitva!");
	if (terkep.get(x, y) == Map::type::Wall) throw OccupiedException("Falra nem kerulhet Monster!");
	Arenaszorny s;
	s.monster = new Monster(monster);
	s.posx = x;
	s.posy = y;
	arenaszornyek.push_back(s);
	monsterready = true;
}

void Game::run() {
	if (mapready == false || heroready == false) throw NotInitializedException("Nem indithato a jatek, nincs megadva palya vagy hos!");
	gamerunning = true;

	while (gamerunning) {
        drawmap();
        std::cout << std::endl;
        CheckForFight();

        if (hos.hero->isAlive() && arenaszornyek.size() != 0) {
            readInput();
        } else {
            gamerunning = false;
        }
	}

	if (hos.hero->isAlive()) {
        std::cout << hos.hero->getName() + " cleared the map." << std::endl;

    }
    else {
        std::cout << hos.hero->getName() + " died." << std::endl;
    }

    std::cout << std::endl << "  LVL: " << hos.hero->getLevel() << std::endl
                  << "   HP: " << hos.hero->getHealthPoints() << "/" << hos.hero->getMaxHealthPoints() << std::endl
                  << "  DMG: " << hos.hero->getDamage() << std::endl
                  << "  DEF: " << hos.hero->getDefense() << std::endl
                  << "  ACD: " << hos.hero->getAttackCoolDown() << std::endl;
}

void Game::CheckForFight() {
    int heroX = hos.posx;
    int heroY = hos.posy;
    Hero tmphero = *hos.hero;



    for (int i = 0; i <(int)arenaszornyek.size(); i++) {
        if (arenaszornyek[i].posx == heroX && arenaszornyek[i].posy == heroY) {
            std::cout << hos.hero->getName() << "(" << hos.hero->getLevel() << ") vs " << arenaszornyek[i].monster->getName() << std::endl << std::endl;
            hos.hero->fightTilDeath(*arenaszornyek[i].monster);
            if (arenaszornyek[i].monster->isAlive() == false) arenaszornyek.erase(arenaszornyek.begin()+i);
        }
    }
}

void Game::drawmap() {
	int lightradius = hos.hero->getLightradius();
    int negativewidth;
    int positivewidth;
    int negativeheight;
    int positiveheight;

	if ((hos.posx - lightradius) < 0) negativewidth = 0;
	else negativewidth = hos.posx - lightradius;

	if ((hos.posx + lightradius) > terkep.getSzelesseg()) positivewidth = terkep.getSzelesseg()- 1;
	else positivewidth = hos.posx + lightradius;

	if ((hos.posy - lightradius) < 0) negativeheight = 0;
	else negativeheight = hos.posy - lightradius;

	if ((hos.posy + lightradius) > terkep.getMagassag()) positiveheight = terkep.getMagassag() - 1;
	else positiveheight = hos.posy + lightradius;

	std::cout << "╔" << "═";
	for (int i = negativewidth; i <= positivewidth; i++) std::cout << "═" << "═";
	std::cout << "═" << "╗" << std::endl;
	for (int i = negativeheight; i <= positiveheight; i++) {
		std::cout << "║" << "║";
		for (int j = negativewidth; j <= positivewidth; j++) {
			try {
				if (terkep.get(j, i) == Map::type::Wall) std::cout << "█" << "█";
				else if (hos.posx == j && hos.posy == i) std::cout << "┣" << "┫";
				else {
					int monsterdb = getMonsterdb(j,i);
					if (monsterdb == 1) std::cout << "M" << "░";
					else if (monsterdb > 1) std::cout << "MM";
					else std::cout << "░" << "░";
				}
			}
			catch (Map::WrongIndexException& e) { std::cout << "░" << "░"; }
		}
		std::cout << "║" << "║" <<std::endl;
	}
	std::cout << "╚" << "═";
	for (int i = negativewidth; i <= positivewidth; i++) std::cout << "═" << "═";
	std::cout << "═" << "╝" << std::endl;

}

void Game::readInput() {
    bool correctMove = false;
    bool correctInput = false;

    int heroX = hos.posx;
    int heroY = hos.posy;
    int difX = 0, difY = 0;
    char way;

    while (!correctMove)
    {
        while (!correctInput)
        {
            std::cout << "Which way do you wish to go?" << std::endl << "(N)orth, (S)outh, (E)ast, (W)est" << std::endl;
            std::cin >> way;
            std::cout << std::endl;
            TranslateUserInput(way, difX, difY, correctInput);
        }

        if (terkep.get(heroX + difX, heroY + difY) != Map::type::Wall)
            correctMove = true;
        else {
            correctInput = false;
            std::cout << "That move is not feasible. There's an obstacle." << std::endl;
        }
    }
    hos.posx += difX;
    hos.posy += difY;
}

void Game::TranslateUserInput (char way, int &difX, int &difY, bool &correctInput) {
    switch (way) {
    case 'W':
        difX = -1;
        difY = 0;
        correctInput = true;
        break;
    case 'w':
        difX = -1;
        difY = 0;
        correctInput = true;
        break;
    case 'S':
        difX = 0;
        difY = 1;
        correctInput = true;
        break;
    case 's':
        difX = 0;
        difY = 1;
        correctInput = true;
        break;
    case 'E':
        difX = 1;
        difY = 0;
        correctInput = true;
        break;
    case 'e':
        difX = 1;
        difY = 0;
        correctInput = true;
        break;
    case 'N':
        difX = 0;
        difY = -1;
        correctInput = true;
        break;
    case 'n':
        difX = 0;
        difY = -1;
        correctInput = true;
        break;
    default:
        std::cout << "Incorrect move, please try again!" << std::endl;
        break;
    }
}

int Game::getMonsterdb(int x,int y) {
	int db = 0;
	for (int i = 0; i <(int)arenaszornyek.size(); i++) {
		if (arenaszornyek[i].posx == x && arenaszornyek[i].posy == y) db++;
	}
	return db;
}
