//
// Created by tomas on 12/27/2022.
//

#include <sstream>
#include <iomanip>
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
unordered_map <string,Airport> Manager::getAirports() {
    return airports;
}
void Manager::getNumFlightTo(string aiportCode) {
    int result = 0;
    for(auto p : graph.getNodes()) {
        for(Flight f:p.second.adj){
            if(f.getTarget()==aiportCode)
                result++;
        }
    }
    Airport airport = airports[aiportCode];
    cout<<"O numero de que tem como destino o aeroporto com o codigo :"<<airport.getCode()<<" sao :"<<result<<'\n';

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
vector<vector<Flight>> Manager::FindBestRoutes1(string source, string target){
    vector<vector<Flight>> op ;
    auto route = FindBestRoute(source,target,graph);
    auto result = FindBestRoutes(source,target,route,graph);
    result.push_back(route);
    return  FindBestRoutes(source,target,route,graph);
}
vector<vector<Flight>> Manager::FindBestRoutes(string source, string target,vector<Flight> route,Graph graph1){
    vector<vector<Flight>> result ;
    int min = route.size();
    for(Flight dele : route){
        Graph tmp = graph1;
        tmp.delFlight(dele);
        auto newRoute = FindBestRoute(source,target,tmp);
        if(min==newRoute.size()){
            result.push_back(newRoute);
            for (auto a: newRoute) {
                cout << a.getSource() << " " << a.getTarget() << ' ' << a.getAirline() << "    ";
            }
            cout << "\n";

            auto newRoutes = FindBestRoutes(source,target,newRoute,tmp);
            result.insert(result.end(),newRoutes.begin(),newRoutes.end());
        }
    }
    return result;
}


vector<Flight> Manager::FindBestRoute(string source, string target,Graph graph1) {
    for (auto airport : airports)graph1.findFlight(airport.first).visited = false;
    queue<vector<Flight>> q;
    q.push({});
    /*unordered_map<string, bool> visited;
    visited[source] = true;*/
    graph1.findFlight(source).visited=true;
    while (!q.empty()) {
        vector<Flight> route = q.front();
        q.pop();
        string current = route.empty() ? source : route.back().getTarget();
        if (current == target) {
            return route;
        }

        for ( auto flight : graph1.findFlight(current).adj) {
            if (!graph1.findFlight(flight.getTarget()).visited) {

                vector<Flight> newRoute = route;
                newRoute.push_back(flight);
                q.push(newRoute);
                graph1.findFlight(flight.getTarget()).visited=true;

            }

        }
    }

    return {};
}
Graph Manager::getGraph(){
    return graph;
}


