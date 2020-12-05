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

    std::string hero_file;
    std::list<std::string> monster_files;

    try {
        JSON scenario = JSON::parseFromFile(scenarioFile);
        if (!(scenario.count("hero") && scenario.count("monsters")))
            bad_exit(3);
        else {
            hero_file = scenario.get<std::string>("hero");
            JSON::list monster_file_list = scenario.get<JSON::list>("monsters");
            for (auto monster_file : monster_file_list)
                monster_files.push_back(std::get<std::string>(monster_file));
        }
    }
    catch (const JSON::ParseException &e) {
        bad_exit(4);
    }

    try {
        Hero hero{Hero::parse(hero_file)};
        std::list<Monster> monsters;
        for (const auto &monster_file : monster_files)
            monsters.push_back(Monster::parse(monster_file));

        Map palya("palya1.txt");

        Game jatek;

        jatek.setMap(palya);

        jatek.putHero(hero, 1, 1);

        jatek.putMonster(monsters.front(), 4, 0);
        if (monsters.size() >= 4) {
            monsters.pop_front();
            monsters.pop_front();
            jatek.putMonster(monsters.front(), 3, 0);
        }

        jatek.run();
    }
    catch (const JSON::ParseException &e) {
        bad_exit(4);
    }
}

void testMode(std::string mapname) {
    Damage dhero, dmonster;
    dhero.physical = 3;
    dhero.magical = 1;
    dmonster.physical = 0;
    dmonster.magical = 0;
    Game jatek;
    Map palya(mapname);
    jatek.setMap(palya);
    Hero hos("Prince Aidan of Khanduras", 30, dhero, 1, 1.1, 20, 5, 1, 1, 1, 0.9, 1, 1);
    Monster monster1("Training Dummy", 250, dmonster, 1, 2.0);
    Monster monster2("Training Dummy", 250, dmonster, 1, 2.0);
    jatek.putHero(hos,1,1);
    if (mapname == "testmap.txt") {
        jatek.putMonster(monster1,3,1);
    } else if (mapname == "testmap2.txt") {
        jatek.putMonster(monster1,4,1);
        jatek.putMonster(monster2,1,3);
    }

    jatek.run();
}

//usage scenario    <scenario file>
//      test        <mapfile>
int main(int argc, char **argv)
{
    if (argc != 3) bad_exit(1);

    if (!modes.count(argv[1])) bad_exit(5);

    switch (modes.at(argv[1])) {
    case mode::Scenario:
        scenarioMode(argv[2]);
        break;

    case mode::Test:
        testMode(argv[2]);
        break;
    }

    return 0;
}
