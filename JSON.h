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
  typedef std::list<std::variant<std::string, int, double>> list;				///< Egy listát definiál, aminek szöveg, egész, vagy double tagja lehet


	JSON(std::ifstream &);
	JSON(const std::string&);
	JSON(const char *);
	static JSON parseFromFile(std::ifstream &);
	static JSON parseFromFile(const std::string&);
	static JSON parseFromFile(const char *);
	~JSON();
	const int count(const std::string& key);

    template <typename T>
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

	template <typename T> inline typename std::enable_if<!std::is_same<T, JSON::list>::value, T>::type
	get(const std::string& key/** [in] kulcs*/){
       	if (!count(key)) throw ParseException("Key does not exist in map!");
        else return std::get<T>(m[key]);
    }

    class ParseException : public std::runtime_error{
    public:
      ParseException(const std::string& err) : std::runtime_error(err){}
    };

private:
	void Jsonprsr(std::ifstream &);
	std::map <std::string, std::variant<std::string, int, double>> m;
};

#endif
