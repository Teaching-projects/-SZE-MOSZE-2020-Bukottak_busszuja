#include<iostream>
#include<iostream>
#include <map>
#include<fstream>
#include<string>

#define INVALID_VALUE 57
#define MYFILEERROR 56

class Jsonparser {
public:
	Jsonparser(std::ifstream &);
	Jsonparser(std::string& szoveg);
	Jsonparser(const char *);
	~Jsonparser();
	std::string getErtek(const std::string &);
private:
	void Jsonprsr(std::ifstream &);
	std::map<std::string, std::string> m;
};
