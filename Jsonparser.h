
/**
 * \class Jasonparser
 *
 * \brief Jasonparser class
 *
 * \author Haban Andras, Tranta Mate, Toth Norbert
 *
 * Created on: 2020/10/27 13:14
*/

#ifndef JSONPARSER_H
#define JSONPARSER_H

#include<iostream>
#include<iostream>
#include <map>
#include<fstream>
#include<string>

#define INVALID_VALUE 57
#define MYFILEERROR 56

class Jsonparser {
public:
	Jsonparser(std::ifstream &);	///< a jasonparser fajlvaltozval mukodo konstruktora
	Jsonparser(std::string& szoveg);	///< a jasonparser stringel mukodo konstruktora
	Jsonparser(const char *);	///< a jasonparser fajlnevel mukodo konstruktora
	~Jsonparser();	///< a jason parser destruktora
	std::string getErtek(const std::string &);	///< fugveny ami paramaterkent megadott kulcshoz ad erteket
  int getSize()const;  ///< fuggveny,ami visszaadja a meretet a map-nek

private:
	void Jsonprsr(std::ifstream &);	///< a fo fugveny amit a konstruktorok meghivnak
	std::map<std::string, std::string> m;	///< map valtozo ami tarolja a kulcsokat es hozzajuk tartozo ertekeket
};

#endif

