/**
 * \Class Json
 *
 * \brief json Class
 *
 * \author Haban Andras, Tranta Mate, Toth Norbert
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


	JSON(std::ifstream &);							///< Json konstruktora fajlvaltozot var
	JSON(const std::string&);						///< Json konstruktora stringet var
	JSON(const char *);								///< Json konstruktora fajlnevet var
	static JSON parseFromFile(std::ifstream &);		///< Meghivja json fajlvaltozot varo konstruktorat (statikus fuggveny)
	static JSON parseFromFile(const std::string&);	///< Meghivja json sztringet varo konstruktorat (statikus fuggveny)
	static JSON parseFromFile(const char *);		///< Meghivja json fajlnevet varo konstruktorat (statikus fuggveny)
	~JSON();										///< Json osztaly destruktora
	const int count(const std::string& key);		///< Megnezi letezik-e az adott kulcs

	int GetDataCount() const;						///< Lekeri a map meretet amiben az ertekek vannak

    template <typename T>							///< Getter fuggveny ami leker egy listat
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

	template <typename T> 							///< Getter fuggveny ami leker egy erteket
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
	void Jsonprsr(std::ifstream &);										///< Jsonparser fologikaja
	std::map <std::string, std::variant<std::string, int, double>> m;	///< map ami tartalmazza a beolvasott kulcsokat és ertekeket
};

#endif
