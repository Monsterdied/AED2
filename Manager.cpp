//
// Created by tomas on 12/27/2022.
//

#include <sstream>
#include <iomanip>
#include "Manager.h"
#include "Coordinates.h"
#include "Airport.h"
#include "Flight.h"
#include "queue"
#include<bits/stdc++.h>
Manager::Manager(){
}
list<string> Manager::getAirportsInCity(string city){
    return cities[city];
}
Airport Manager::getAirportWithCode(string airportCode){
    return airports[airportCode];
}
Airline Manager::getAirlineWithCode(string airlineCode){
    return airlines[airlineCode];
}
set<string> Manager::getCitiesInCountry(string country){
    return countrysToCitys[country];
}
unordered_map <string,Airline>  Manager::getAirlines(){
    return airlines;
}
unordered_map <string,Airport> Manager::getAirports() {
    return airports;
}
int Manager::getNumFlightFrom(string airportCode){
    return graph.getEdges(airportCode).size();
}
int Manager::getNumFlightTo(string airportCode) {
    int result = 0;
    for(auto p : graph.getNodes()) {
        for(Flight f:p.second.adj){
            if(f.getTarget() == airportCode)
                result++;
        }
    }
    //cout<<"O numero de que tem como destino o aeroporto com o codigo :"<<airport.getCode()<<" sao :"<<result<<'\n';
    return result;
}
int Manager::getNumFlightFromDifferentAirlinesFrom(string airportCode){
    unordered_set<string> result;
    auto flights = graph.getEdges(airportCode);
    for(auto flight : flights){
        result.insert(flight.getAirline());
    }

    return result.size();
}
int Manager::getNumFlightFromDifferentAirlinesTo(string airportCode){
    unordered_set<string> result;
    for(auto p : graph.getNodes()) {
        for(Flight f:p.second.adj){
            if(f.getTarget() == airportCode)
                result.insert(f.getAirline());
        }
    }
    return result.size();
}
int Manager::getNumFlightFromDifferentCountriesTo(string airportCode){
    unordered_set<string> result;
    for(auto p : graph.getNodes()) {
        for(Flight f:p.second.adj){
            if(f.getTarget() == airportCode)
                result.insert(f.getSource());
        }
    }

    return result.size();
}
int Manager::getNumFlightToDifferentCountriesFrom(string airportCode){
    unordered_set<string> result;
    auto flights = graph.getEdges(airportCode);
    for(auto flight : flights){
        result.insert(flight.getTarget());
    }

    return result.size();
}

void Manager::ReadAirLines() {
    ifstream file;
    file.open("../Data/airlines.csv");
    if (!file.is_open()) {
        cerr << "Error opening file" << endl;
    }
    string full_str;
    string code = "",name = "",callsign = "",country = "";
    getline(file,full_str,'\n');
    while(file.good()) {
        getline(file, full_str, '\n');
        stringstream ss(full_str);
        getline(ss, code, ',');
        getline(ss, name, ',');
        getline(ss, callsign, ',');
        getline(ss, country, ',');
        airlines.insert({code,Airline(code,name,callsign,country)});
    }
}

void Manager::ReadAirports() {
    unordered_map <string, Airport> airports;
    unordered_map <string, list<string>> cities;

    ifstream file;
    file.open("../Data/airports.csv");
    if (!file.is_open()) {
        cerr << "Error opening file" << endl;
    }

    string full_str, latitudeStr, longitudeStr, name, code, city, country;
    getline(file, full_str);
    while(file.good()) {
        getline(file, full_str, '\n');
        stringstream ss(full_str);
        getline(ss, code, ',');
        getline(ss, name, ',');
        getline(ss, city, ',');
        getline(ss, country, ',');
        getline(ss, latitudeStr, ',');
        getline(ss, longitudeStr, ',');
        double latitude = stod(latitudeStr);
        double longitude = stod(longitudeStr);
        airports.insert({code, Airport(latitude,longitude,name,code,city,country)});
//not sure if we need this if
        /*if (cities.count(city) == 0) {
            list<string> tmpList;
            cities[city] = tmpList;
        }*/
        cities[city].push_back(code);
        countrysToCitys[country].insert(city);
    }
    this->cities = cities;
    this->airports= airports;
}

