#include <iostream>
#include <map>
#include <string>
#include <filesystem>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <list>

#include "JSON.h"
#include "Hero.h"
#include "Monster.h"
#include "Game.h"
#include "Map.h"
#include "PreparedGame.h"

enum mode {
    Scenario,
    Test
};

const std::map<std::string, mode> modes = {
    {"scenario", mode::Scenario},
    {"test", mode::Test},
};

const std::map<int,std::string> error_messages = {
    { 1 , "Bad number of arguments. Only a mode and a single scenario file should be provided." },
    { 2 , "The provided scenario file is not accessible." },
    { 3 , "The provided scenario file is invalid." },
    { 4 , "JSON parsing error." },
    { 5 , "The provided mode is invalid (scenario / test)"}
};

void bad_exit(int exitcode){
    std::cerr
        << (error_messages.count(exitcode) ? error_messages.at(exitcode) : "Unknown error")
        << std::endl;
    exit(exitcode);
}

void scenarioMode(std::string scenarioFile) {
    if (!std::filesystem::exists(scenarioFile)) bad_exit(3);

    try {
        PreparedGame game(scenarioFile);
        game.run();
    } catch (const JSON::ParseException& e) {bad_exit(4);}

}

void testMode() {
    Damage dhero, dmonster;
    dhero.physical = 3;
    dhero.magical = 1;
    dmonster.physical = 0;
    dmonster.magical = 0;
    Game jatek("markedmap.txt");
    MarkedMap palya("markedmap.txt");
    jatek.setMap(palya);
    Hero hos("Prince Aidan of Khanduras", 30, dhero, 1, 1.1, 20, 5, 1, 1, 1, 0.9, 1, 1);
    Monster monster1("Training Dummy", 250, dmonster, 1, 2.0);
    int heroX = palya.getHeroPosition().x;
    int heroY = palya.getHeroPosition().y;
    int monster1X = palya.getMonsterPositions('1').back().x;
    int monster1Y = palya.getMonsterPositions('1').back().y;
    jatek.putHero(hos,heroX,heroY);
    jatek.putMonster(monster1,monster1X,monster1Y);
    jatek.run();
}

//usage <mode> <scenario file>
int main(int argc, char **argv)
{
    if (argc != 3) bad_exit(1);

    if (!modes.count(argv[1])) bad_exit(5);

    switch (modes.at(argv[1])) {
    case mode::Scenario:
        scenarioMode(argv[2]);
        break;

    case mode::Test:
        testMode();
        break;
    }

    return 0;
}
