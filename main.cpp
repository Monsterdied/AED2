#include <iostream>
#include <vector>
#include <fstream>
#include "Coordinates.h"
#include "Airport.h"
#include "Airline.h"
#include "Manager.h"
#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <fstream>
#include "Coordinates.h"
#include "Airport.h"
#include "Airline.h"
#include "Manager.h"
#include<bits/stdc++.h>

void mainMenu(Manager &manager);

void airlinerMenu(Manager manager);
void printAirlinesInCountry(vector<Airline> airlines, string country);
void printAllAirlines(Manager manager);
void printAirline(vector<Airline> airlines, string string1, const string& mode);

void airportMenu(Manager manager);
void printAirport(Manager manager, string val, const string& mode);
void printAllAirports(Manager manager);
void printAirportsInCity(Manager manager, string city);
void printAirportsInCountry(Manager manager, string country);
void printAirportFromCoordinates(Manager manager, Coordinates coordinates, int maxDistance);
void printNumCountriesReachableInNFlights(Manager manager, string src, int n);

void flightMenu(Manager manager);
void printBestRoute(Manager manager, vector<string> sources, vector<string> targets);
void printBestRouteWithBlacklist(Manager manager, string source, string target, set<string> blackListAirlines);
void printBestRouteWithGreenlist(Manager manager, string source, string target, set<string> greenListAirlines);

void numFlightMenu(Manager manager);
void printNumFlights(Manager manager, string code, string mode);

int main() {
    Manager manager;
    manager.ReadAirLines();
    manager.ReadAirports();
    manager.ReadFlights();

    mainMenu(manager);
}

void mainMenu(Manager &manager) {
    while (true) {
        string input;
        do {
            cout << "__________________________________________" << endl;
            cout << "Welcome to Flight Network System L.EIC GUI" << endl;
            cout << "Select one of the following options: " << endl;
            cout << " 1. Info about airliners" << endl;
            cout << " 2. Info about airports" << endl;
            cout << " 3. Flight menu" << endl;
            cout << " 4. Get number of flights to/from locations" << endl;
            cout << " 9. Close program" << endl;
            cout << "Type option:";
            cin >> input;
            cout << endl;

            if (!(input == "1" || input == "2" || input == "3" || input == "4" || input == "9"))
                cout <<  "Option " << input << " doesn't exist. Try again." << endl;
        } while(!(input == "1" || input == "2" || input == "3" || input == "4" || input == "9"));

        if (input == "1")
            airlinerMenu(manager);
        else if (input == "2")
            airportMenu(manager);
        else if (input == "3")
            flightMenu(manager);
        else if (input == "4")
            numFlightMenu(manager);
        else if (input == "9") {
            cout << "Program successfully closed";
            return;
        }
    }
}

void airlinerMenu(Manager manager) {
    while (true) {
        string input;
        do {
            cout << "____________________________________" << endl;
            cout << "Select one of the following options: " << endl;
            cout << " 1. Search airliner by name" << endl;
            cout << " 2. Search airliner by code" << endl;
            cout << " 3. Search airliner by call sign" << endl;
            cout << " 4. Show airliners in country" << endl;
            cout << " 5. Show all airliners" << endl;
            cout << " 9. Close program" << endl;
            cout << "Type option:";
            cin >> input;
            cout << endl;

            if (!(input == "1" || input == "2" || input == "3" || input == "4" || input == "5" || input == "9"))
                cout <<  "Option " << input << " doesn't exist. Try again." << endl;
        } while(!(input == "1" || input == "2" || input == "3" || input == "4" || input == "5" || input == "9"));

        vector<Airline> airlines;
        for(auto paired : manager.getAirlines()) {
            airlines.push_back(paired.second);
        }

        if (input == "1") {
            cout << "Type airline name: ";
            string name1, name2;
            cin >> name1;
            getline(cin, name2);
            cout << endl;
            string name = name1 + name2;
            printAirline(airlines, name, "name");
        }
        else if (input == "2"){
            cout << "Type airline code: ";
            string code;
            cin >> code;
            cout << endl;
            printAirline(airlines, code, "code");
        }
        else if (input == "3"){
            cout << "Type airline country sign: ";
            string callSign1, callSign2;
            cin >> callSign1;
            getline(cin, callSign2);
            cout << endl;
            string callSign = callSign1 + callSign2;
            printAirline(airlines, callSign, "callsign");
        }
        else if (input == "4"){
            cout << "Type country name: ";
            string country1, country2;
            cin >> country1;
            getline(cin, country2);
            cout << endl;
            string country = country1 + country2;
            printAirlinesInCountry(airlines, country);
        }
        else if (input == "5")
            printAllAirlines(manager);
        else if (input == "9")
            return;
    }
}

