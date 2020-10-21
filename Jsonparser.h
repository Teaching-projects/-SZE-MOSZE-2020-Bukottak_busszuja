#include<iostream>
#include<iostream>
#include <map>
#include<fstream>
#include<string>

#define INVALID_VALUE 57
#define MYFILEERROR 56

class Jsonparser
{
public:
	void Jsonprsr(std::ifstream &);
	Jsonparser(std::ifstream &);
	Jsonparser(std::string& szoveg);
	Jsonparser(const char*);
	Jsonparser(std::string, std::string, std::string);
	~Jsonparser();
	std::string getErtek(std::string &);
	bool operator ==(Jsonparser & other) {
		std::string nev = "name"; std::string hp = "hp"; std::string dmg = "dmg";
		return (this->getErtek(nev) == other.getErtek(nev) && this->getErtek(hp) == other.getErtek(hp) && this->getErtek(dmg) == other.getErtek(dmg));
	}
private:
	std::map<std::string, std::string> m;
};

