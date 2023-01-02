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
#include<bits/stdc++.h>
Manager::Manager(){
}
vector<Airline> Manager::getAirlines(){
    return airlines;
}
unordered_map <string,Airport> Manager::getAirports() {
    return airports;
}
int Manager::getNumFlightFrom(string aiportCode){
    return graph.getEdges(aiportCode).size();
}
int Manager::getNumFlightTo(string aiportCode) {
    int result = 0;
    for(auto p : graph.getNodes()) {
        for(Flight f:p.second.adj){
            if(f.getTarget()==aiportCode)
                result++;
        }
    }
    //cout<<"O numero de que tem como destino o aeroporto com o codigo :"<<airport.getCode()<<" sao :"<<result<<'\n';
    return result;
}
int Manager::getNumFlightFromDiferentAirlinesFrom(string aiportCode){
    unordered_set<string> result;
    auto flights = graph.getEdges(aiportCode);
    for(auto flight : flights){
        result.insert(flight.getAirline());
    }

    return result.size();
}
int Manager::getNumFlightFromDiferentAirlinesTo(string aiportCode){
    unordered_set<string> result;
    for(auto p : graph.getNodes()) {
        for(Flight f:p.second.adj){
            if(f.getTarget()==aiportCode)
                result.insert(f.getAirline());
        }
    }
    return result.size();
}
int Manager::getNumFlightFromDiferentCountrysTo(string aiportCode){
    unordered_set<string> result;
    for(auto p : graph.getNodes()) {
        for(Flight f:p.second.adj){
            if(f.getTarget()==aiportCode)
                result.insert(f.getSource());
        }
    }

    return result.size();
}
int Manager::getNumFlightToDiferentCountrysFrom(string aiportCode){
    unordered_set<string> result;
    auto flights = graph.getEdges(aiportCode);
    for(auto flight : flights){
        result.insert(flight.getTarget());
    }

    return result.size();
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
vector<vector<Flight>> Manager::FindBestRoutes1(string source, string target) {
    Graph graph1 = graph;
    vector<vector<Flight>> result1;
    vector<Flight> route = FindBestRoute(source, target, graph1);
    result1.push_back(route);
    auto result =  FindBestRoutes(source,target,result1,graph1);


    return result;

}



vector<vector<Flight>> Manager::FindBestRoutes(string source, string target,vector<vector<Flight>>& result, Graph graph1) {

    // Find the shortest route
    vector<Flight> route = FindBestRoute(source, target, graph1);
    // If a route was found, add it to the result

    cout<<"---------------Called---------------------\n";
    // Find all routes with the same length as the shortest route
    int min = route.size();
    Graph tmp = graph1;
    int i = 0;
    for (Flight dele : route) {
        i++;
        cout<<i<<"---------------delete---------------------\n";
        tmp.delFlight(dele);
        cout << dele.getSource() << " " << dele.getTarget() << ' ' << dele.getAirline() << "   \n ";
        cout<<i<<"---------------add--------------------\n";
        cout << dele.getSource() << " " << dele.getTarget() << ' ' << dele.getAirline() << "    \n";
        tmp.addEdge(dele.getSource(),dele.getTarget(),dele.getAirline());
        vector<Flight> newRoute = FindBestRoute(source, target, tmp);

        if (newRoute.size() <= min && find(result.begin(), result.end(), newRoute) == result.end()) {
            for (auto a: route) {
                cout << a.getSource() << " " << a.getTarget() << ' ' << a.getAirline() << "    ";
            }
            cout<<"\n";
            result.push_back(newRoute);
            auto newRoutes = FindBestRoutes(source, target, result,tmp);
        }


    }
    return result;
}

vector<Flight> Manager::FindBestRoute(string source, string target,Graph graph1) {
    for (auto airport : airports)graph1.findFlightFrom(airport.first).visited = false;
    queue<vector<Flight>> q;
    q.push({});
    /*unordered_map<string, bool> visited;
    visited[source] = true;*/
    graph1.findFlightFrom(source).visited=true;
    while (!q.empty()) {
        vector<Flight> route = q.front();
        q.pop();
        string current = route.empty() ? source : route.back().getTarget();
        if (current == target) {
            return route;
        }

        for ( auto flight : graph1.findFlightFrom(current).adj) {
            if (!graph1.findFlightFrom(flight.getTarget()).visited) {

                vector<Flight> newRoute = route;
                newRoute.push_back(flight);
                q.push(newRoute);
                graph1.findFlightFrom(flight.getTarget()).visited=true;

            }

        }
    }

    return {};
}
int Manager::CountCountriesReachableInYFlights(const string& src, int y){
    unordered_set<string> countries;
    for(int i = 1 ; i<=y;i++){
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
Graph Manager::getGraph(){
    return graph;
}