void airportMenu(Manager manager) {
    while (true) {
        string input;
        do {
            cout << "__________________________________________" << endl;
            cout << "Select one of the following options: " << endl;
            cout << " 1. Search airport by name" << endl;
            cout << " 2. Search airport by code" << endl;
            cout << " 3. Search airports by coordinates" << endl;
            cout << " 4. Show airport(s) in country" << endl;
            cout << " 5. Show airport(s) in city" << endl;
            cout << " 6. Show all airports" << endl;
            cout << " 7. Count countries reachable in n flights" << endl;
            cout << " 9. Go to previous menu" << endl;
            cout << "Type option:";
            cin >> input;
            cout << endl;

            if (!(input == "1" || input == "2" || input == "3" || input == "4" || input == "5" || input == "6" || input == "7" || input == "9"))
                cout <<  "Option " << input << " doesn't exist. Try again." << endl;
        } while(!(input == "1" || input == "2" || input == "3" || input == "4" || input == "5" || input == "6" || input == "7" || input == "9"));

        if (input == "1") {
            cout << "Type airport name: ";
            string name1, name2;
            cin >> name1;
            getline(cin, name2);
            cout << endl;
            string name = name1 + name2;
            printAirport(manager, name, "name");
        }
        else if (input == "2") {
            cout << "Type airport code: ";
            string code;
            cin >> code;
            cout << endl;
            printAirport(manager, code, "code");
        }
        else if (input == "3") {
            double latitude, longitude;
            cout << "Type airport's coordinates:" << endl;
            cout << "Latitude:";
            cin >> latitude;
            cout << "Longitude:";
            cin >> longitude;
            Coordinates coord = Coordinates(latitude, longitude);
            cout << "Type maximum distance to coordinates:";
            int distance;
            cin >> distance;
            cout << endl;
            printAirportFromCoordinates(manager, coord, distance);
        }
        else if (input == "4") {
            cout << "Type country name: ";
            string country1, country2;
            cin >> country1;
            getline(cin, country2);
            cout << endl;
            string country = country1 + country2;
            printAirportsInCountry(manager, country);
        }
        else if (input == "5") {
            cout << "Type city name: ";
            string city1, city2;
            cin >> city1;
            getline(cin, city2);
            cout << endl;
            string city = city1 + city2;
            printAirportsInCity(manager, city);
        }
        else if (input == "6")
            printAllAirports(manager);
        else if (input == "7") {
            cout << "Type airport code:";
            string code;
            int n;
            cin >> code;
            cout << "How many flights:";
            cin >> n;
            cout << endl;
            printNumCountriesReachableInNFlights(manager, code, n);
        }
        else if (input == "9")
            return;
    }
}

