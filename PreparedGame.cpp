#include <string>

#include "PreparedGame.h"
#include "MarkedMap.h"
#include "JSON.h"

PreparedGame::PreparedGame(std::string scenariofile) {
    std::vector<std::string> expectedKeys= {"map", "hero"};
    std::string hero_file, monster_file;
    JSON scenario = JSON::parseFromFile(scenariofile);
    for (auto &&key : expectedKeys)
        if (!scenario.count(key))
            throw JSON::ParseException("Missing keys.");

    MarkedMap scenario_map(scenario.get<std::string>("map"));
    setMap(scenario_map);

    hero_file = scenario.get<std::string>("hero");
    Hero heroToPut{Hero::parse(hero_file)};
    int heroX = scenario_map.getHeroPosition().x;
    int heroY = scenario_map.getHeroPosition().y;
    putHero(heroToPut,heroX, heroY);

    int maxMonsterNumber = scenario_map.getMonsterNumber();
    for (int i = 1; i <= maxMonsterNumber; i++)
    {
        std::string monsterName = "monster-"+std::to_string(i);
        if (scenario.count(monsterName))
        {
            std::string sIdx = std::to_string(i);
            char cIdx = sIdx[0];
            std::vector<Koordinata> monsterPositions = scenario_map.getMonsterPositions(cIdx);
            for (unsigned int i = 0; i < monsterPositions.size(); i++)
            {
                monster_file = scenario.get<std::string>(monsterName);
                Monster monsterToPut = Monster::parse(monster_file);
                putMonster(monsterToPut, monsterPositions[i].x, monsterPositions[i].y);

            }
        }
    }

}
