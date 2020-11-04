#ifndef JSON_H
#define JSON_H



#include<iostream>
#include<iostream>
#include <map>
#include<fstream>
#include<string>

class JSON {
public:
	JSON(std::ifstream &);
	JSON(const std::string&);
	JSON(const char *);
	static JSON parseFromFile(std::ifstream &);
	static JSON parseFromFile(const std::string&);
	static JSON parseFromFile(const char *);
	~JSON();
	std::string getErtek(const std::string &);
	const int count(const std::string& key);

    template <class T> T get(const std::string& key){
        return m[key];
    }

    class ParseException : public std::runtime_error{
    public:
      ParseException(const std::string& err) : std::runtime_error(err){}
    };

private:
	void Jsonprsr(std::ifstream &);
	std::map<std::string, std::string> m;
};

#endif
