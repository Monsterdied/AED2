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
     //! A normal method taking no arguments and doesn´t return anything.
     /*!
         Reads the files them in their respective data structures.
         \Complexity  0(n)
     */
    void ReadAirLines();
     //! A normal method taking no arguments and doesn´t return anything.
     /*!
         Reads the files them in their respective data structures.
         a Complexity é N o number of airports , E the number of airports int the city and S the number of cities in a Country
         \Complexity  0(N log(E) + N log(S))
     */
    void ReadAirports();
     //! A normal method taking no arguments and doesn´t return anything.
     /*!
         Reads the files them in their respective data structures.
         \Complexity  0(n)
     */
    void ReadFlights();
     //! A normal method taking The name of the city return the airports in the city
     /*!
         This method utilizes unordered_map so is very efficient .
         \Complexity  0(1)
     */
    list<string> getAirportsInCity(string city);
     //! A normal method taking The name of the country return the airports in the city
     /*!
         This method utilizes unordered_map so is very efficient.
         \Complexity  0(1)
     */
    set<string> getCitysInContry(string country);
     //! A normal method taking The AirportCode that return the airport
     /*!
         This method utilizes unordered_map so is very efficient.
         \Complexity  0(1)
     */
    Airport getAirportWithCode(string airportCode);
     //! A normal method taking The AirlineCode that return the airport
     /*!
         This method utilizes unordered_map so is very efficient.
         \Complexity  0(1)
     */
     Airline getAirlineWithCode(string airlineCode);
     //! A normal method taking The AirportCode that return a integer
     /*!
         This method returns the number of flights to a certain Airport , n is the number of flights.
         \Complexity  0(n)
     */
    int getNumFlightTo(string aiportCode);
     //! A normal method taking The AirportCode that return a integer
     /*!
         This method returns the flights that begin in the Airport that the airport code is referring to
         ,utilizes unordered_map so is very efficient.
         \Complexity  0(1)
     */
    int getNumFlightFrom(string aiportCode);
     //! A normal method taking The AirportCode that return a integer
     /*!
         This method returns the number of flights to a certain airport that the airportCode is referring to from different airlines , n is the number of flights.
         \Complexity  0(n)
     */
    int getNumFlightFromDiferentAirlinesTo(string aiportCode);
     //! A normal method taking The AirportCode that return a integer
     /*!
         This method returns the flights that begin in the Airport that the airportCode is referring to
         ,utilizes unordered_map so is very efficient.
         \Complexity  0(1)
     */
    int getNumFlightFromDiferentAirlinesFrom(string aiportCode);
     //! A normal method taking The AirportCode that return a integer
     /*!
         This method returns the number of flights to a certain airport that the airportCode is referring to from different Countries, n is the number of flights.
         \Complexity  0(nlog(n))
     */
    int getNumFlightFromDiferentCountrysTo(string aiportCode);
     //! A normal method taking The AirportCode that return a integer
     /*!
         This method returns the number of flights from a certain airport that the airportCode is referring to from different Countries , n is the number of flights.
         \Complexity  0(log(n))
     */
    int getNumFlightToDiferentCountrysFrom(string aiportCode);
     //! A normal method taking no arguments and return an unordered_map.
     /*!
         Returns an unordered_map where the key is the AirlineCode and Returns and Airline.
         \Complexity 0(1)
     */
     unordered_map <string,Airline>  getAirlines();
     //! A normal method taking no arguments and return an unordered_map.
     /*!
         Returns an unordered_map where the key is the AirportCode and Returns and Airport.
         \Complexity 0(1)
     */
     unordered_map <string,Airport> getAirports();
     //! A normal method taking a string source (AirportCode) and string Target (AirportCode).
     /*!
         Returns a path with the shortest length possible that goes from the airportCode source and airportCode target
         \Complexity  O(V+E), where V is the number of vertices (airports) in the graph and E is the number of edges (flights) in the graph
     */
     vector<Flight> FindBestRoute(string source, string target);// da output de 1 caminho com a route mais pequena
     //! A normal method taking a set and string source (AirportCode) and string Target (AirportCode).
     /*!
         Returns a path with the shortest length possible that goes from the airportCode source and airportCode target
         With airlines blacklisted

         \Complexity  O(V+E) ,where V is the number of vertices (airports) in the graph and E is the number of edges (flights) in the graph
     */
     vector<Flight> FindBestRouteWithBlackListed(string source, string target,set<string> blackListAirlines);//faz o mesmo que a anterior com black listed
     //! A normal method taking a set and string source (AirportCode) and string Target (AirportCode).
     /*!
         Returns a path with the shortest length possible that goes from the airportCode source and airportCode target
         With airlines GreenListed(only uses the airlines in the set green list)
         \Complexity  O(V+E) , where V is the number of vertices (airports) in the graph and E is the number of edges (flights) in the graph
     */
     vector<Flight> FindBestRouteWithGreenListed(string source, string target,set<string> greenListAirlines);//faz o mesmo que a anterior com white listed
     //! A normal method taking a string source (AirportCode) and string Target (AirportCode).
     /*!
         Returns all possible paths with the shortest length possible that goes from the airportCode source and airportCode target
         \Complexity  O(R * (V+E)), where R is the number of routes found and V is the number of vertices (airports) in the graph and E is the number of edges (flights) in the graph

     */
     vector<vector<Flight>> FindBestRoutes1(string source, string target);//função calcula todas as routes entre os dois aeroportos
     //! This function is auxiliary to FindBestRoutes1.
     /*!
         Returns all possible paths with the shortest length possible that goes from the airportCode source and airportCode target
         \Complexity  O(R * (V+E)) , where R is the number of routes found and V is the number of vertices (airports) in the graph and E is the number of edges (flights) in the graph

     */
     vector<vector<Flight>> FindBestRoutes(string source, string target,vector<vector<Flight>>& result);//função auxiliar a anterior
     //! A normal method taking Coordinates and a int distance that returns a vector.
     /*!
         This method taking Coordinates and a int distance that returns a vector with the AirportCodes
         with the distance of distanteSource from the coordinates
         \Complexity  0(n)
     */
     vector<string> FindAirportsFromCordenadas(Cordenadas cordenadas,int distanceSource);//Encontra todos os aeroportos a distancia de distanceSource da cordenada
     //! A normal method taking a Country Name.
     /*!
         This method taking Country returns a vector with all AirportCodes in the Country
         \Complexity  0(n) , Where n is the number of airports in the country
     */
     vector<string> FindAirportsFromCountry(string country);//Encontra todos os aeroportos no pais contry
     //! A normal method taking a City Name.
     /*!
         This method taking City Name that returns a vector runs all AirportCodes
         in the city
         \Complexity  0(n) Where n is the number of airports in the city.
     */
     vector<string> FindAirportsFromCity(string city);//Encontra todos os aeroportos no cidade
     //! A normal method taking a vector of strings starts and a vector with targets and returns a vector of vectors with strings.
     /*!
         This method taking a vector of strings starts is made of AirportCodes and a vector with targets is made of AirportCodes
         returns a route per combination of aeroport if they have the minimum length.
         \Complexity   O(S * T * (V+E)) where S is the number of starting airports, T is the number of target airports,
         V is the number of vertices (airports) in the graph, and E is the number of edges (flights) in the graph.
     */
     vector<vector<Flight>> FindBestRoutesFromAirportsToAirports(vector<string> starts, vector<string> targets);//encontra entre os varios paises uma rota e da output as rotas com tamanho minimo
     int CountCountriesReachableInNFlights(const string& src, int n);//da output ao numero de paises que podes chegar de src em y fligths
     unordered_set<string> CountriesReachableInYFlights(const string& src, int y);//da output aos paises que podes chegar de src em y fligths
     set<string> findArticulationPoints();//find articulation Airports sao os quais se removeres em ves de um ciclo ficas com dois 


};


#endif //PROJ_MANAGER_H
