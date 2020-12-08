/**
 * \Class Map
 *
 * \brief Map Class
 *
 * \author Hab�n Andr�s, Tranta M�t�, T�th Norbert
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
	std::vector <std::string> palya;			///< Vektor ami a p�lya sorait tartalmazza
public:
	enum type { Wall, Free,Unknow};				///< Egy mez� lehets�ges t�pusai
	Map(const std::string &);					///< Map oszt�ly construktora
	Map(){}										///< Map oszt�ly default konstruktora
	virtual ~Map();								///< Map ost�ly destruktora
	void kiir()const;							///< f�ggv�ny ami ki�rja a beolvasott p�lya tartalm�t
	int getSzelesseg()const;					///< lek�ri a p�lya sz�less�g�t
	int getMagassag()const;						///< lek�ri a p�lya magass�g�t
	Map::type get(int x, int y) const;			///< visszaadja a p�lya egy mez�j�nek t�pus�t koordin�ta alapj�n
	class WrongIndexException : public std::runtime_error {
	public:
		WrongIndexException(const std::string& hibauzenet) : std::runtime_error(hibauzenet) {}
	};
};

#endif