void flightMenu(Manager manager) {
    while (true) {
        string input;
        do {
            cout << "___________________________________________________________________" << endl;
            cout << "Select one of the following options: " << endl;
            cout << " 1. Show routes between two airports with fewest connecting flights" << endl;
            cout << " 2. Show routes between multiple with fewest connecting flights" << endl;
            cout << " 3. Same as 1 but excluding certain airlines" << endl;
            cout << " 4. Same as 1 but only using certain airlines" << endl;
            cout << " 9. Go to previous menu" << endl;
            cout << "Type option:";
            cin >> input;
            cout << endl;

            if (!(input == "1" || input == "2" || input == "3" || input == "4" || input == "9"))
                cout <<  "Option " << input << " doesn't exist. Try again." << endl;
        } while(!(input == "1" || input == "2" || input == "3" || input == "4" || input == "9"));

        if (input == "1") {
            string src, target;
            cout << "Type airport code of source airport:";
            cin >> src;
            cout << "Type airport code of target airport:";
            cin >> target;
            cout << endl;
            vector<string> vec1, vec2;
            vec1.push_back(src);
            vec2.push_back(target);
            printBestRoute(manager, vec1, vec2);
        }
        else if (input == "2") {
            vector<string> vec1, vec2;
            string src;
            while (true) {
                cout << "Type source airport or type 9 to break loop:";
                cin >> src;
                cout << endl;
                if (src == "9")
                    break;
                else
                    vec1.push_back(src);
            }

            string target;
            while (true) {
                cout << "Type target airport or type 9 to break loop:";
                cin >> target;
                cout << endl;
                if (target == "9")
                    break;
                else
                    vec2.push_back(target);
            }

            printBestRoute(manager, vec1, vec2);
        }
        else if (input == "3") {
            string src, target;
            cout << "Type airport code of source airport:";
            cin >> src;
            cout << "Type airport code of target airport:";
            cin >> target;
            cout << endl;

            string code;
            set<string> blackListAirlines;
            while (true) {
                cout << "Type airline code or type 9 to break loop:";
                cin >> code;
                cout << endl;
                if (code == "9")
                    break;
                else
                    blackListAirlines.insert(code);
            }

            printBestRouteWithBlacklist(manager, src, target, blackListAirlines);
        }
        else if (input == "4") {
            string src, target;
            cout << "Type airport code of source airport:";
            cin >> src;
            cout << "Type airport code of target airport:";
            cin >> target;
            cout << endl;

            string code;
            set<string> greenListAirlines;
            while (true) {
                cout << "Type airline code or type 9 to break loop:";
                cin >> code;
                cout << endl;
                if (code == "9")
                    break;
                else
                    greenListAirlines.insert(code);
            }

            printBestRouteWithGreenlist(manager, src, target, greenListAirlines);
        }
        else if (input == "9")
            return;
    }
}

void numFlightMenu(Manager manager) {
    while (true) {
        string input;
        do {
            cout << "_______________________________________________" << endl;
            cout << "Select one of the following options: " << endl;
            cout << "Get number of:" << endl;
            cout << " 1. flights to airport" << endl;
            cout << " 2. flights from airport" << endl;
            cout << " 3. different airlines flying to airport" << endl;
            cout << " 4. different airlines flying from airport" << endl;
            cout << " 5. different countries with flights to airport" << endl;
            cout << " 6. different countries with flights to airport" << endl;
            cout << " 9. Go to previous menu" << endl;
            cout << "Type option:";
            cin >> input;
            cout << endl;

            if (!(input == "1" || input == "2" || input == "3" || input == "4" || input == "5" || input == "6" || input == "9"))
                cout <<  "Option " << input << " doesn't exist. Try again." << endl;
        } while(!(input == "1" || input == "2" || input == "3" || input == "4" || input == "5" || input == "6" || input == "9"));

        if (input == "1" || input == "2" || input == "3" || input == "4" || input == "5" || input == "6") {
            string code;
            cout << "Type airport code: ";
            cin >> code;
            cout << endl;
            printNumFlights(manager, code, input);
        }
        else if (input == "9")
            return;
    }
}

void printAirline(vector<Airline> airlines, string string1, const string& mode) {
    for(auto it = airlines.begin(); it != airlines.end(); it++) {
        string val;
        if (mode == "name")
            val = it->getName();
        else if (mode == "code")
            val = it->getCode();
        else if (mode == "callsign")
            val = it->getCallSign();

        if (val == string1) {
            cout << "_____________________________________________________________________\n";
            cout << left << setw(35) << "Name" << setw(30) << "Call sign" << setw(20) << "Country" << endl;
            cout << "_____________________________________________________________________\n";
            cout << left << setw(35) << it->getName() << setw(30) << it->getCallSign() << setw(20) << it->getCountry() << endl;
            cout << endl;
            return;
        }
    }
    cout <<"Airliner not found!" << endl;
    cout << endl;
}

void printAllAirlines(Manager manager) {
    auto airlines = manager.getAirlines();

    cout << "__________________________________________________________________________\n";
    cout << left << setw(35) << "Name" << setw(30) << "Call sign" << setw(20) << "Country" << endl;
    cout << "__________________________________________________________________________\n";

    for(auto itr : airlines) {
        Airline it = itr.second;
        cout << left << setw(35) << it.getCountry() << setw(30) << it.getCallSign() << setw(20) << it.getCountry() << endl;
    }
    cout << endl;
}

void printAirlinesInCountry(vector<Airline> airlines, string country){

    cout << "__________________________________________________________________________\n";
    cout << left << setw(35) << "Name" << setw(30) << "Call sign" << setw(20) << "Country" << endl;
    cout << "__________________________________________________________________________\n";

    for (auto it = airlines.begin(); it != airlines.end(); it++){
        if (it->getCountry() == country){
            cout << left << setw(35) << it->getName() << setw(30) << it->getCallSign() << setw(20) << it->getCountry() << endl;
        }
    }

    cout << endl;
}

