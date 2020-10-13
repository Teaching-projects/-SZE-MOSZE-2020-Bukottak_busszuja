#include<iostream>
#include<iostream>
#include <map>
#include<fstream>
#include<string>
class Jsonparser
{
public:
	Jsonparser(std::string);
	Jsonparser(std::ifstream &);
	Jsonparser(const char *);
	Jsonparser(std::string,std::string,std::string);
	~Jsonparser();
	std::string getErtek(std::string);
	bool operator ==(Jsonparser & other){
		return (this->getErtek("name") == other.getErtek("name") && this->getErtek("hp") == other.getErtek("hp") && this->getErtek("dmg") == other.getErtek("dmg"));
	}
private:
	std::map<std::string, std::string> m;
};

