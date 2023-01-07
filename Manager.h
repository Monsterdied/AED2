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
     vector<Flight> FindBestRoute(string source, string target);// da output de 1 caminho com a route mais pequena
     vector<Flight> FindBestRouteWithBlackListed(string source, string target,set<string> blackListAirlines);//faz o mesmo que a anterior com black listed
     vector<Flight> FindBestRouteWithGreenListed(string source, string target,set<string> greenListAirlines);//faz o mesmo que a anterior com white listed
     vector<vector<Flight>> FindBestRoutes1(string source, string target);//função calcula todas as routes entre os dois aeroportos
     vector<vector<Flight>> FindBestRoutes(string source, string target,vector<vector<Flight>>& result);//função auxiliar a anterior
     vector<string> FindAirportsFromCordenadas(Cordenadas cordenadas,int distanceSource);//Encontra todos os aeroportos a distancia de distanceSource da cordenada
     vector<string> FindAirportsFromCountry(string country);//Encontra todos os aeroportos no pais contry
     vector<string> FindAirportsFromCity(string city);//Encontra todos os aeroportos no cidade
     vector<vector<Flight>> FindBestRoutesFromAirportsToAirports(vector<string> starts, vector<string> targets);//encontra entre os varios paises uma rota e da output as rotas com tamanho minimo
     int CountCountriesReachableInNFlights(const string& src, int n);//da output ao numero de paises que podes chegar de src em y fligths
     unordered_set<string> CountriesReachableInYFlights(const string& src, int y);//da output aos paises que podes chegar de src em y fligths
     set<string> findArticulationPoints();//find articulation Airports sao os quais se removeres em ves de um ciclo ficas com dois 


};


#endif //PROJ_MANAGER_H
