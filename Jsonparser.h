#include<iostream>
#include <map>
#include<fstream>
#include<string>
class Jsonparser
{
public:
	Jsonparser(std::string);
	Jsonparser(std::ifstream &);
	~Jsonparser();
	std::string getErtek(std::string);
private:
	std::map<std::string,std::string> m;
};

