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
    vector<Flight> route = maneger.FindBestRoute("JFK", "KUN");
    cout << "CDG\n";
    for(Flight a:route){
        cout<<a.getTarget()<<'\n';
    }

}