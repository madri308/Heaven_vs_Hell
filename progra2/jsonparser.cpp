#include "jsonparser.h"
#include "iostream"
#include "string.h"
#include <fstream>
#include <json.hpp>


using json = nlohmann::json;
using namespace std;

JsonParser::JsonParser(string names[], string lastNames[],string jobs[],string religions[],string countries[][4]){
    std::ifstream i("C://Users//Sebas Villanueva//Documents//GitHub//Heaven_vs_Hell//progra2//data.json");
    i >> file;
    for(json::size_type element = 0 ; element < 1000 ; element++){
        names[element] = file["names"][element];
        lastNames[element] = file["lastnames"][element];
    }
    for(json::size_type countriePos = 0 ; countriePos < 100 ; countriePos++){
        countries[countriePos][0] = file["countries"][countriePos][0];
        countries[countriePos][1] = "0";
        countries[countriePos][2] = "0";
        countries[countriePos][3] = file["countries"][countriePos][1];
    }
    for(json::size_type job  = 0; job < 50 ; job++){
        jobs[job] = file["jobs"][job];
    }
    for(json::size_type religion = 0 ; religion < 10 ; religion++){
        religions[religion] = file["religions"][religion];
    }
}



