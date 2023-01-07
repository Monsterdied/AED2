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
#include <set>

 class Manager {
private:
    /*unordered_set <Airport,HashFunction> airports ;*/
    unordered_map <string,Airport> airports;
    unordered_map <string,Airline> airlines;
    unordered_map <string, list<string>> cities;//key =cityCode list<string> aeroportCodes
     unordered_map <string, set<string>> countrysToCitys;//key =ContryCode set<string> citys
    Graph graph;

public:
    Manager();
    void ReadAirLines();
    void ReadAirports();
    void ReadFlights();
    Graph getGraph();
    list<string> getAirportsInCity(string city);
    set<string> getCitysInContry(string country);
    Airport getAirportWithCode(string airportCode);
     Airline getAirlineWithCode(string airlineCode);
    int getNumFlightTo(string aiportCode);
    int getNumFlightFrom(string aiportCode);
    int getNumFlightFromDiferentAirlinesTo(string aiportCode);
    int getNumFlightFromDiferentAirlinesFrom(string aiportCode);
    int getNumFlightFromDiferentCountrysTo(string aiportCode);
    int getNumFlightToDiferentCountrysFrom(string aiportCode);
     unordered_map <string,Airline>  getAirlines();
     unordered_map <string,Airport> getAirports();
     vector<Flight> FindBestRoute(string source, string target);
     vector<Flight> FindBestRouteWithLists(string source, string target,set<string> blackListAirlines,set<string> greenListAirlines);
     vector<vector<Flight>> FindBestRoutes1(string source, string target);
     vector<vector<Flight>> FindBestRoutes(string source, string target,vector<vector<Flight>>& result);
     vector<string> FindAirportsFromCordenadas(Cordenadas cordenadas,int distanceSource);
     vector<string> FindAirportsFromCountry(string country);
     vector<string> FindAirportsFromCity(string city);
     vector<vector<Flight>> FindBestRoutesFromAirportsToAirports(vector<string> starts, vector<string> targets);
     int CountCountriesReachableInNFlights(const string& src, int n);
     unordered_set<string> CountriesReachableInYFlights(const string& src, int y);
     set<string> findArticulationPoints();//find articulation Airports


};


#endif //PROJ_MANAGER_H
