#include <iostream>
#include <vector>
#include <fstream>
#include "Cordenadas.h"
#include "Airport.h"
#include "Airline.h"
#include "Manager.h"

int main() {
    Manager maneger;
    maneger.ReadAirLines();
    maneger.ReadAirports();
    maneger.ReadFlights();
    /*cout<<("Iberia Airlines"==maneger.getAirlines().front().getName() ? "ok":"not ok")<<'\n';
    cout<<("John F Kennedy Intl"==(maneger.getAirports().find("JFK")->second.getName()) ? "ok":"not ok")<<'\n';
    cout<<("JFK"==maneger.getAirports().find("JFK")->second.getCode() ? "ok":"not ok")<<'\n';
    cout<<("New York"==maneger.getAirports().find("JFK")->second.getCity() ? "ok":"not ok")<<'\n';
    cout<<("United States"==maneger.getAirports().find("JFK")->second.getCountry() ? "ok":"not ok")<<'\n';
    cout<<(40.639751==maneger.getAirports().find("JFK")->second.getCordenadas().getlatitude() ? "ok":"not ok")<<'\n';
    cout<<(-73.778925==maneger.getAirports().find("JFK")->second.getCordenadas().getlongitude() ? "ok":"not ok")<<'\n';*/
}