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
vector<Flight> Manager::getFlights() {
    return flights;
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
        flights.push_back(Flight(source, target, airline));
    }

}
vector<Flight> Manager::FindBestRoute(std::string source, std::string target) {
    queue<vector<Flight>> q;
    unordered_map<string, bool> visited;
    q.push({});
    visited[source] = true;
    while (!q.empty()) {
        vector<Flight> route = q.front();
        q.pop();
        string current = route.empty() ? source : route.back().getTarget();
        if (current == target) {
            return route;
        }
        for ( Flight flight : flights) {
            if (flight.getSource() == current && !visited[flight.getTarget()]) {
                vector<Flight> newRoute = route;
                newRoute.push_back(flight);
                q.push(newRoute);
                visited[flight.getTarget()] = true;
            }
        }
    }
    return {};
}


