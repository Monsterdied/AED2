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
unsigned Graph::diameter() {
    unsigned diametro = 0;
    for (auto node : nodes) {
        bfs_distance(node.first);
        for (auto node1 : nodes)
            if (nodes[node1.first].visited && nodes[node1.first].dist > diametro)
                diametro = nodes[node1.first].dist;
    }
    return diametro;
}
void Graph::bfs_distance(string v) {
    for (auto node : nodes) nodes[node.first].visited = false;
    queue<string> q; // queue of unvisited nodes
    q.push(v);
    nodes[v].visited = true;
    nodes[v].dist = 0;
    while (!q.empty()) { // while there are still unvisited nodes
        string u = q.front(); q.pop();
        for (auto e : nodes[u].adj) {
            string w = e.getTarget();
            if (!nodes[w].visited) {
                q.push(w);
                nodes[w].dist = nodes[u].dist +1;
                nodes[w].visited = true;
            }
        }
    }
}