void Manager::ReadFlights() {
    ifstream file;
    file.open("../Data/flights.csv");
    if (!file.is_open()) {
        cerr << "Error opening file" << endl;
    }
    string full_str;
    string source = "", target = "", airline = "";
    getline(file, full_str, '\n');
    while (file.good()) {
        getline(file, full_str, '\n');
        stringstream ss(full_str);
        getline(ss, source, ',');
        getline(ss, target, ',');
        getline(ss, airline, ',');
        graph.addEdge(source,target,airline);
        //flights.push_back(Flight(source, target, airline));
    }

}
vector<vector<Flight>> Manager::FindBestRoutes1(string source, string target) {
    vector<vector<Flight>> result1;
    vector<Flight> route = FindBestRoute(source, target);
    result1.push_back(route);
    auto result =  FindBestRoutes(source,target,result1);


    return result;

}



vector<vector<Flight>> Manager::FindBestRoutes(string source, string target,vector<vector<Flight>>& result) {

    // Find the shortest route
    // If a route was found, add it to the result

    // Find all routes with the same length as the shortest route
    int min = result[0].size();
    for (Flight dele : result.back()) {
        //to isolate the flight
        graph.delFlight(dele);

        vector<Flight> newRoute = FindBestRoute(source, target);
        if (newRoute.size() <= min && find(result.begin(), result.end(), newRoute) == result.end()) {
            result.push_back(newRoute);
            auto newRoutes = FindBestRoutes(source, target, result);
        }
        graph.addFlight(dele);

    }
    return result;
}

vector<Flight> Manager::FindBestRoute(string source, string target) {
    for (auto airport : airports)graph.findFlightFrom(airport.first).visited = false;
    queue<vector<Flight>> q;
    q.push({});
    /*unordered_map<string, bool> visited;
    visited[source] = true;*/


    graph.findFlightFrom(source).visited=true;
    while (!q.empty()) {
        vector<Flight> route = q.front();
        q.pop();
        string current = route.empty() ? source : route.back().getTarget();
        if (current == target) {
            return route;
        }

        for ( auto flight : graph.findFlightFrom(current).adj) {
            if (!graph.findFlightFrom(flight.getTarget()).visited && !flight.getUsed()) {

                vector<Flight> newRoute = route;
                newRoute.push_back(flight);
                q.push(newRoute);
                graph.findFlightFrom(flight.getTarget()).visited=true;

            }

        }
    }

    return {};
}
int Manager::CountCountriesReachableInNFlights(const string& src, int n){
    unordered_set<string> countries;
    for(int i = 1 ; i<=n;i++){
        auto tmp = CountriesReachableInYFlights(src,i);
        for(string s : tmp){
            countries.insert(s);
        }
    }
    return countries.size();
}
unordered_set<string> Manager::CountriesReachableInYFlights(const string& src, int y) {
    unordered_set<string> countries;
    for (auto airport : airports)graph.findFlightFrom(airport.first).visited = false;
    queue<pair<string, int>> q;
    q.push({src, 0});
    graph.findFlightFrom(src).visited = true;
    while (!q.empty()) {
        pair<string, int> current = q.front();
        q.pop();
        if (current.second == y) {
            countries.insert(airports[current.first].getCountry());
        } else {
            for (const Flight& flight : graph.getEdges(current.first)) {
                if (!graph.findFlightFrom(flight.getTarget()).visited) {
                    q.push({flight.getTarget(), current.second + 1});
                    graph.findFlightFrom(flight.getTarget()).visited = true;
                }
            }
        }
    }
    return countries;
}
vector<string> Manager::FindAirportsFromCoordinates(Coordinates coordinates, int distanceSource) {
    vector<string> result;
    for(auto paired : airports){
        Airport airport = paired.second;
        if(coordinates.getDistance(airport.getCoordinates()) <= distanceSource){
            result.push_back(airport.getCode());
        }
    }
    return result;

}
vector<string> Manager::FindAirportsFromCountry(string country){
    set<string> cities = getCitiesInCountry(country);
    vector<string> result;
    for(string city : cities) {
        vector<string> aeroports_from_citie = FindAirportsFromCity(city);
        for(string aeroport : aeroports_from_citie) {
            //cout<<aeroport<<" \n";
            result.push_back(aeroport);
        }

    }
    return result;
}
vector<string> Manager::FindAirportsFromCity(string city){
    list<string> aeroports = cities[city];
    vector<string> result;
    for(string i : aeroports)
        result.push_back(i);
    return result;
}
vector<vector<Flight>> Manager::FindBestRoutesFromAirportsToAirports(vector<string> starts, vector<string> targets) {
    vector<vector<Flight>> result;
    int min = INT_MAX;
    for(string source : starts){
        for(string target : targets){
            vector<Flight> route = FindBestRoute(source,target);
            if(route.size() < min){
                result.clear();
                min = route.size();
            }
            if(route.size() <= min){
                result.push_back(route);
            }
        }
    }
    return result;
}


