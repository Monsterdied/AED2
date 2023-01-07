#include <iostream>
#include <vector>
#include <fstream>
#include "Cordenadas.h"
#include "Airport.h"
#include "Airline.h"
#include "Manager.h"
#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <fstream>
#include "Cordenadas.h"
#include "Airport.h"
#include "Airline.h"
#include "Manager.h"
#include<bits/stdc++.h>

void mainMenu(Manager &manager);
void menuFlights(Manager manager);
void showBestFlights(Manager manager);

void airportMenu(Manager manager);
void showAirport(Manager manager);
void showAllAirports(Manager manager);

void airlinerMenu(Manager manager);
void printAirlinesInCountry(vector<Airline> vetor, string country);
void showAllAirliners(Manager manager);
void printAirliner(vector<Airline> airlines, string string1, const string& mode);

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
            cout << " 1. Show info about airliners" << endl;
            cout << " 2. Show info about airports" << endl;
            cout << " 3. Flight Menu" << endl;
            cout << " 9. Close program" << endl;
            cout << "Type option:";
            cin >> input;
            cout << endl;

            if (!(input == "1" || input == "2" || input == "9"))
                cout <<  "Option " << input << " doesn't exist. Try again." << endl;
        } while(!(input == "1" || input == "2" || input == "9"));

        if (input == "1")
            airlinerMenu(manager);
        else if (input == "2")
            airportMenu(manager);
        else if (input == "3")
            menuFlights(manager);
        else if (input == "9") {
            cout << "Thank you for using this program!";
            return;
        }
    }
}  //Feito

void airlinerMenu(Manager manager) {
    while (true) {
        string input;
        do {
            cout << "__________________________________________" << endl;
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

        vector<Airline> testing;
        for(auto paired : manager.getAirlines()) {
            testing.push_back(paired.second);
        }

        if (input == "1") {
            cout << "Type airline name: ";
            string name1, name2;
            cin >> name1;
            getline(cin, name2);
            cout << endl;
            string name = name1 + name2;
            printAirliner(testing, name, "name");
        }  //Feito
        else if (input == "2"){
            cout << "Type airline code: ";
            string code;
            cin >> code;
            cout << endl;
            printAirliner(testing, code, "code");
        }
        else if (input == "3"){
            cout << "Type airline country sign: ";
            string callSign1, callSign2;
            cin >> callSign1;
            getline(cin, callSign2);
            cout << endl;
            string callSign = callSign1 + callSign2;
            printAirliner(testing, callSign, "callsign");
        }
        else if (input == "4"){
            cout << "Type country name: ";
            string country1, country2;
            cin >> country1;
            getline(cin, country2);
            cout << endl;
            string country = country1 + country2;
            printAirlinesInCountry(testing, country);
        }
        else if (input == "5")
            showAllAirliners(manager);
        else if (input == "9")
            return;
    }
}

void airportMenu(Manager manager) { //TODO
    while (true) {
        string input;
        do {
            cout << "__________________________________________" << endl;
            cout << "Select one of the following options: " << endl;
            cout << " 1. Show all airports" << endl;
            cout << " 2. Search airports in city" << endl;
            cout << " 3. Search airports in country" << endl;
            cout << " 4. Search airports by coordinates" << endl;
            cout << " 9. Go to previous menu" << endl;
            cout << "Type option:";
            cin >> input;
            cout << endl;

            if (!(input == "1" || input == "2" || input == "9"))
                cout <<  "Option " << input << " doesn't exist. Try again." << endl;
        } while(!(input == "1" || input == "2" || input == "9"));

        if (input == "1")
            showAllAirports(manager);
        else if (input == "9")
            mainMenu(manager);


        cout << "_________________________________________________________________________________\n";
        cout << "|Neste menu dos aeroportos, poderas escolher uma funcao em baixo:               |"
             << "\n""|                                                                               |\n";
        cout << "|                                                                               |\n"
                "|1.Ver um aeroporto em especifico.                                              |\n"
                "|2.Ver um conjunto de aeroportos.                                               |\n"
                "|3.Voltar atras.                                                                |\n";
        cout << "|_______________________________________________________________________________|\n";

        if(input=="1") {
            //showAirport(manager);
        }
        if (input=="9")
            return;
    }
}

void menuFlights(Manager manager) {
    while (true) {
        string input;
        do {
            cout << "__________________________________________" << endl;
            cout << "Welcome to Flight Network System L.EIC GUI" << endl;
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
            showBestFlights(manager);
        else if (input == "2") {
            //TODO
        }
        else if (input == "9")
            mainMenu(manager);
    }
}

void printAirliner(vector<Airline> airlines, string string1, const string& mode) {
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

void showAllAirliners(Manager manager) {
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

void printAirlinesInCountry(vector<Airline> vetor, string country){
    cout << "_____________________Name________________________________Callsign__________________________Country______________\n";
    for(auto it=vetor.begin();it!=vetor.end();it++){
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

void listagemAirportNome(vector<Airport> a,string nome){
    for(auto it=a.begin();it!=a.end();it++){
        if(it->getName()==nome){
            cout << "_____________________Name________________________________City__________________________Country_________________________\n";
            cout<<"|";
            cout<<setw(47);
            cout<<it->getName();
            cout<<"|";
            cout<<setw(30);
            cout<<it->getCity();
            cout<<"|";
            cout<<setw(38);
            cout<< it->getCountry();
            cout <<"|";
            cout<<"\n";
            cout << "______________________________________________________________________________________________________________________\n";
            cout <<"Print com sucesso 100%. Retornando ao menu principal...\n";
            return;
        }
    }
    cout<<"Airport not found!\n ";
}

void showAllAirports(Manager manager){
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

void showBestFlights(Manager manager){
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