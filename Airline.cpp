//
// Created by tomas on 12/27/2022.
//

#include "Airline.h"
Airline::Airline() {
    this->code="";
    this->name = "";
    this->callsign = "";
    this->country = "";
}
Airline::Airline(string code,string name,string callsign,string country){
    this->code=code;
    this->name = name;
    this->callsign = callsign;
    this->country = country;
}
string Airline::getCode(){
    return code;
}
string Airline::getName(){
    return name;
}
string Airline::getCallSign(){
    return callsign;
}
string Airline::getCountry(){
    return country;
}