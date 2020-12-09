/**
 * \Class Json
 *
 * \brief json Class
 *
 * \author Hab�n Andr�s, Tranta M�t�, T�th Norbert
 *
 * Created on: 2020/12/07 18:13
*/
#ifndef JSON_H
#define JSON_H



#include<iostream>
#include <map>
#include <variant>
#include<fstream>
#include<string>
#include <algorithm>
#include <regex>
#include <type_traits>
#include <list>
#include <cctype>

class JSON {
public:
  typedef std::list<std::variant<std::string, int, double>> list;				///< Egy listat definial, aminek szoveg, egesz, vagy double tagja lehet


	JSON(std::ifstream &);							///< Json konstruktora f�jlv�ltozot v�r
	JSON(const std::string&);						///< Json konstruktora stringet v�r
	JSON(const char *);								///< Json konstruktora f�jlnevet v�r
	static JSON parseFromFile(std::ifstream &);		///< Megh�vja json f�jlv�ltoz�t v�r� konstruktor�t (statikus f�ggv�ny)
	static JSON parseFromFile(const std::string&);	///< Megh�vja json sztringet v�r� konstruktor�t (statikus f�ggv�ny)
	static JSON parseFromFile(const char *);		///< Megh�vja json f�jlnevet v�r� konstruktor�t (statikus f�ggv�ny)
	~JSON();										///< Json oszt�ly destruktora
	const int count(const std::string& key);		///< Megn�zi l�tezik-e az adott kulcs

	int GetDataCount() const;						///< Lek�ri a map m�ret�t amiben az �rt�kek vannak

    template <typename T>							///< Getter f�ggv�ny ami lek�r egy list�t
	inline typename std::enable_if<std::is_same<T, JSON::list>::value, T>::type
	get(const std::string& key){
		if (!count(key)) throw ParseException("Key does not exist in map!");
		else{
				list toReturn;
				std::istringstream elements(std::get<std::string>(m[key]));
				std::copy(std::istream_iterator<std::string>(elements),
               		std::istream_iterator<std::string>(),
           	 		std::back_inserter(toReturn));

				return toReturn;
			}
		}

	template <typename T> 							///< Getter f�ggv�ny ami lek�r egy �rt�ket
	inline typename std::enable_if<!std::is_same<T, JSON::list>::value, T>::type 
	get(const std::string& key){
       	if (!count(key)) throw ParseException("Key does not exist in map!");
        else return std::get<T>(m[key]);
    }

    class ParseException : public std::runtime_error{
    public:
      ParseException(const std::string& err) : std::runtime_error(err){}
    };

private:
	void Jsonprsr(std::ifstream &);										///< Jsonparser f�logik�ja
	std::map <std::string, std::variant<std::string, int, double>> m;	///< map ami tartalmazza a beolvasott kulcsokat �s �rt�keket
};

#endif
