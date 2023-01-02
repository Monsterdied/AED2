//
// Created by tomas on 12/28/2022.
//

#ifndef PROJ_GRAPH_H
#define PROJ_GRAPH_H

#include <list>
#include <vector>
#include <queue>
#include <iostream>
#include <unordered_map>
#include "Airline.h"
#include "Flight.h"
using namespace std;

class Graph {
private:
public:
    struct Node {
        list<Flight> adj; // The list of outgoing edges (to adjacent nodes)
        bool visited;   // As the node been visited on a search?
    };
    // Graph size (vertices are numbered from 1 to n)
    unordered_map <string,Node> nodes; // The list of nodes being represented


    // Constructor: nr nodes and direction (default: undirected)
    Graph();

    // Add edge from source to destination with a certain weight
    void addEdge(string src, string dest, string airline);
    void delFlight(Flight flight);
    unordered_map <string,Node> getNodes();
    list<Flight> getEdges(string code);
    Node& findFlightFrom(string codeAirport);
    vector<Flight> findFlights(string codeSrc , string codeDest);
    // ----- Functions to implement in this class -----
    int distance(int a, int b);
    int diameter();


};


#endif //PROJ_GRAPH_H
