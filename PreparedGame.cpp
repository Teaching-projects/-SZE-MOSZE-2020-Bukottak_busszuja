#include <string>

#include "PreparedGame.h"
#include "MarkedMap.h"
#include "JSON.h"

PreparedGame::PreparedGame(std::string scenariofile) {
    std::vector<std::string> expectedKeys= {"map", "hero"};
    JSON scenario = JSON::parseFromFile(scenariofile);
    for (auto &&key : expectedKeys)
        if (!scenario.count(key))
            throw JSON::ParseException("Missing keys.");

    MarkedMap scenario_map(scenario.get<std::string>("map"));
    setMap(scenario_map);
    Hero heroToPut = Hero::parse(scenario.get<std::string>("hero"));
    int heroX = scenario_map.getHeroPosition().x;
    int heroY = scenario_map.getHeroPosition().y;
    putHero(heroToPut,heroX, heroY);
    std::cerr<<heroToPut.getName()<<std::endl;
    std::cerr<<heroToPut.getAttackCoolDown()<<std::endl;
    //std::cerr<<heroToPut.getDamage()<<std::endl;
    std::cerr<<heroToPut.getDefense()<<std::endl;
    std::cerr<<heroToPut.getHealthPoints()<<std::endl;
    std::cerr<<heroToPut.getLevel()<<std::endl;
    std::cerr<<heroToPut.getMaxHealthPoints()<<std::endl;

    int maxMonsterNumber = scenario_map.getMonsterNumber();
    for (int i = 1; i <= maxMonsterNumber; i++)
    {
        std::string monsterName = "monster-"+std::to_string(i);
        std::cerr<<monsterName << std::endl << std::endl;
        if (scenario.count(monsterName))
        {
            std::string sIdx = std::to_string(i);
            char cIdx = sIdx[0];
            std::vector<Koordinata> monsterPositions = scenario_map.getMonsterPositions(cIdx);
            for (unsigned int i = 0; i < monsterPositions.size(); i++)
            {
                Monster monsterToPut = Monster::parse(scenario.get<std::string>(monsterName));
                std::cerr<<monsterToPut.getName() << std::endl << std::endl;
                putMonster(monsterToPut, monsterPositions[i].x, monsterPositions[i].y);
                //std::cerr<<hos.hero->getName();
            }
        }
    }
}
