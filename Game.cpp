#include "Game.h"

Game::Game(std::string terkepfajlnev) {
	Map Terkep(terkepfajlnev);
	setMap(Terkep);
}

void Game::setMap(Map map) {
	if (gamerunning)throw GameAlreadyStartedException("A jatek mar elindult,mar nem lehet palyat megadni!");
	if (heroready || monsterready) throw AlreadyHasUnitsException("Van mar palyterkep,ami mar rendelkezik egysegekkel!");
	terkep = map;
	mapready = true;
	heroready = false;
	monsterready = false;
	gamerunning = false;
}


void Game::putHero(Hero Hero, int x, int y) {
	if (gamerunning)throw GameAlreadyStartedException("A jatek mar elindult,mar nem lehet feltenni host!");
	if (mapready == false)throw Map::WrongIndexException("Meg nincs palyaterkep beallitva!");
	if (heroready)throw AlreadyHasHeroException("Mar egy hos van az arenaban!");
	if (terkep.get(x, y) == Map::type::Wall) throw OccupiedException("Falra nem kerulhet Hero!");
	hos.hero = &Hero;
	hos.posx = x;
	hos.posy = y;
	heroready = true;
}

void Game::putMonster(Monster szorny, int x, int y) {
	if (mapready == false)throw Map::WrongIndexException("Meg nincs palyaterkep beallitva!");
	if (terkep.get(x, y) == Map::type::Wall) throw OccupiedException("Falra nem kerulhet Monster!");
	Arenaszorny s;
	s.monster = &szorny;
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
        CheckForFight();

        if (hos.hero->isAlive() && arenaszornyek.size() != 0) {
            readInput();
        } else {
            gamerunning = false;
        }
	}

	if (hos.hero->isAlive())
    {
        std::cout << hos.hero->getName() + " cleared the map." << std::endl;
    }
    else
    {
        std::cout << hos.hero->getName() + " died." << std::endl;
    }
}

void Game::CheckForFight() {
    int heroX = hos.posx;
    int heroY = hos.posy;
    std::vector<int> deadMonsters;

    for (int i = 0; i <(int)arenaszornyek.size(); i++) {
        if (arenaszornyek[i].posx == heroX && arenaszornyek[i].posy == heroY) {
            hos.hero->fightTilDeath(*arenaszornyek[i].monster);
            if (arenaszornyek[i].monster->isAlive() == false) arenaszornyek.erase(arenaszornyek.begin()+i);
        }
    }
}

void Game::drawmap() {
	int szelesseg = terkep.getSzelesseg();
	int magassag = terkep.getMagassag();
	char Balfel = 201;
	char Jobbfel = 187;
	char Balle = 200;
	char Jobble = 188;
	char vizszint = 205;
	char szabad = 177;
	char fal = 178;
	char balhos = 195;
	char jobbhos = 180;
	char fuggoleges = 186;
	std::cout << Balfel;
	for (int i = 0; i < szelesseg; i++) std::cout << vizszint<<vizszint;
	std::cout <<vizszint<< Jobbfel << std::endl;
	for (int i = 0; i < magassag; i++) {
		std::cout << fuggoleges<<fuggoleges;
		for (int j = 0; j < szelesseg; j++) {
			try {
				if (terkep.get(j, i) == Map::type::Wall) std::cout << fal<<fal;
				else if (hos.posx == j && hos.posy == i) std::cout << balhos<<jobbhos;
				else {
					int monsterdb = getMonsterdb(j,i);
					if (monsterdb == 1) std::cout << "M"<<szabad;
					else if (monsterdb > 1) std::cout << "MM";
					else std::cout << szabad<<szabad;
				}
			}
			catch (Map::WrongIndexException& e) { std::cout << szabad<<szabad; }
		}
		std::cout << fuggoleges<<std::endl;
	}
	std::cout << Balle;
	for (int i = 0; i < szelesseg; i++) std::cout << vizszint<<vizszint;
	std::cout <<vizszint<< Jobble << std::endl;

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
            TranslateUserInput(way, difX, difY, correctInput);
        }

        if (terkep.get(heroX + difX, heroY + difY) == Map::type::Free)
            correctMove = true;
        else {
            correctInput = false;
            std::cout << "That move is not feasible. There's an obstacle." << std::endl;
        }
    }
    std::cerr << "Hiba";
    hos.posx += difX;
    hos.posy += difY;
}

void Game::TranslateUserInput (char way, int &difX, int &difY, bool &correctInput) {
    switch (way) {
    case 'N':
        difX = -1;
        difY = 0;
        correctInput = true;
        break;
    case 'n':
        difX = -1;
        difY = 0;
        correctInput = true;
        break;
    case 'E':
        difX = 0;
        difY = 1;
        correctInput = true;
        break;
    case 'e':
        difX = 0;
        difY = 1;
        correctInput = true;
        break;
    case 'S':
        difX = 1;
        difY = 0;
        correctInput = true;
        break;
    case 's':
        difX = 1;
        difY = 0;
        correctInput = true;
        break;
    case 'W':
        difX = 0;
        difY = -1;
        correctInput = true;
        break;
    case 'w':
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
