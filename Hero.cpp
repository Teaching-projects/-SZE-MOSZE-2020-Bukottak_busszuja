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
    speed *= speedPerLvl;
}

void Hero::xpGain(int gain) {
    xp += gain;
    while (xp >= xpPerLvl) {
        lvlUp();
    }
}

void Hero::tamad(Monster* a) {
    int gain = dmg;
	if (dmg > a->hp) gain = a->hp;
	a->hp = a->hp - this->dmg;
	xpGain(gain);
	if (a->hp < 0) a->hp = 0;
}

Hero Hero::parse(const std::string& json) {
    JSON parsedJSON = JSON::parseFromFile(json);
	std::string name = parsedJSON.getErtek("name");
	int hp = stoi(parsedJSON.getErtek("base_health_points"));
	int dmg = stoi(parsedJSON.getErtek("base_damage"));
	int xpPerLvl = stoi(parsedJSON.getErtek("experience_per_level"));
	int hpPerLvl = stoi(parsedJSON.getErtek("health_point_bonus_per_level"));
	int dmgPerLvl = stoi(parsedJSON.getErtek("damage_bonus_per_level"));
  	double speed = stod(parsedJSON.getErtek("base_attack_cooldown"));
  	double speedPerLvl = stod(parsedJSON.getErtek("cooldown_multiplier_per_level"));
	return Hero(name , hp, dmg, speed, xpPerLvl, hpPerLvl, dmgPerLvl, speedPerLvl);
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


