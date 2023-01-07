//
// Created by tomas on 12/27/2022.
//

#ifndef PROJ_AIRLINE_H
#define PROJ_AIRLINE_H
#include <iostream>
using namespace std;
class Airline {
private:
    string code;
    string name;
    string callsign;
    string country;
public:
    Airline();
    Airline(string code,string name,string callsign,string country);
    string getCode();
    string getName();
    string getCallSign();
    string getCountry();

};


#endif //PROJ_AIRLINE_H
