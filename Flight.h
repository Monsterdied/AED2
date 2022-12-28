//
// Created by Utilizador on 12/28/2022.
//

#ifndef PROJ_FLIGHT_H
#define PROJ_FLIGHT_H
#include "string"
using namespace std;
class Flight {
private:
    string source,target,airline;
public:
    Flight(string source,string target,string airline);
    string getSource();
    string getTarget();
    string getAirline();
};
#endif //PROJ_FLIGHT_H
