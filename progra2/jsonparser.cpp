#include "jsonparser.h"
#include "iostream"
#include "string.h"
#include <fstream>
#include <json.hpp>


using json = nlohmann::json;
using namespace std;

JsonParser::JsonParser(string names[], string lastNames[],string jobs[],string religions[],string countries[]){
    std::ifstream i("C:/Users/Esteban Madrigal/Documents/GitHub/Heaven_vs_Hell/progra2/data.json");
    i >> file;
    for(json::size_type element = 0 ; element < 1000 ; element++){
        names[element] = file["names"][element];
        lastNames[element] = file["lastnames"][element];
    }
    for(json::size_type countriePos = 0 ; countriePos < 100 ; countriePos++){
        countries[countriePos] = file["countries"][countriePos];
    }
    for(json::size_type job  = 0; job < 50 ; job++){
        jobs[job] = file["jobs"][job];
    }
    for(json::size_type religion = 0 ; religion < 10 ; religion++){
        religions[religion] = file["religions"][religion];
    }
}



