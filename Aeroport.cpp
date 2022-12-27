//
// Created by tomas on 12/26/2022.
//

#include "Aeroport.h"
Aeroport::Aeroport(double latitude , double longitude , string name , string code , string city , string country ){
    this->cordenadas=Cordenadas(latitude,longitude);
    this->city = city;
    this->code= code ;
    this->country=country;
    this->name = name;
}