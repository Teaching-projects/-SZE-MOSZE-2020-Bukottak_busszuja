#include "Monster.h"

int Monster::getDamage()const {
	return dmg;
}

int Monster::getMaxHealthPoints()const {
	return maxhp;
}

int Monster::getHealthPoints()const {
	return hp;
}

std::string Monster::getName()const {
	return nev;
}

double Monster::getAttackCoolDown() const {
	return speed;
}

void Monster::tamad(Monster* a) {
	a->hp = a->hp - this->dmg;
	if (a->hp < 0) a->hp = 0;
}


Monster Monster::parse(const std::string& json) {
    JSON parsedJSON = JSON::parseFromFile(json);
	std::string name = parsedJSON.getErtek("name");
	int hp = stoi(parsedJSON.getErtek("health_points"));
	int dmg = stoi(parsedJSON.getErtek("damage"));
  	double speed = stod(parsedJSON.getErtek("attack_cooldown"));
	return Monster(name ,hp ,dmg ,speed);
}

Monster& Monster::operator=(const Monster &szorny) {
    maxhp = szorny.getMaxHealthPoints();
    hp = szorny.getHealthPoints();
    dmg = szorny.getDamage();
    nev = szorny.getName();
    speed = szorny.getAttackCoolDown();
    return *this;
}

void Monster::fightTilDeath(Monster& other) {
    double aspThis = this->getAttackCoolDown();
    double aspOther = other.getAttackCoolDown();
    bool a = false;

    while (this->isAlive() && other.isAlive()) {

        if (aspThis == aspOther) {

            if (a) {

                this->tamad(&other);
                if (other.isAlive()) {
                    other.tamad(this);
                    aspThis = this->getAttackCoolDown();
                    aspOther = other.getAttackCoolDown();
                    a = false;
                }

            } else {

                other.tamad(this);
                if (this->isAlive()) {
                    this->tamad(&other);
                    aspThis = this->getAttackCoolDown();
                    aspOther = other.getAttackCoolDown();
                    a = true;
                }
            }

        } else if (aspThis < aspOther) {
            this->tamad(&other);
            aspOther -= aspThis;
            aspThis = this->getAttackCoolDown();
            a = false;

        } else if (aspThis > aspOther) {
            other.tamad(this);
            aspThis -= aspOther;
            aspOther = other.getAttackCoolDown();
            a = true;
        }

    }

}

bool Monster::isAlive() const {
	return hp > 0;
}