// Function to find the articulation points in the graph represented by the Manager object
set<string> Manager::findArticulationPoints() {
    unordered_map<string, int> num;
    unordered_map<string, int> low;
    set<string> S;
    set<string> ap;
    int index = 0;

    // Call the helper function for each node
    for (auto& p : airports) {
        if (num.find(p.first) == num.end()) {
            graph.dfs(p.first, index, num, low, S, ap);
        }
    }

    return ap;
}
//ainda não checkei
vector<Flight> Manager::FindBestRouteWithBlackListed(string source, string target,set<string> blackListAirlines) {
    for (auto airport : airports)graph.findFlightFrom(airport.first).visited = false;
    queue<vector<Flight>> q;
    q.push({});
    /*unordered_map<string, bool> visited;
    visited[source] = true;*/
    graph.findFlightFrom(source).visited=true;
    while (!q.empty()) {
        vector<Flight> route = q.front();
        q.pop();
        string current = route.empty() ? source : route.back().getTarget();
        if (current == target) {
            return route;
        }

        for ( auto flight : graph.findFlightFrom(current).adj) {
            if (!graph.findFlightFrom(flight.getTarget()).visited && !flight.getUsed() && !blackListAirlines.count(flight.getAirline())) {
                vector<Flight> newRoute = route;
                newRoute.push_back(flight);
                q.push(newRoute);
                graph.findFlightFrom(flight.getTarget()).visited=true;

            }

        }
    }

    return {};
}

//ainda não checkei
vector<Flight> Manager::FindBestRouteWithGreenListed(string source, string target,set<string> greenListAirlines) {
    for (auto airport : airports)graph.findFlightFrom(airport.first).visited = false;
    queue<vector<Flight>> q;
    q.push({});
    /*unordered_map<string, bool> visited;
    visited[source] = true;*/
    graph.findFlightFrom(source).visited=true;
    while (!q.empty()) {
        vector<Flight> route = q.front();
        q.pop();
        string current = route.empty() ? source : route.back().getTarget();
        if (current == target) {
            return route;
        }

        for ( auto flight : graph.findFlightFrom(current).adj) {
            if (!graph.findFlightFrom(flight.getTarget()).visited && !flight.getUsed() && greenListAirlines.count(flight.getAirline())) {
                vector<Flight> newRoute = route;
                newRoute.push_back(flight);
                q.push(newRoute);
                graph.findFlightFrom(flight.getTarget()).visited=true;

            }
        }
    }

    return {};
}

Graph Manager::getGraph(){
    return graph;
}


