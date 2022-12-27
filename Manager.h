//
// Created by tomas on 12/27/2022.
//

#ifndef PROJ_MANAGER_H
#define PROJ_MANAGER_H


#include <vector>
#include <fstream>
#include <unordered_set>
#include "Airline.h"

class Manager {
private:
    unordered_set <string> airports ;
    vector<Airline> airlines;

public:
    Manager();
    void ReadAirLinesFile() ;
    vector<Airline> getAirlines();
};


#endif //PROJ_MANAGER_H
