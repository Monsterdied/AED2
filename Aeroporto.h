//
// Created by tomas on 12/26/2022.
//

#ifndef PROJ_AEROPORTO_H
#define PROJ_AEROPORTO_H


#include "Cordenadas.h"
#include <iostream>
using namespace std;
class Aeroporto {
private:
    Cordenadas cordenadas;
    string name;
    string code;
    string city;
    string country;
public:
    Aeroporto(double latitude , double longitude , string name , string code , string city , string country );
    void ReadAirportsFile();

};


#endif //PROJ_AEROPORTO_H
