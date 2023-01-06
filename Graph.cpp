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
void Graph::addFlight(Flight flight) {
    list<Flight>& tmp = nodes[flight.getSource()].adj;
    auto it = find(tmp.begin(), tmp.end(), flight);
    if (it != tmp.end()) {
        it->setUsed(false);

    }

}

void Graph::delFlight(Flight flight){
    list<Flight>& tmp = nodes[flight.getSource()].adj;
    auto it = find(tmp.begin(), tmp.end(), flight);
    if (it != tmp.end()) {
        it->setUsed(true);

    }
}

unordered_map <string,Graph::Node> Graph::getNodes(){
    return nodes;
}
list<Flight> Graph::getEdges(string code){
    return nodes[code].adj;
}
Graph::Node& Graph::findFlightFrom(string codeAirport){
    return nodes[codeAirport];
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
void Graph::dfs(string node, int& index, unordered_map<string, int>& num, unordered_map<string, int>& low, set<string>& S, set<string>& ap) {
    // Set num and low values and push node onto the stack
    num[node] = low[node] = index++;
    S.insert(node);

    // Go through all the neighbors of node
    for (Flight f : getEdges(node)) {
        string w = f.getTarget();

        // If w has not been visited before, it is a tree edge
        if (num.find(w) == num.end()) {
            dfs(w, index, num, low, S, ap);
            low[node] = min(low[node], low[w]);

            // If the subtree rooted at w has a connection to one of the ancestors of node, node is an articulation point
            if (low[w] >= num[node]) {
                ap.insert(node);
            }
        }

            // If w is in the stack, it is a back edge
        else if (S.find(w) != S.end()) {
            low[node] = min(low[node], num[w]);
        }
    }

    // Pop node from the stack
    S.erase(node);
}