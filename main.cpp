#include <iostream>
#include <vector>
#include <fstream>
#include "Cordenadas.h"
#include "Airport.h"
#include "Airline.h"
#include "Manager.h"
#include<bits/stdc++.h>
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
        cout << '\n';
        for (auto a: route1) {

            Graph graph = maneger.getGraph();
            cout << a.getSource() << " " << a.getTarget() << ' ' << a.getAirline() << "    ";

        }
    }
    vector<vector<Flight>> routes;
    vector<Flight> route1;
    vector<Flight> route2;
    route1.push_back(Flight("OPO", "YYZ", "TAP"));
    route1.push_back(Flight("YYZ", "PEK", "CCA"));
    route2.push_back(Flight("OPO", "YYZ", "TAP"));
    route2.push_back(Flight("YYZ", "PEK", "RIP"));
    routes.push_back(route1);
    auto it = find(routes.begin(),routes.end(),route2);
    if(it!=routes.end())cout<<"FUCK\n\n\n";
    cout<<maneger.getNumFlightFrom("OPO")<<" "<<maneger.getNumFlightTo("OPO")<<"\n";
    cout<<"TO DIFERENT :"<<maneger.getNumFlightToDiferentCountrysFrom("YEG")<<"\n";
    cout<<" From diferent :"<<maneger.getNumFlightFromDiferentCountrysTo("YEG")<<"\n";
    cout<<"Test "<<maneger.CountCountriesReachableInNFlights("OPO",2)<<"\n";
    cout<<"Test "<<maneger.CountriesReachableInYFlights("OPO",2).size();
}