void printAllAirports(Manager manager){
    auto airports = manager.getAirports();
    cout << "_____________________Name________________________________City__________________________Country_________________________\n";
    for(auto itr : airports){
        Airport it= itr.second;
        cout<<"|";
        cout<<setw(47);
        cout<<it.getName();
        cout<<"|";
        cout<<setw(30);
        cout<<it.getCity();
        cout<<"|";
        cout<<setw(38);
        cout<< it.getCountry();
        cout <<"|";
        cout<<"\n";
    }
    cout << "______________________________________________________________________________________________________________________\n";
    cout <<"Print com sucesso 100%. Retornando ao menu principal...\n";
}

void printAirport(Manager manager, string val, const string& mode) {
    auto airports = manager.getAirports();
    for (auto itr : airports) {
        Airport airport = itr.second;
        bool flag = false;
        if (mode == "name" && airport.getName() == val)
            flag = true;
        else if (mode == "code" && airport.getCode() == val)
            flag = true;

        if (flag) {
            cout << "___________________________________________________________________________________" << endl;
            cout << left << setw(8) << "Code" << setw(35) << "Name" << setw(30) << "City" << setw(30) << "Country" << endl;
            cout << "___________________________________________________________________________________" << endl;
            cout << left << setw(8) << airport.getCode() << setw(35) << airport.getName() << setw(30) << airport.getCity() << setw(30) << airport.getCountry() << endl;
            cout << endl;
            return;
        }
    }

    cout << "No airport meeting conditions was found" << endl;
    cout << endl;
}

void printAirportsInCity(Manager manager, string city) {
    auto airports = manager.FindAirportsFromCity(city);
    unordered_map <string,Airport> airports1 = manager.getAirports();

    cout << "___________________________________________________________________________________" << endl;
    cout << left << setw(8) << "Code" << setw(35) << "Name" << setw(30) << "City" << setw(30) << "Country" << endl;
    cout << "___________________________________________________________________________________" << endl;

    for(string code : airports){
        Airport airport = airports1[code];
        cout << left << setw(8) << airport.getCode() << setw(35) << airport.getName() << setw(30) << airport.getCity() << setw(30) << airport.getCountry() << endl;
    }
    cout << endl;
}

void printAirportsInCountry(Manager manager, string country) {
    auto airports = manager.FindAirportsFromCountry(country);
    unordered_map <string,Airport> airports1 = manager.getAirports();

    cout << "___________________________________________________________________________________" << endl;
    cout << left << setw(8) << "Code" << setw(35) << "Name" << setw(30) << "City" << setw(30) << "Country" << endl;
    cout << "___________________________________________________________________________________" << endl;

    for(string code : airports){
        Airport airport = airports1[code];
        cout << left << setw(8) << airport.getCode() << setw(35) << airport.getName() << setw(30) << airport.getCity() << setw(30) << airport.getCountry() << endl;
    }
    cout << endl;
}

void printAirportFromCoordinates(Manager manager, Coordinates coordinates, int maxDistance) {
    vector<string> airportCodes = manager.FindAirportsFromCoordinates(coordinates, maxDistance);
    unordered_map <string, Airport> airports = manager.getAirports();

    cout << "Airports within " << maxDistance << "km of (" << coordinates.getLatitude() << ", " << coordinates.getLongitude() << "):" << endl;
    cout << "___________________________________________________________________________________" << endl;
    cout << left << setw(8) << "Code" << setw(35) << "Name" << setw(30) << "City" << setw(30) << "Country" << endl;
    cout << "___________________________________________________________________________________" << endl;
    for (string code : airportCodes) {
        Airport airport = airports[code];
        cout << left << setw(8) << airport.getCode() << setw(35) << airport.getName() << setw(30) << airport.getCity() << setw(30) << airport.getCountry() << endl;
    }
    cout << endl;
}

