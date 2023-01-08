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
     //! An class constructor taking no arguments and doesn't return anything.
    Manager();
     //! An normal method taking no arguments and doesn't return anything.
     /*!
         Reads the files then put the data in their respective data structures.
         \Complexity  0(n)
         \n Where the n is the number on lines (in this case the airlines) in the file.
     */
    void ReadAirLines();
     //! An void method taking no arguments and doesn't return anything.
     /*!
         Reads the files them in their respective data structures.
         \Complexity  0(N log(E) + N log(S))
         \n
           Where N is the number of airports, E the number of airports int the city and S the number of cities in a Country
     */
    void ReadAirports();
     //! An void method taking no arguments and doesn't return anything.
     /*!
         Reads the files them in their respective data structures.
         \Complexity  0(n)
         \n Where the n is the number on lines (in this case the flights) in the file.
     */
    void ReadFlights();
     //! An List<String> method taking the name of the city and returns the airports in that city.
     /*!
         This method utilizes unordered_map so it's very efficient .
         \Complexity  0(1)
         \Arguments @b String city
     */
    list<string> getAirportsInCity(string city);
     //! An set<string> method taking the name of the country and returns the cities in that country.
     /*!
         This method utilizes unordered_map so it's very efficient.
         \Complexity  0(1)
         \Arguments @b String Country
     */
    set<string> getCitiesInCountry(string country);
     //! An Airport method taking The airportCode and then returns the airport with that code.
     /*!
         This method utilizes unordered_map so it's very efficient.
         \Complexity  0(1)
         \Arguments @b String airportCode
     */
    Airport getAirportWithCode(string airportCode);
     //! An Airline method taking The airlineCode that returns the airline with that code.
     /*!
         This method utilizes unordered_map so is very efficient.
         \Complexity  0(1)
         \Arguments @b String airlineCode
     */
     Airline getAirlineWithCode(string airlineCode);
     //! An integer method that takes the airportCode and returns the number of flights to that airport.
     /*!
         This method uses a iterator.
         \Complexity  0(n) \n Where n is the number of flights.
         \Arguments @b String airportCode
     */
    int getNumFlightTo(string aiportCode);
     //! An integer method taking The airportCode and that returns the number of flights from that airport.
     /*!
         This method utilizes unordered_map so it's very efficient.
         \Complexity  0(1)
         \Arguments @b string airportCode
     */
    int getNumFlightFrom(string aiportCode);
     //! An integer method taking the airportCode and returns the number of flights to a certain airport that has the airportCode and is referring to from different airlines.
     /*!

         \Complexity  0(n) \n Where the n is the number of flights
         \Arguments @b String airportCode

     */
    int getNumFlightFromDifferentAirlinesTo(string aiportCode);
     //! An integer method taking The AirportCode that returns the flights that begin in the Airport that the airportCode is referring to
     /*!
         This method utilizes the unordered_map so it's very efficient.
         \Complexity  0(1)
         \Arguments @b String airportCode
     */
    int getNumFlightFromDifferentAirlinesFrom(string aiportCode);
     //! An integer method taking The AirportCode that returns the number of flights to a certain airport that the airportCode is referring to from different Countries.
     /*!
         \Complexity  0(nlog(n)) \n Where n is the number of flights
         \Arguments @b String airportCode

     */
    int getNumFlightFromDifferentCountriesTo(string aiportCode);
     //! An integer method taking The AirportCode that returns the number of flights from a certain airport that the airportCode is referring to from different Countries
     /*!
         \Complexity  0(log(n)) \n Where the n is the number of flights
     */
    int getNumFlightToDifferentCountriesFrom(string aiportCode);
     //! An unordered_map-string,Airline- method taking no arguments and returns an unordered_map, where the key is the AirlineCode.
     /*!
         \Complexity 0(1)
     */
     unordered_map <string,Airline>  getAirlines();
     //! A unordered_map-string,Airline- method taking no arguments and returns an unordered_map where the key is the AirportCode.
     /*!
         \Complexity 0(1)
     */
     unordered_map <string,Airport> getAirports();
     //! A vector-Flight- method taking a string source (AirportCode) and string Target (AirportCode).
     /*!
         \n Returns a path with the shortest length possible that goes from the airportCode source and airportCode target
         \Complexity  O(V+E) \n Where V is the number of vertices (airports) in the graph and E is the number of edges (flights) in the graph
         \Arguments @b String source
         \n @b String target
     */
     vector<Flight> FindBestRoute(string source, string target);
     //! A vector-Flight- method taking a set and string source (AirportCode) and string Target (AirportCode).
     /*!
         \n Returns a path with the shortest length possible that goes from the airportCode source and airportCode target with blacklisted Airlines.

         \Complexity  O(V+E) \n Where V is the number of vertices (airports) in the graph and E is the number of edges (flights) in the graph
         \Arguments @b String source
         \n @b String target
         \n @b Set-string- blackListAirlines
     */
     vector<Flight> FindBestRouteWithBlackListed(string source, string target,set<string> blackListAirlines);
     //! A vector-Flight- method taking a set and string source (AirportCode) and string Target (AirportCode).
     /*!
         Returns a path with the shortest length possible that goes from the airportCode source and airportCode target
         With airlines GreenListed(only uses the airlines in the set green list)
         \Complexity  O(V+E) \n Where V is the number of vertices (airports) in the graph and E is the number of edges (flights) in the graph
         \Arguments @b String source
         \n @b String target
         \n @b Set-string- greenListAirlines
     */
     vector<Flight> FindBestRouteWithGreenListed(string source, string target,set<string> greenListAirlines);
     //! A vector-Flight- method taking a string source (AirportCode) and string Target (AirportCode).
     /*!
         Returns all possible paths with the shortest length possible that goes from the airportCode source and airportCode target
         \Complexity  O(R * (V+E)) \n where R is the number of routes found and V is the number of vertices (airports) in the graph and E is the number of edges (flights) in the graph
         \Arguments @b String source
         \n @b String target
     */
     vector<vector<Flight>> FindBestRoutes1(string source, string target);
     //! This function is auxiliary to FindBestRoutes1.
     /*!
         Returns all possible paths with the shortest length possible that goes from the airportCode source and airportCode target
         \Complexity  O(R * (V+E)) , where R is the number of routes found and V is the number of vertices (airports) in the graph and E is the number of edges (flights) in the graph

     */
     vector<vector<Flight>> FindBestRoutes(string source, string target,vector<vector<Flight>>& result);
     //! A vector-string- method taking Coordinates and a int distance that returns an vector.
     /*!
         This method taking Coordinates and a int distance that returns a vector with the AirportCodes with the distance of distanteSource from the coordinates.
         \Complexity  0(n)
         \Arguments @b Coordinates cordenadas
         \n @b int distanceSource
     */
     vector<string> FindAirportsFromCoordinates(Coordinates coordinates, int distanceSource);
     //! A normal method taking a Country Name.
     /*!
         This method taking Country returns a vector with all AirportCodes in the Country
         \Complexity  0(n) \n Where n is the number of airports in the country
     */
     vector<string> FindAirportsFromCountry(string country);
     //! A vector-string- method taking a City Name.
     /*!
         This method taking City Name that returns a vector with all AirportCodes in the city
         \Complexity  0(n) Where n is the number of airports in the city.
         \Arguments @b string city
     */
     vector<string> FindAirportsFromCity(string city);
     //! A vector-flight- method taking a vector of strings starts and a vector with targets and returns a vector of vectors with strings.
     /*!
         This method returns a route per combination of airports if they have the minimum length.
         \Complexity   O(S * T * (V+E)) \n  Where S is the number of starting airports, T is the number of target airports,
         V is the number of vertices (airports) in the graph, and E is the number of edges (flights) in the graph.
         \Arguments @b vector-string- starts
         \n @b vector-string- targets
     */
     vector<vector<Flight>> FindBestRoutesFromAirportsToAirports(vector<string> starts, vector<string> targets);
     //! A integer method taking a  strings source and an integer n, where n is the number of flights and the source is the airportcode.
     /*!
         This method returns the number of countries that are reachable within n flights
         \Complexity   O(n*m) \n  Where n is the number of flights allowed, m is the average number of countries reachable in y flights
         \Arguments @b string src
         \n @b int n
     */
     int CountCountriesReachableInNFlights(const string& src, int n);
     //! A unordered_set-string- method taking a  strings source and an integer n, where y is the number of flights and the source is the airportcode.
     /*!
         This method returns the an set of countries that are reachable within y flights
         \Complexity   O(n+m) \n  Where n is the number of airports, m is the number of flights.
         \Arguments @b string src
         \n @b int y
     */
     unordered_set<string> CountriesReachableInYFlights(const string& src, int y);
        /**
        * @brief Identifies the articulation points in the graph and prints them to the console.
        *
        \Complexity O(V+E)
        */
     void ArticulationPoints();
    /**

    @brief Returns the diameter of the graph, which is defined as the maximum distance between any pair of vertices in the graph.
    @return The diameter of the graph.
    @complexity O(|V| * (|V| + |E|))
    */
    int diameter();
     /**
 
    @brief Finds the strongly connected components (SCCs) in the graph.
    @return The number of SCCs found.
    @complexity O(|V| + |E|)
    */
    int StronglyConnectedComponents();
};


#endif //PROJ_MANAGER_H
