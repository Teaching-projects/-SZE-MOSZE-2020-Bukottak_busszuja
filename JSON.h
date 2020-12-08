/**
 * \Class Json
 *
 * \brief json Class
 *
 * \author Habán András, Tranta Máté, Tóth Norbert
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
  typedef std::list<std::variant<std::string, int, double>> list;				///< Egy listÃ¡t definiÃ¡l, aminek szÃ¶veg, egÃ©sz, vagy double tagja lehet


	JSON(std::ifstream &);							///< Json konstruktora fájlváltozot vár
	JSON(const std::string&);						///< Json konstruktora stringet vár
	JSON(const char *);								///< Json konstruktora fájlnevet vár
	static JSON parseFromFile(std::ifstream &);		///< Meghívja json fájlváltozót váró konstruktorát (statikus függvény)
	static JSON parseFromFile(const std::string&);	///< Meghívja json sztringet váró konstruktorát (statikus függvény)
	static JSON parseFromFile(const char *);		///< Meghívja json fájlnevet váró konstruktorát (statikus függvény)
	~JSON();										///< Json osztály destruktora
	const int count(const std::string& key);		///< Megnézi létezik-e az adott kulcs

	int GetDataCount() const;						///< Lekéri a map méretét amiben az értékek vannak

    template <typename T>							///< Getter függvény ami lekér egy listát
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

	template <typename T> 							///< Getter függvény ami lekér egy értéket
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
	void Jsonprsr(std::ifstream &);										///< Jsonparser fõlogikája
	std::map <std::string, std::variant<std::string, int, double>> m;	///< map ami tartalmazza a beolvasott kulcsokat és értékeket
};

#endif
