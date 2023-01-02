//
// Created by tomas on 12/28/2022.
//

#include "Graph.h"
#include<bits/stdc++.h>
Graph::Graph(){
}

// Add edge from source to destination with a certain weight
void Graph::addEdge(string src, string dest, string airlineCode) {
    nodes[src].adj.push_back({src,dest,airlineCode});
    nodes[dest];
}

void Graph::delFlight(Flight flight){
    list<Flight>& tmp = nodes[flight.getSource()].adj;
    auto it = find(tmp.begin(), tmp.end(), flight);
    if (it != tmp.end()) {
        tmp.erase(it);
    }
}

unordered_map <string,Graph::Node> Graph::getNodes(){
    return nodes;
}
list<Flight> Graph::getEdges(string code){
    return nodes[code].adj;
}
Graph::Node& Graph::findFlightFrom(string codeAirport){
    return nodes.find(codeAirport)->second;
}
vector<Flight> Graph::findFlights(string codeSrc , string codeDest) {
    auto flights = nodes[codeSrc].adj;
    vector<Flight> result;
    for(Flight flight :flights){
        if(flight.getTarget()==codeDest){
            result.push_back(flight);
        }
    }
    return result;
}