#include "Hero.h"
#include <math.h>

#define XPTOLVL 100

int Hero::getXp()const {
	return xp;
}

int Hero::getLevel()const {
	return lvl;
}

void Hero::lvlUp() {
    xp = xp-xpPerLvl;
    lvl++;
    maxhp += hpPerLvl;
    hp = maxhp;
    dmg += dmgPerLvl;
    def += defPerLvl;
    speed *= speedPerLvl;
}

void Hero::xpGain(int gain) {
    xp += gain;
    while (xp >= xpPerLvl) {
        lvlUp();
    }
}

void Hero::tamad(Monster* a) {
    if (this->dmg > a->def)
    {
        int gain = this->dmg - a->def;
        if ((this->dmg - a->def) > a->hp) gain = a->hp;
        a->hp = a->hp - (this->dmg - a->def);
        xpGain(gain);
    }

	if (a->hp < 0) a->hp = 0;
}

Hero Hero::parse(const std::string& json) {
    std::vector <std::string> keysNeeded {"experience_per_level","health_point_bonus_per_level", "damage_bonus_per_level", "cooldown_multiplier_per_level","name", "base_health_points", "base_damage", "base_attack_cooldown", "base_defense", "defense_bonus_per_level"};
    JSON parsedJSON = JSON::parseFromFile(json);

    bool okay = true;
    	for (auto key : keysNeeded)
        	if(!parsedJSON.count(key))
			okay = false;

	if (okay) {

        std::string name = parsedJSON.get<std::string>("name");
        int hp = parsedJSON.get<int>("base_health_points");
        int dmg = parsedJSON.get<int>("base_damage");
        int def = parsedJSON.get<int>("base_defense");
        int xpPerLvl = parsedJSON.get<int>("experience_per_level");
        int hpPerLvl = parsedJSON.get<int>("health_point_bonus_per_level");
        int dmgPerLvl = parsedJSON.get<int>("damage_bonus_per_level");
        int defPerLvl = parsedJSON.get<int>("defense_bonus_per_level");
        double speed = parsedJSON.get<double>("base_attack_cooldown");
        double speedPerLvl = parsedJSON.get<double>("cooldown_multiplier_per_level");

        return Hero(name , hp, dmg, def, speed, xpPerLvl, hpPerLvl, dmgPerLvl, defPerLvl, speedPerLvl);
	}
	else throw JSON::ParseException("Incorrect attributes in " + json + "!");
}

/*Hero& Hero::operator=(const Hero &other) {
    maxhp = other.getMaxHealthPoints();
    hp = other.getHealthPoints();
    dmg = other.getDamage();
    def = other.getDefense();
    nev = other.getName();
    speed = other.getAttackCoolDown();
    xp = 0;
    lvl = 1;
    xpPerLvl = other.xpPerLvl;
    dmgPerLvl = other.dmgPerLvl;
    defPerLvl = other.defPerLvl;
    speedPerLvl = other.speedPerLvl;
    return *this;
}*/


