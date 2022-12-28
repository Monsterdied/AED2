//
// Created by tomas on 12/26/2022.
//

#ifndef PROJ_AIRPORT_H
#define PROJ_AIRPORT_H


#include "Cordenadas.h"
#include <iostream>
using namespace std;
class Airport {
private:
    Cordenadas cordenadas;
    string name;
    string code;
    string city;
    string country;
public:
    Airport(double latitude , double longitude , string name , string code , string city , string country );
    Airport();
    Cordenadas getCordenadas();
    string getName()const;
    string getCode()const;
    string getCity()const;
    string getCountry()const;
    bool operator==(const Airport& ariport) const;

};
//if you want to use ordered set
/*
struct HashFunction
{
    size_t operator()(const Airport& airport) const
    {
        size_t codeHash = std::hash<string>()(airport.getCode());
        return codeHash;
    }
};*/


#endif //PROJ_AIRPORT_H
