//
// Created by tomas on 12/27/2022.
//

#ifndef PROJ_MANAGER_H
#define PROJ_MANAGER_H


#include <vector>
#include <fstream>
#include <unordered_set>
#include <unordered_map>
#include "Airline.h"
#include "Airport.h"

class Manager {
private:
    /*unordered_set <Airport,HashFunction> airports ;*/
    unordered_map <string,Airport> airports;
    vector<Airline> airlines;

public:
    Manager();
    void ReadAirLinesFile();
    void ReadAirports();
    vector<Airline> getAirlines();
    unordered_map <string,Airport> getAirports();
};


#endif //PROJ_MANAGER_H
