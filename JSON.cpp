#include "JSON.h"
#include <set>


void JSON::Jsonprsr(std::ifstream& f) {

	if (!f.good()) { throw ParseException("File does not exist!"); }
	else {
		std::string sor = "";
		std::string jsonstring = "";

		while (!f.eof()) {
			getline(f, sor);
			jsonstring += sor;
		}


		static const std::regex parseRegex("\\s*\"([\\w-]*)\"\\s*:\\s*\"?([\\s\\w\\.-\\/]*)\"?\\s*[,}]\\s*");
		static const std::regex listRegex("\\s*\"([\\w]*)\"\\s*:\\s*\"?\\[?\\s*([\\w\\.\"?,?\\s*]*)\"?\\s*[,\\]}]");
        std::smatch matches, listmatches;
        std::string errMsg;
        if (jsonstring.substr(0,1) != "{") {
            errMsg = "Error in file: missing opening {.";
            throw ParseException(errMsg);
        }
        else if (jsonstring.substr(jsonstring.size()-1, 1) != "}") {
            errMsg = "Error in file: missing ending }.";
            throw ParseException(errMsg);
        }

        while(std::regex_search(jsonstring, matches, parseRegex)) {
            if (matches[1] == "") {
                errMsg = "Error in file: incorrect key.";
                throw ParseException(errMsg);
            } else if (matches[2] == "") {
                errMsg = "Error in file: incorrect value.";
                throw ParseException(errMsg);
            } else {
                std::string value = matches[2];

                if (!value.empty() && std::all_of(value.begin(), value.end(), [](char c){return std::isdigit(c);})) m[matches[1]] = std::stoi(value);
                else if (!value.empty() && std::all_of(value.begin(), value.end(), [](char c){return ((std::isdigit(c) || c == '.') ? true : false);})) m[matches[1]] = std::stod(value);
                else m[matches[1]] = value;
                jsonstring = matches.suffix().str();
            }
        }

        if(std::regex_search(jsonstring, listmatches, listRegex)) {
            std::string values = listmatches[2];
                while (values.find(",")!=std::string::npos)
                    values.erase(values.find(","),1);

                while(values.find("\"")!= std::string::npos)
                    values.erase(values.find("\""),1);

            m[listmatches[1]]=values;
            jsonstring = listmatches.suffix().str();
        }
    }

    f.close();
}

JSON::JSON(std::ifstream& f) {
	Jsonprsr(f);
}

JSON::JSON(const char* fajlnev) {
	std::ifstream f(fajlnev);
	Jsonprsr(f);
}

JSON::JSON(const std::string& szoveg) {
	std::ifstream f(szoveg);
	Jsonprsr(f);
}


JSON::~JSON()
{
	m.clear();
}

JSON JSON::parseFromFile(std::ifstream& f) {
	JSON object(f);
	return object;
}

JSON JSON::parseFromFile(const std::string& szoveg) {
	JSON object(szoveg);
	return object;
}

JSON JSON::parseFromFile(const char * fajlnev) {
	JSON object(fajlnev);
	return object;
}

const int JSON::count(const std::string& key){
    if (m.find(key) != m.end()) return 1;
    else return 0;
}

int JSON::GetDataCount() const {
	return m.size();
}
