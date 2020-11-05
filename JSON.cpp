#include "JSON.h"
#include <set>


void JSON::Jsonprsr(std::ifstream& f) {
	std::set<std::string> keys;
	keys.insert("name");
	keys.insert("damage");
	keys.insert("health_points");
	keys.insert("attack_cooldown");
    keys.insert("monsters");

    keys.insert("base_damage");
	keys.insert("base_health_points");
	keys.insert("base_attack_cooldown");
    keys.insert("experience_per_level");
    keys.insert("health_point_bonus_per_level");
	keys.insert("damage_bonus_per_level");
	keys.insert("cooldown_multiplier_per_level");
	keys.insert("hero");
    keys.insert("lore");
	keys.insert("race");


	std::string::size_type i;
	std::string::size_type j;
	std::string::size_type foundkey = 0;
    std::string::size_type foundvalue = 0;
	std::string errMsg;
	if (!f.good()) { throw ParseException("File does not exist!"); }
	else {
		std::string sor = "";
		std::string key;
		std::string value;

		while (!f.eof()) {
			getline(f, sor);
			j = 0;
			foundkey = 0;
			foundvalue = 0;
			while (sor[j] != '}' && j != sor.size()) {
                if (sor.find('"',foundkey+1) != std::string::npos) {
                    foundkey = sor.find('"',foundkey);
                    i = foundkey + 1;
                    key = "";
                    while (sor[i] != '"' && sor[i] != ':') {
                        if (sor[i] == '"' || sor[i] == ' ') {
                            i++;
                        }
                        else {
                            key = key + sor[i];
                            i++;
                        }
                    }

                }

                if (sor.find(':',foundvalue+1) != std::string::npos) {
                    foundvalue = sor.find(':',foundvalue);
                    i = foundvalue + 1;
                    value = "";
                    while (((sor[i] != ',') || (sor[i+1] != '"')) && ((sor[i] != ',') || (sor[i+1] != ' ') || (sor[i+2] != '"')) && (i != sor.size())) {

                        if (sor[i] == '"') {
                            i++;
                        } else if ((sor[i] == ' ' || sor[i] == ',') && (key != "monsters" && key != "lore" && key != "name")) {
                            i++;
                        } else {
                            value = value + sor[i];
                            i++;
                        }
                        foundkey = i;
                    }
                    if (key == "name") {
                        value.erase(0,1);
                        std::string::size_type tmp = value.find(',');
                        if (tmp != std::string::npos) {
                            value.erase(tmp);
                        }
                    }
                    if (key == "damage" || key == "health_points" || key == "base_health_points" || key == "base_damage" || key == "experience_per_level" || key == "health_point_bonus_per_level" || key == "damage_bonus_per_level") {
                        int tmp = stoi(value);
                        m[key] = tmp;
                    } else if (key == "attack_cooldown" || key == "base_attack_cooldown" || key == "cooldown_multiplier_per_level") {
                        std::cerr << stod(value) << std::endl;
                        double tmp = stod(value);
                        m[key] = tmp;
                    } else {
                        m[key] = value;
                    }

                }
                    if (sor.find(',',foundkey) != std::string::npos) {
                        foundkey = sor.find(',',foundkey);
                        foundvalue = foundkey;
                        j += foundkey+1;
                    } else {
                        j = sor.size();
                    }
                    if (key == "monsters") j = sor.size();
			}
		}
		f.close();
	}
}

JSON::JSON(std::ifstream& f) {
	Jsonprsr(f);
}

JSON::JSON(const char* fajlnev) {
	std::ifstream f(fajlnev);
	Jsonprsr(f);
}

JSON::JSON(const std::string& szoveg) {
	std::ifstream f(szoveg);
	Jsonprsr(f);
}


JSON::~JSON()
{
	m.clear();
}

JSON JSON::parseFromFile(std::ifstream& f) {
	JSON object(f);
	return object;
}

JSON JSON::parseFromFile(const std::string& szoveg) {
	JSON object(szoveg);
	return object;
}

JSON JSON::parseFromFile(const char * fajlnev) {
	JSON object(fajlnev);
	return object;
}

const int JSON::count(const std::string& key){
    if (m.find(key) != m.end()) return 1;
    else return 0;
}