void printNumFlights(Manager manager, string code, string mode) {
    if (mode == "1") {
        int res = manager.getNumFlightTo(code);
        cout << "_____________________________" << endl;
        cout << "There are " << res << " flights to " << code << "." << endl << endl;
    }
    else if (mode == "2") {
        int res = manager.getNumFlightFrom(code);
        cout << "_______________________________" << endl;
        cout << "There are " << res << " flights from " << code << "." << endl << endl;
    }
    else if (mode == "3") {
        int res = manager.getNumFlightFromDifferentAirlinesTo(code);
        cout << "__________________________________________" << endl;
        cout << "There are " << res << " airlines with flights to " << code << "." << endl << endl;
    }
    else if (mode == "4") {
        int res = manager.getNumFlightFromDifferentAirlinesFrom(code);
        cout << "____________________________________________" << endl;
        cout << "There are " << res << " airlines with flights from " << code << "." << endl << endl;
    }
    else if (mode == "5") {
        int res = manager.getNumFlightFromDifferentCountriesTo(code);
        cout << "_____________________________________________________" << endl;
        cout << "There are " << res << " flights from different countries to " << code << "." << endl << endl;
    }
    else if (mode == "6") {
        int res = manager.getNumFlightToDifferentCountriesFrom(code);
        cout << "_____________________________________________________" << endl;
        cout << "There are " << res << " flights to different countries from " << code << "." << endl << endl;
    }
}

void printBestRoute(Manager manager, vector<string> sources, vector<string> targets) {
    vector<vector<Flight>> routes =  manager.FindBestRoutesFromAirportsToAirports(sources, targets);
    unordered_map<string, Airport> airports = manager.getAirports();

    if (routes.empty()) {
        cout << "___________________" << endl;
        cout << "No available routes" << endl;
        return;
    }

    cout << "Flight with fewest connecting flights from source airports to target airports:" << endl;
    cout << "_______________________________________________________________________________________" << endl;
    cout << left << setw(40) << "Source airport" << setw(40) << "Target airport" << setw(20) << "Airline" << endl;
    cout << "_______________________________________________________________________________________" << endl;
    for (vector<Flight> route : routes)
        for (Flight flight : route)
            cout << left << setw(40) << airports[flight.getSource()].getName() << setw(40) << airports[flight.getTarget()].getName() << setw(20) << flight.getAirline() << endl;

    cout << endl;
}

void printBestRouteWithBlacklist(Manager manager, string source, string target, set<string> blackListAirlines) {
    vector<Flight> route =  manager.FindBestRouteWithBlackListed(source, target, blackListAirlines);
    unordered_map<string, Airport> airports = manager.getAirports();

    if (route.empty()) {
        cout << "_____________________________________________________" << endl;
        cout << "No available route without using blacklisted airlines" << endl;
        return;
    }

    cout << "Flight with fewest connecting flights from " << source << " to " << target << ":" << endl;
    cout << "_______________________________________________________________________________________" << endl;
    cout << left << setw(40) << "Source airport" << setw(40) << "Target airport" << setw(20) << "Airline" << endl;
    cout << "_______________________________________________________________________________________" << endl;
    for (Flight flight : route)
        cout << left << setw(40) << airports[flight.getSource()].getName() << setw(40) << airports[flight.getTarget()].getName() << setw(20) << flight.getAirline() << endl;

    cout << endl;
}

void printBestRouteWithGreenlist(Manager manager, string source, string target, set<string> greenListAirlines) {
    vector<Flight> route =  manager.FindBestRouteWithGreenListed(source, target, greenListAirlines);
    unordered_map<string, Airport> airports = manager.getAirports();

    if (route.empty()) {
        cout << "__________________________________________________" << endl;
        cout << "No available route using only greenlisted airlines" << endl;
        return;
    }

    cout << "Flight with fewest connecting flights from " << source << " to " << target << ":" << endl;
    cout << "_______________________________________________________________________________________" << endl;
    cout << left << setw(40) << "Source airport" << setw(40) << "Target airport" << setw(20) << "Airline" << endl;
    cout << "_______________________________________________________________________________________" << endl;
    for (Flight flight : route)
        cout << left << setw(40) << airports[flight.getSource()].getName() << setw(40) << airports[flight.getTarget()].getName() << setw(20) << flight.getAirline() << endl;

    cout << endl;
}

void printNumCountriesReachableInNFlights(Manager manager, string src, int n) {
    unordered_map<string, Airport> airports = manager.getAirports();

    int num = manager.CountCountriesReachableInNFlights(src, n);
    cout << "____________________________________________________________________" << endl;
    cout << num << " countries are reachable from " << airports[src].getName() << " in " << n << " flights." << endl;
}