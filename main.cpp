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

void flightMenu(Manager manager);
void printBestFlights(Manager manager);

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
            cout << " 4. Show all names in country" << endl;
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

void airportMenu(Manager manager) { //TODO
    while (true) {
        string input;
        do {
            cout << "____________________________________" << endl;
            cout << "Select one of the following options: " << endl;
            cout << " 1. Search airport by name" << endl;
            cout << " 2. Search airport by code" << endl;
            cout << " 3. Search airports by coordinates" << endl;
            cout << " 4. Show airport(s) in country" << endl;
            cout << " 5. Show airport(s) in city" << endl;
            cout << " 6. Show all airports" << endl;
            cout << " 9. Go to previous menu" << endl;
            cout << "Type option:";
            cin >> input;
            cout << endl;

            if (!(input == "1" || input == "2" || input == "3" || input == "4" || input == "5" || input == "6" || input == "9"))
                cout <<  "Option " << input << " doesn't exist. Try again." << endl;
        } while(!(input == "1" || input == "2" || input == "3" || input == "4" || input == "5" || input == "6" || input == "9"));

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
        else if (input == "3"){
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
        else if (input == "9")
            return;
    }
}

void flightMenu(Manager manager) { //TODO
    while (true) {
        string input;
        do {
            cout << "____________________________________________________________________" << endl;
            cout << "Select one of the following options: " << endl;
            cout << " 1. Show flights between two airports with fewest connecting flights" << endl;
            cout << " 2. Show flights between two locations" << endl;
            cout << " 9. Go to previous menu" << endl;
            cout << "Type option:";
            cin >> input;
            cout << endl;

            if (!(input == "1" || input == "2" || input == "9"))
                cout <<  "Option " << input << " doesn't exist. Try again." << endl;
        } while(!(input == "1" || input == "2" || input == "9"));

        if (input == "1")
            printBestFlights(manager);
        else if (input == "2") {
            //TODO
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
            cout << "_____________________Name________________________________Callsign__________________________Country______________\n";
            cout<<"|";
            cout<<setw(41);
            cout<<it->getName();
            cout<<"|";
            cout<<setw(30);
            cout<<it->getCallSign();
            cout<<"|";
            cout<<setw(38);
            cout<< it->getCountry();
            cout <<"|";
            cout<<"\n";
            cout << "_________________________________________________________________________________________________________________\n";
            cout <<"Print com sucesso 100%. Retornando ao menu principal...\n";
            return;
        }
    }
    cout<<"Airliner not found!\n ";
}

void printAllAirlines(Manager manager) {
    cout << "_____________________Name________________________________Callsign__________________________Country______________\n";
    auto tmp = manager.getAirlines();
    for(auto itr : tmp){
        Airline it = itr.second;
        cout<<"|";
        cout<<setw(41);
        cout<<it.getName();
        cout<<"|";
        cout<<setw(30);
        cout<<it.getCallSign();
        cout<<"|";
        cout<<setw(38);
        cout<< it.getCountry();
        cout <<"|";
        cout<<"\n";
        //se meter o getCode aqui dá um erro de badalloc (erro type 3) por nos problemas
    }
    cout << "_________________________________________________________________________________________________________________\n";
    cout <<"Print com sucesso 100%. Retornando ao menu principal...\n";
}

void printAirlinesInCountry(vector<Airline> airlines, string country){
    cout << "_____________________Name________________________________Callsign__________________________Country______________\n";
    for(auto it=airlines.begin(); it != airlines.end(); it++){
        if(it->getCountry()==country){
            cout<<"|";
            cout<<setw(41);
            cout<<it->getName();
            cout<<"|";
            cout<<setw(30);
            cout<<it->getCallSign();
            cout<<"|";
            cout<<setw(38);
            cout<< it->getCountry();
            cout <<"|";
            cout<<"\n";
        }
    }
    cout << "_________________________________________________________________________________________________________________\n";
    cout <<"Print com sucesso 100%. Retornando ao menu principal...\n";
    return;
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
    cout << "_____________________Name________________________________City__________________________Country_________________________\n";
    for (auto itr : airports) {
        Airport airport = itr.second;
        bool flag = false;
        if (mode == "name" && airport.getName() == val)
            flag = true;
        else if (mode == "code" && airport.getCode() == val)
            flag = true;

        if (flag) {
            cout<<"|";
            cout<<setw(47);
            cout << airport.getName();
            cout<<"|";
            cout<<setw(30);
            cout << airport.getCity();
            cout<<"|";
            cout<<setw(38);
            cout << airport.getCountry();
            cout <<"|";
            cout<<"\n";
            break;
        }
    }
    cout << "______________________________________________________________________________________________________________________\n";
    cout <<"Print com sucesso 100%. Retornando ao menu principal...\n";
}

void printBestFlights(Manager manager) {
    cout<<"Introduza o Code do Aeroporto de Ida:\n";
    string ida;
    string chegada;
    cin>>ida;
    cout<<"Introduza o Code do Aeroporto de Chegada:\n";
    cin>>chegada;
    vector<vector<Flight>> result = manager.FindBestRoutes1(ida,chegada);
    int i = 1;
    for(vector<Flight> route : result){
        cout<< "Route "<<i<<".\n";
        i++;
        for(Flight flight : route) {
            string start = manager.getAirportWithCode( flight.getSource()).getName() + "("+flight.getSource() + ")";
            string end=">"+ manager.getAirportWithCode( flight.getTarget()).getName() + "("+flight.getTarget() + ")";
            string airline = manager.getAirlineWithCode(flight.getAirline()).getName()+"("+flight.getAirline()+")";
            cout<< setfill('-')<<setw(35)<<left<< start
                << setfill('-')<<setw(40)<<airline
                <<end<<"\n";
        }
        cout<<"\n";
    }
}

void printAirportsInCity(Manager manager, string city) {
    auto airports = manager.FindAirportsFromCity(city);
    cout << "_____________________Name________________________________City__________________________Country_________________________\n";
    for(string airport : airports){
        cout<<"|";
        cout<<setw(47);
        cout<<airport;
        cout<<"|";
        cout<<setw(30);
        cout<<city;
        cout<<"|";
        cout<<"\n";
    }
    cout << "______________________________________________________________________________________________________________________\n";
    cout <<"Print com sucesso 100%. Retornando ao menu principal...\n";
}

void printAirportsInCountry(Manager manager, string country) {
    auto airports = manager.FindAirportsFromCountry(country);
    cout << "_____________________Name________________________________City__________________________Country_________________________\n";
    for(string airport : airports){
        cout<<"|";
        cout<<setw(47);
        cout<<airport;
        cout<<"|";
        cout<<setw(38);
        cout<< country;
        cout <<"|";
        cout<<"\n";
    }
    cout << "______________________________________________________________________________________________________________________\n";
    cout <<"Print com sucesso 100%. Retornando ao menu principal...\n";
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

void printAirportFromCoordinates(Manager manager, Coordinates coordinates, int maxDistance) {
    vector<string> airportCodes = manager.FindAirportsFromCoordinates(coordinates, maxDistance);
    unordered_map <string, Airport> airports = manager.getAirports();

    cout << "Airports within " << maxDistance << "km of (" << coordinates.getLatitude() << ", " << coordinates.getLongitude() << "):" << endl;
    cout << "__________________________________________________________________________" << endl;
    cout << left << setw(7) << "Code" << setw(40) << "Name" << setw(20) << "City" << setw(20) << "Country" << endl;
    cout << "__________________________________________________________________________" << endl;
    for (string code : airportCodes) {
        Airport airport = airports[code];
        cout << left << setw(7) << airport.getCode() << setw(40) << airport.getName() << setw(20) << airport.getCity() << setw(20) << airport.getCountry() << endl;
    }
    cout << endl;
}