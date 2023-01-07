//
// Created by tomas on 12/26/2022.
//

#ifndef PROJ_AIRPORT_H
#define PROJ_AIRPORT_H


#include "Coordinates.h"
#include <iostream>
using namespace std;
class Airport {
private:
    Coordinates coordinates;
    string name;
    string code;
    string city;
    string country;
public:
    Airport(double latitude , double longitude , string name , string code , string city , string country );
    Airport();
    Coordinates getCoordinates();
    string getName()const;
    string getCode()const;
    string getCity()const;
    string getCountry()const;
    bool operator==(const Airport& airport) const;

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
