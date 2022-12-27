#include <iostream>
#include <vector>
#include <fstream>
#include "Cordenadas.h"
#include "Aeroport.h"
#include "Airline.h"
#include "Manager.h"

int main() {
    Manager maneger;
    maneger.ReadAirLinesFile();

    cout<<maneger.getAirlines().front().getName();
}