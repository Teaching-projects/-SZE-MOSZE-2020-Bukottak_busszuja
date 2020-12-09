/**
 * \Class Map
 *
 * \brief Map Class
 *
 * \author Haban András, Tranta Mate, Toth Norbert
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
	std::vector <std::string> palya;			///< Vektor ami a palya sorait tartalmazza
public:
	enum type { Wall, Free,Unknow};				///< Egy mezo lehetseges tipusai
	Map(const std::string &);					///< Map osztály construktora
	Map(){}										///< Map osztaly default konstruktora
	virtual ~Map();								///< Map osztaly destruktora
	void kiir()const;							///< fuggveny ami kiirja a beolvasott palya tartalmat
	int getSzelesseg()const;					///< lekeri a palya szelesseget
	int getMagassag()const;						///< lekeri a palya magassagat
	Map::type get(int x, int y) const;			///< visszaadja a palya egy mezojenek tipusat koordinata alapjan
	class WrongIndexException : public std::runtime_error {
	public:
		WrongIndexException(const std::string& hibauzenet) : std::runtime_error(hibauzenet) {}
	};
};

#endif
