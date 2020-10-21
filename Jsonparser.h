#include<iostream>
#include<iostream>
#include <map>
#include<fstream>
#include<string>

#define MYFILEERROR 56
#define MYINVALIDVALUE 57

class Jsonparser
{
public:
	Jsonparser(std::ifstream &);
	Jsonparser(std::string & szoveg);
	Jsonparser(const char *);
	Jsonparser(std::string,std::string,std::string);
	~Jsonparser();
	std::string getErtek(std::string &);
	bool operator ==(Jsonparser & other){
		std::string nev = "name"; std::string hp = "hp"; std::string dmg = "dmg";
		return (this->getErtek(nev) == other.getErtek(nev) && this->getErtek(hp) == other.getErtek(hp) && this->getErtek(dmg) == other.getErtek(dmg));
	}
private:
	std::map<std::string, std::string> m;
};

