//
// Created by tomas on 12/27/2022.
//

#include <sstream>
#include "Manager.h"
#include "Cordenadas.h"
#include "Airport.h"
#include "Flight.h"
#include "queue"

Manager::Manager(){
}
vector<Airline> Manager::getAirlines(){
    return airlines;
}
unordered_map <string,Airport> Manager::getAirports(){
    return airports;
}

void Manager::ReadAirLines() {
    vector<Airline> airlines;
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
        airlines.push_back(Airline(code,name,callsign,country));
    }
    this->airlines= airlines;
    }
void Manager::ReadAirports() {
    unordered_map <string,Airport> airports ;
    ifstream file;
    file.open("../Data/airports.csv");
    if (!file.is_open()) {
        cerr << "Error opening file" << endl;
    }
    string full_str;
    string latitudeStr ="",longitudeStr="" , name="" , code="" , city="" , country="";
    getline(file,full_str,'\n');
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
    }
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
vector<Graph::Flight> Manager::FindBestRoute(std::string source, std::string target) {
    for (auto airport : airports)graph.findFlight(airport.first).visited = false;
    queue<vector<Graph::Flight>> q;
    q.push({});
    /*unordered_map<string, bool> visited;
    visited[source] = true;*/
    graph.findFlight(source).visited=true;
    while (!q.empty()) {
        vector<Graph::Flight> route = q.front();
        q.pop();
        string current = route.empty() ? source : route.back().destinationCode;
        if (current == target) {
            return route;
        }

        for ( auto flight : graph.findFlight(current).adj) {
            if (!graph.findFlight(flight.destinationCode).visited) {
                vector<Graph::Flight> newRoute = route;
                newRoute.push_back(flight);
                q.push(newRoute);
                graph.findFlight(flight.destinationCode).visited=true;

            }
        }
    }
    return {};
}
Graph Manager::getGraph(){
    return graph;
}


