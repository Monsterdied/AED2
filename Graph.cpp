//
// Created by tomas on 12/28/2022.
//

#include "Graph.h"
Graph::Graph(){
}

// Add edge from source to destination with a certain weight
void Graph::addEdge(string src, string dest, string airlineCode) {
    nodes[src].adj.push_back({dest, airlineCode,src});
    nodes[dest];
}

unordered_map <string,Graph::Node> Graph::getNodes(){
    return nodes;
}
list<Graph::Flight> Graph::getEdges(string code){
    return nodes[code].adj;
}
Graph::Node& Graph::findFlight(string codeAirport){
    return nodes.find(codeAirport)->second;
}