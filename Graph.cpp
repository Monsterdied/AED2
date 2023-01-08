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
void Graph::dfs_art(string v, bool isRoot, int &index, unordered_set<string> &points) {
    nodes[v].num = index;
    nodes[v].low = index;
    index++;
    nodes[v].inStack = true;
    int rootChilds = 0;
    for (const Flight &edge : nodes[v].adj) {
        string w = edge.getTarget();
        if (nodes[w].num == 0) {
            if (isRoot)
                rootChilds++;
            dfs_art(w, false, index, points);
            nodes[v].low = min(nodes[v].low, nodes[w].low);
            if ((!isRoot && nodes[w].low >= nodes[v].num and nodes[w].low>2) || (isRoot && rootChilds > 1)){
                if(v=="OIA"){cout<<w<<"\n\n\n";}
                points.insert(v);
            }

        } else if (nodes[w].inStack)
            nodes[v].low = min(nodes[v].low, nodes[w].num);
    }
    nodes[v].inStack = false;
}

unsigned Graph::diameter() {
    unsigned diametro = 0;
    resetNodes();
    for (auto node : nodes) {
        bfs_distance(node.first);
        for (auto node1 : nodes)
            if (nodes[node1.first].visited && nodes[node1.first].dist > diametro)
                diametro = nodes[node1.first].dist;
    }
    return diametro;
}
void Graph::resetNodes() {
    for (auto node : nodes) {
        bool visited;
        /**
        * @brief A unsigned that tells the distance from some Node.
        */
        nodes[node.first].visited = false;
        nodes[node.first].dist = INT_MAX;
        nodes[node.first].num = 0;
        nodes[node.first].low = 0;
        nodes[node.first].inStack = false;
    }
}
void Graph::bfs_distance(string v) {
    resetNodes();
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
int Graph::findSCC() {
    // Initialize variables
    int index = 1;
    stack<string> S;
    vector<unordered_set<string>> sccs;
    // Perform DFS on each node
    for (auto& node : nodes) {
        if (node.second.num == 0) {
            dfsSCC(node.first, index, S, sccs);
        }
    }

    return sccs.size();
}
void Graph::dfsSCC(string v, int &index, stack<string> &S, vector<unordered_set<string>> &sccs) {
    nodes[v].num = nodes[v].low = ++index;
    S.push(v);
    nodes[v].inStack = 1;
    for (const Flight &e : nodes[v].adj) {
        string w = e.getTarget();
        if (nodes[w].num == 0) {
            dfsSCC(w, index, S, sccs);
            nodes[v].low = min(nodes[v].low, nodes[w].low);
        }
        else if (nodes[w].inStack) {
            nodes[v].low = min(nodes[v].low, nodes[w].num);
        }
    }
    if (nodes[v].num == nodes[v].low) {
        unordered_set<string> scc;
        string w;
        do {
            w = S.top();
            S.pop();
            nodes[w].inStack = 0;
            scc.insert(w);
        } while (v != w);
            sccs.push_back(scc);
    }
}