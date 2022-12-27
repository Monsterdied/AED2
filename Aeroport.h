//
// Created by tomas on 12/26/2022.
//

#ifndef PROJ_AEROPORT_H
#define PROJ_AEROPORT_H


#include "Cordenadas.h"
#include <iostream>
using namespace std;
class Aeroport {
private:
    Cordenadas cordenadas;
    string name;
    string code;
    string city;
    string country;
public:
    Aeroport(double latitude , double longitude , string name , string code , string city , string country );
    void ReadAirportsFile();

};


#endif //PROJ_AEROPORT_H
