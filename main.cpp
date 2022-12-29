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
/*
    auto ok = maneger.getGraph();
    for(auto tmp : maneger.getAirports()){
        cout<<tmp.first<<"\n\n";
        for(auto tmp1 : ok.getEdges(tmp.first)){
            cout<<tmp1.sourceCode<<" "<<tmp1.airlineCode<<tmp1.destinationCode<<"\n";
        }
        cout<<"\n\n\n\n\n";
    }*/
    vector<Graph::Flight> route = maneger.FindBestRoute("JFK", "KUN");
    cout << "CDG\n";
    for(Graph::Flight a:route){
        cout<<a.destinationCode<<'\n';
    }

}