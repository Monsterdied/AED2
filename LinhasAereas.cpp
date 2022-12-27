//
// Created by Rodrigo on 12/27/2022.
//
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include "LinhasAereas.h"

LinhaAerea::LinhaAerea(string code, string nome, string callsign,string country){
    this->code = code;
    this->nome = nome;
    this-> callsign = callsign;
    this-> country = country;
}
string LinhaAerea::getNome(){
    return this->nome;
}


