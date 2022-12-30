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
    /*
    auto route = maneger.FindBestRoute("OPO", "PEK",maneger.getGraph());
    cout<<route.size();
    for( auto a:route){
        cout<<'\n';
        Graph graph = maneger.getGraph();
        cout<<a.getSource()<<" "<<a.getTarget()<<' '<<a.getAirline()<<" ";

        cout<<"\n";
    }*/
    auto route = maneger.FindBestRoutes1("OPO", "PEK");
    cout << route.size();
    for (auto route1: route) {
        for (auto a: route1) {
            cout << '\n';
            Graph graph = maneger.getGraph();
            cout << a.getSource() << " " << a.getTarget() << ' ' << a.getAirline() << " ";

            cout << "\n";
        }
    }
}