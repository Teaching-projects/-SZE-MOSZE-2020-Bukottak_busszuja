#include "Jsonparser.h"
#include <set>


void Jsonparser::Jsonprsr(std::ifstream & f) {
	std::set<std::string> keys;
	keys.insert("name");
	keys.insert("dmg");
	keys.insert("hp");

	std::string::size_type i;
	std::string::size_type found;
	if (!f.good()) throw MYFILEERROR;
	else {
		std::string sor = "";
		std::string key;
		std::string value;

		while (!f.eof()) {
			getline(f, sor);
			found = sor.find('"');
			if (found != std::string::npos) {
				i = found + 1;
				key = "";
				while (sor[i] != '"') {
					key = key + sor[i];
					i++;
				}

				if (keys.find(key) == keys.end()) throw INVALID_VALUE;

			}

			found = sor.find(':');
			if (found != std::string::npos) {
				i = found + 1;
				value = "";
				while (sor[i] != ',' && i != sor.size()) {
					if (sor[i] == '"' || sor[i] == ' ') {
						i++;
					}
					else {
						value = value + sor[i];
						i++;
					}
				}

				m[key] = value;

			}
		}
		f.close();

	}
}

Jsonparser::Jsonparser(std::ifstream& f) {
	Jsonprsr(f);
}

Jsonparser::Jsonparser(const char* fajlnev) {
	std::ifstream f(fajlnev);
	Jsonprsr(f);
}

Jsonparser::Jsonparser(std::string& szoveg) {
	std::ifstream f(szoveg);
	Jsonprsr(f);
}


Jsonparser::Jsonparser(std::string name, std::string hp, std::string dmg) {
	m["name"] = name;
	m["hp"] = hp;
	m["dmg"] = dmg;
}



Jsonparser::~Jsonparser()
{
	m.clear();
}

std::string Jsonparser::getErtek(std::string & kulcs) {
	return m[kulcs];
}
