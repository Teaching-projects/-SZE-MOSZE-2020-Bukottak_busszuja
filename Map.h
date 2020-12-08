/**
 * \Class Map
 *
 * \brief Map Class
 *
 * \author Habán András, Tranta Máté, Tóth Norbert
 *
 * Created on: 2020/12/07 18:25
*/
#ifndef MAP_H
#define MAP_H



#include<iostream>
#include<vector>
#include<string>


class Map
{
protected:
	std::vector <std::string> palya;			///< Vektor ami a pálya sorait tartalmazza
public:
	enum type { Wall, Free,Unknow};				///< Egy mezõ lehetséges típusai
	Map(const std::string &);					///< Map osztály construktora
	Map(){}										///< Map osztály default konstruktora
	virtual ~Map();								///< Map ostály destruktora
	void kiir()const;							///< függvény ami kiírja a beolvasott pálya tartalmát
	int getSzelesseg()const;					///< lekéri a pálya szélességét
	int getMagassag()const;						///< lekéri a pálya magasságát
	Map::type get(int x, int y) const;			///< visszaadja a pálya egy mezõjének típusát koordináta alapján
	class WrongIndexException : public std::runtime_error {
	public:
		WrongIndexException(const std::string& hibauzenet) : std::runtime_error(hibauzenet) {}
	};
};

#endif
