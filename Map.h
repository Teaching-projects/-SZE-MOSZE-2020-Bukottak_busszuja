#ifndef MAP_H
#define MAP_H



#include<iostream>
#include<vector>
#include<string>


class Map
{
protected:
	std::vector <std::string> palya;
public:
	enum type { Wall, Free,Unknow};
	Map(const std::string &);
	Map(){}
	virtual ~Map();
	void kiir()const;
	int getSzelesseg()const;
	int getMagassag()const;
	Map::type get(int x, int y) const;
	class WrongIndexException : public std::runtime_error {
	public:
		WrongIndexException(const std::string& hibauzenet) : std::runtime_error(hibauzenet) {}
	};
};

#endif