//
// Created by Rodrigo on 12/27/2022.
//

#ifndef PROJ_LINHASAEREAS_H
#define PROJ_LINHASAEREAS_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class LinhaAerea{
private:
    string code;
    string nome;
    string callsign;
    string country;
public:
    LinhaAerea(string code, string nome, string callsign,string country);
    string getNome();

};

#endif //PROJ_LINHASAEREAS_H
