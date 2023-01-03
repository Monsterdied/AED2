 //
// Created by tomas on 12/27/2022.
//

#ifndef PROJ_MANAGER_H
#define PROJ_MANAGER_H


#include <vector>
#include <fstream>
#include <unordered_set>
#include <unordered_map>
#include "Airline.h"
#include "Airport.h"
#include "Graph.h"

 class Manager {
private:
    /*unordered_set <Airport,HashFunction> airports ;*/
    unordered_map <string,Airport> airports;
    unordered_map <string,Airline> airlines;
    unordered_map <string, list<string>> cities;
    Graph graph;

public:
    Manager();
    void ReadAirLines();
    void ReadAirports();
    void ReadFlights();
    Graph getGraph();
    int getNumFlightTo(string aiportCode);
    int getNumFlightFrom(string aiportCode);
    int getNumFlightFromDiferentAirlinesTo(string aiportCode);
    int getNumFlightFromDiferentAirlinesFrom(string aiportCode);
    int getNumFlightFromDiferentCountrysTo(string aiportCode);
    int getNumFlightToDiferentCountrysFrom(string aiportCode);
     unordered_map <string,Airline>  getAirlines();
     unordered_map <string,Airport> getAirports();
     vector<Flight> FindBestRoute(string source, string target);
     vector<vector<Flight>> FindBestRoutes1(string source, string target);
     vector<vector<Flight>> FindBestRoutes(string source, string target,vector<vector<Flight>>& result);
     vector<vector<Flight>> FindBestRoutesFromCordenadasToTarget(Cordenadas cordenadas, string target,int distanceSource);
     vector<vector<Flight>> FindBestRoutesFromCordenadasToCordenadas(Cordenadas cordenadas, Cordenadas cordenadas1,int distanceSource,int distanceTarget);
     int CountCountriesReachableInNFlights(const string& src, int n);
     unordered_set<string> CountriesReachableInYFlights(const string& src, int y);


};


#endif //PROJ_MANAGER_H
