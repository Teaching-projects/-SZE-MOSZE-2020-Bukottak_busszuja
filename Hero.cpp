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
    dmg.physical += dmgPerLvl;
    dmg.magical += mdmgPerLvl;
    speed *= speedPerLvl;
}

void Hero::xpGain(int gain) {
    xp += gain;
    while (xp >= xpPerLvl) {
        lvlUp();
    }
}

void Hero::tamad(Monster* a) {
    int gain = dmg.physical + dmg.magical;
	if ((dmg.physical + dmg.magical) > a->hp) gain = a->hp;
	a->hp = a->hp - (dmg.physical + dmg.magical);
	xpGain(gain);
	if (a->hp < 0) a->hp = 0;
}

Hero Hero::parse(const std::string& json) {
    std::vector <std::string> keysNeeded {"experience_per_level","health_point_bonus_per_level", "damage_bonus_per_level", "magical_damage_bonus_per_level", "cooldown_multiplier_per_level",
                                            "name", "base_health_points", "base_attack_cooldown"};
    JSON parsedJSON = JSON::parseFromFile(json);

    bool okay = true;
    	for (auto key : keysNeeded)
        	if(!parsedJSON.count(key))
			okay = false;

    Damage dmg;

    if(parsedJSON.count("damage")) dmg.physical = parsedJSON.get<int>("damage");
	else dmg.physical = 0;

	if(parsedJSON.count("magical-damage")) dmg.magical = parsedJSON.get<int>("magical-damage");
	else dmg.magical = 0;

	if (okay) {

        std::string name = parsedJSON.get<std::string>("name");
        int hp = parsedJSON.get<int>("base_health_points");
        int xpPerLvl = parsedJSON.get<int>("experience_per_level");
        int hpPerLvl = parsedJSON.get<int>("health_point_bonus_per_level");
        int dmgPerLvl = parsedJSON.get<int>("damage_bonus_per_level");
        int mdmgPerLvl = parsedJSON.get<int>("magical_damage_bonus_per_level");
        double speed = parsedJSON.get<double>("base_attack_cooldown");
        double speedPerLvl = parsedJSON.get<double>("cooldown_multiplier_per_level");

        return Hero(name , hp, dmg, speed, xpPerLvl, hpPerLvl, dmgPerLvl, mdmgPerLvl, speedPerLvl);
	}
	else throw JSON::ParseException("Incorrect attributes in " + json + "!");
}

Hero& Hero::operator=(const Monster &szorny) {
    maxhp = szorny.getMaxHealthPoints();
    hp = szorny.getHealthPoints();
    dmg = szorny.getDamage();
    nev = szorny.getName();
    speed = szorny.getAttackCoolDown();
    xp = 0;
    lvl = 1;
    return *this;
}


