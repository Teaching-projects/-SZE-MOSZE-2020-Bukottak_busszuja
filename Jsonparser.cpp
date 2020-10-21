#include "Jsonparser.h"

Jsonparser::Jsonparser(std::ifstream & f) {
	int keyv, i;
	std::string::size_type found;
	if (!f.good()) throw MYFILEERROR;
	else {
		std::string sor = "";
		std::string tmp;

		while (!f.eof()) {
			getline(f, sor);
			keyv = 0;
			found = sor.find('"');
			if (found != std::string::npos) {
				i = found + 1;
				tmp = "";
				while (sor[i] != '"') {
					tmp = tmp + sor[i];
					i++;
				}

				if (tmp == "name") keyv = 1;
				if (tmp == "hp") keyv = 2;
				if (tmp == "dmg") keyv = 3;
			}

			found = sor.find(':');
			if (found != std::string::npos) {
				i = found + 1;
				tmp = "";
				while (sor[i] != ',' && i != sor.size()) {
					if (sor[i] == '"' || sor[i] == ' ') {
						i++;
					}
					else {
						tmp = tmp + sor[i];
						i++;
					}
				}

				switch (keyv) {
				case 1: m["name"] = tmp;
					break;
				case 2: m["hp"] = tmp;
					break;
				case 3: m["dmg"] = tmp;
					break;
				default: throw MYINVALIDVALUE;
					break;

				}
			}
		}
		f.close();

	}
}


Jsonparser::Jsonparser(const char * fajlnev) {
std::ifstream f(fajlnev);
Jsonparser::Jsonparser(f);
}

Jsonparser::Jsonparser(std::string & szoveg) {
	std::ifstream f(szoveg);
	Jsonparser::Jsonparser(f);
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
