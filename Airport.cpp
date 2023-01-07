//
// Created by tomas on 12/26/2022.
//

#include "Airport.h"
Airport::Airport(double latitude , double longitude , string name , string code , string city , string country ){
    this->cordenadas=Coordenadas(latitude, longitude);
    this->city = city;
    this->code= code ;
    this->country=country;
    this->name = name;
}
Airport::Airport() {
    this->cordenadas=Coordenadas(0, 0);
    this->city = "";
    this->code= "" ;
    this->country="";
    this->name = "";
}
bool Airport::operator==(const Airport& airport) const
{
    if (this->cordenadas == airport.cordenadas && this->name == airport.name && this->country == airport.country && this->code==airport.code && this->city == airport.city) return true;
    else return false;
}
Coordenadas Airport::getCordenadas(){
    return cordenadas;
}
string Airport::getName() const{
    return name;
}
string Airport::getCode()const{
    return code;
}
string Airport::getCity()const{
    return city;
}
string Airport::getCountry()const{
    return country;
}
