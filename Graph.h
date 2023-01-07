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
#include <set>
#include "Airline.h"
#include "Flight.h"
using namespace std;

class Graph {
private:
public:
    /**
     * @brief Represents a node (airport) in the graph.
     */
    struct Node {
        /**
         * @brief The airport code.
         */
        string code;
        /**
         * @brief The list of flights from this airport.
         */
        list<Flight> adj;
    };
    /**
    * @brief A map of nodes (airports) in the graph, indexed by their codes.
    */
    unordered_map <string,Node> nodes;

    /**
     * @brief Constructs an empty Graph object.
     *
     * The complexity of this member function is O(1).
     */
    Graph();

    /**
     * @brief Adds an edge (flight) from the source airport to the destination airport with the given airline code.
     *
     * The complexity of this member function is O(1).
     *
     * @param src The source airport code.
     * @param dest The destination airport code.
     * @param airlineCode The airline code operating the flight.
     */
    void addEdge(string src, string dest, string airlineCode);

    /**
     * @brief Adds a flight to the graph.
     *
     * The complexity of this member function is O(n), where `n` is the number of flights from the source airport.
     *
     * @param flight The flight to add.
     */
    void addFlight(Flight flight);

    /**
     * @brief Deletes a flight from the graph.
     *
     * The complexity of this member function is O(n), where `n` is the number of flights from the source airport.
     *
    * @param flight The flight to delete.
    */
    void delFlight(Flight flight);

    /**
     * @brief Returns the nodes (airports) in the graph.
     *
     * The complexity of this member function is O(n), where `n` is the number of nodes in the graph.
     *
     * @return The nodes in the graph.
     */
    unordered_map <string,Node> getNodes();

    /**
     * @brief Returns the edges (flights) from the given airport code.
     *
     * The complexity of this member function is O(1).
     *
     * @param code The airport code.
     * @return The edges from the given airport.
     */
    list<Flight> getEdges(string code);

    /**
     * @brief Finds the node (airport) with the given code.
     *
     * The complexity of this member function is O(1).
     *
     * @param codeAirport The airport code.
     * @return The node with the given code.
     */
    Node& findFlightFrom(string codeAirport);

    /**
     * @brief Finds the flights between the source and destination airports with the given codes.
     *
     * The complexity of this member function is O(n), where `n` is the number of flights from the source airport.
     *
     * @param codeSrc The source airport code.
     * @param codeDest The destination airport code.
     * @return The flights between the source and destination airports.
     */
    vector<Flight> findFlights(string codeSrc , string codeDest);

    /**
     * @brief Performs a depth-first search (DFS) on the graph.
     *
     * The complexity of this member function is O(n + m), where `n` is the number of nodes in the graph and `m` is the number of edges.
     *
     * @param node The starting node for the DFS.
     * @param index A reference to the current index of the DFS.
     * @param num A map of nodes to their DFS numbers.
     * @param low A map of nodes to their low numbers.
     * @param S A set of nodes in the DFS stack.
     * @param ap A set of articulation points in the graph.
     */
    void dfs(string node, int& index, unordered_map<string, int>& num, unordered_map<string, int>& low, set<string>& S, set<string>& ap);


};


#endif //PROJ_GRAPH_H
