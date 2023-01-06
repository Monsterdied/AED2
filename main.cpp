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
void menuAirlines(Manager manager);
void menuPrincipal();
void menu1(Manager manager);
void menuAirlinesEspecifica(Manager manager);
void listagemTotalAirlines(Manager manager);
void listagemAirlineNome(vector<Airline> vetor, string nome);
void listagemAirlineCode(vector<Airline> vetor ,string nome);

void listagemAirlineNome(vector<Airline> vetor ,string nome){
    for(auto it=vetor.begin();it!=vetor.end();it++){
        if(it->getName()==nome){
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
            return;
        }
    }
    cout<<"Airport not found!\n ";
}  //Feito
void listagemAirlineCallsine(vector<Airline> vetor ,string code){
    for(auto it=vetor.begin();it!=vetor.end();it++){
        if(it->getCallSign()==code){
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
            return;
        }
    }
    cout<<"Airport not found!\n ";
}
void listagemAirlineCode(vector<Airline> vetor ,string code){
    for(auto it=vetor.begin();it!=vetor.end();it++){
        if(it->getCode()==code){
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
            return;
        }
    }
    cout<<"Airport not found!\n ";
}  //Feito
void menuAirlinesEspecifica(Manager manager){
    cout << "_________________________________________________________________________________\n";
    cout << "|Escolha uma das opcoes seguintes:                                              |"
         <<    "\n|                                                                               |\n";
    cout <<
         "|1.Procurar pelo Nome                                                           |\n"
         "|2.Procurar pelo Code                                                           |\n"
         "|3.Procurar pelo CallSign                                                       |\n";
    cout << "|_______________________________________________________________________________|\n";
    string input;
    cin>>input;
    vector<Airline> testing;
    for(auto paired : manager.getAirlines()) {
        testing.push_back(paired.second);
    }

    if(input=="1"){
        cout<<"Introduza o nome da Airline:\n";
        string nome;
        string nome1;
        cin>>nome;
        getline(cin,nome1);
        string nomefinal= nome + nome1;
        listagemAirlineNome(testing,nomefinal);
    }  //Feito
    if(input=="2"){
        cout<<"Introduza o codigo do Aeroporto:\n";
        string code;
        cin>>code;
        listagemAirlineCode(testing,code);
    }
    if(input=="3"){
        cout<<"Introduza o Call Sign do Aeroporto:\n";
        string code;
        cin>>code;
        listagemAirlineCallsine(testing,code);
    }

}
void menuAirlines(Manager manager){
    cout << "_________________________________________________________________________________\n";
    cout << "|Neste menu das airlines, poderas escolher uma das funcoes disponiveis em baixo:|"
         << "\n""|                                                                               |\n";
    cout << "|Selecione a opcao desejada:                                                    |\n"
            "|1.Ver uma airline em especifica.                                               |\n"
            "|2.Ver um conjunto de airlines.                                                 |\n"
            "|3.Voltar atras.                                                                |\n";
    cout << "|_______________________________________________________________________________|\n";
    string input;
    cin>>input;
    if(input=="1"){
        menuAirlinesEspecifica(manager);
    }
    if(input=="2"){
        menuAirlinesEspecifica(manager);
    }
}

void listagemTotalAirlines(Manager manager){
    cout << "_____________________Name________________________________Callsign__________________________Country______________\n";
    for(auto itr=manager.getAirlines().begin();itr!=manager.getAirlines().end();itr++){
        Airline it = itr->second;
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
} //Feito
void menu1(Manager manager){
    cout << "____________________________________________________________________\n";
    cout << "|Neste menu, poderas escolher uma das funcoes disponiveis em baixo:|"
         << "\n""|                                                                  |\n";
    cout << "|                                                                  |\n"
            "|1.Ver todos as linhas aereas.                                     |\n"
            "|2.Ver parcialmente todos as linhas aereas.                        |\n"
            "|3.Voltar atras.                                                   |\n";
    cout << "|__________________________________________________________________|\n";
    string input;
    cin>>input;
    if(input=="1"){
        listagemTotalAirlines(manager);
        menuPrincipal();
    }
    if(input=="2"){
        menuAirlines(manager);
        cout <<"Print com sucesso 100%. Retornando ao menu principal...\n";
        menuPrincipal();
    }
    if(input=="3"){
        cout<<"Voltando Atras...\n";
        menuPrincipal();
    }
} //Feito (vai-se adicionando coisas novas com mais funcoes novas)

void menuPrincipal(){
    cout << "_________________________________________________\n";
    cout << "|Welcome to Flight Network System L.EIC GUI     |"
         << "\n""|                                               |\n";
    cout << "|Selecione a opcao desejada:                    |\n"
            "|1.Ver Funcoes disponiveis.                     |\n"
            "|2.Sair do Programa.                            |\n";
    cout << "|_______________________________________________|\n";

}  //Feito

int main() {
    Manager maneger;
    maneger.ReadAirLines();
    maneger.ReadAirports();
    maneger.ReadFlights();

    string ctrl;
    menuPrincipal();
    do {
        string input_principal;
        cin >> input_principal;

        if (input_principal == "1") {
            menu1(maneger);
        } else if (input_principal == "2") {
            cout << "Obrigado por usar o programa!";
            break;
        } else {
            cout << "Input errado, Obrigado por usar o programa!";
            break;
        }
    }while(true);


}
/*
int main() {
    Manager maneger;
    maneger.ReadAirLines();
    maneger.ReadAirports();
    maneger.ReadFlights();
/*
    auto ok = maneger.getGraph();
    for(auto tmp : maneger.getAirports()){
        cout<<tmp.first<<"\n\n";
        for(auto tmp1 : ok.getEdges(tmp.first)){
            cout<<tmp1.sourceCode<<" "<<tmp1.airlineCode<<tmp1.destinationCode<<"\n";
        }
        cout<<"\n\n\n\n\n";
    }*/
    /*
    auto route = maneger.FindBestRoute("OPO", "PEK",maneger.getGraph());
    cout<<route.size();
    for( auto a:route){
        cout<<'\n';
        Graph graph = maneger.getGraph();
        cout<<a.getSource()<<" "<<a.getTarget()<<' '<<a.getAirline()<<" ";

        cout<<"\n";
    }*//*
    auto route = maneger.FindBestRoutes1("OPO", "CIH");
    cout << route.size();
    for (auto route1: route) {
        cout << '\n';
        for (auto a: route1) {

            Graph graph = maneger.getGraph();
            cout << a.getSource() << " " << a.getTarget() << ' ' << a.getAirline() << "    ";

        }

    }
    route = maneger.FindBestRoutes1("OPO", "PEK");
    cout << route.size();
    for (auto route1: route) {
        cout << '\n';
        for (auto a: route1) {

            Graph graph = maneger.getGraph();
            cout << a.getSource() << " " << a.getTarget() << ' ' << a.getAirline() << "    ";

        }
    }*//*
    vector<vector<Flight>> routes;
    vector<Flight> route1;
    vector<Flight> route2;
    route1.push_back(Flight("OPO", "YYZ", "TAP"));
    route1.push_back(Flight("YYZ", "PEK", "CCA"));
    route2.push_back(Flight("OPO", "YYZ", "TAP"));
    route2.push_back(Flight("YYZ", "PEK", "RIP"));
    routes.push_back(route1);
    auto it = find(routes.begin(),routes.end(),route2);
    if(it!=routes.end())cout<<"FUCK\n\n\n";
    cout<<maneger.getNumFlightFrom("OPO")<<" "<<maneger.getNumFlightTo("OPO")<<"\n";
    cout<<"TO DIFERENT :"<<maneger.getNumFlightToDiferentCountrysFrom("YEG")<<"\n";
    cout<<" From diferent :"<<maneger.getNumFlightFromDiferentCountrysTo("YEG")<<"\n";
    cout<<"Test "<<maneger.CountCountriesReachableInNFlights("OPO",2)<<"\n";
    cout<<"Test "<<maneger.CountriesReachableInYFlights("OPO",2).size();*//*
    vector<string> target;
    target.push_back("PEK");
    routes = maneger.FindBestRoutesFromAirportsToAirports(maneger.FindAirportsFromCordenadas(Cordenadas(41.1571867,-8.6362544),300),target);

    for (auto route1: routes) {
        cout << '\n';
        for (auto a: route1) {

            Graph graph = maneger.getGraph();
            cout << a.getSource() << " " << a.getTarget() << ' ' << a.getAirline() << "    ";

        }
    }*//*
    auto routes = maneger.FindBestRoutesFromAirportsToAirports(maneger.FindAirportsFromCordenadas(Cordenadas(41.1571867,-8.6362544),150),maneger.FindAirportsFromCordenadas(Cordenadas(40.0733964,116.5827059),100));

    for (auto route1: routes) {
        cout << '\n';
        for (auto a: route1) {

            cout << a.getSource() << " " << a.getTarget() << ' ' << a.getAirline() << "    ";

        }
    }*//*
    auto tmp = maneger.getCitysInContry("China");
    for(auto i : tmp)cout<<i<<"\n";*//*
    vector<string> start;
    start.push_back("OPO");
    auto routes = maneger.FindBestRoutesFromAirportsToAirports(start,maneger.FindAirportsFromCordenadas(Cordenadas(40.0733964,116.5827059),1000));

    for (auto route1: routes) {
        cout << '\n';
        for (auto a: route1) {

            cout << a.getSource() << " " << a.getTarget() << ' ' << a.getAirline() << "    ";

        }
    }*//*
    auto tmp = maneger.FindAirportsFromCountry("Portugal");
    for(auto i : tmp)cout<<i<<"\n";*//*
    auto tmp = maneger.FindAirportsFromCountry("France");
    cout<<tmp.size();
    for(auto i : tmp)cout<<i<<"\n";*//*
    auto tmp = maneger.FindAirportsFromCountry("Portugal");
    cout<<tmp.size()<<"\n";
    for(auto i : tmp)cout<<i<<"\n";*/
    /*auto tmp = maneger.findArticulationPoints();
    cout<<tmp.size()<<"\n";
    for(auto i : tmp)cout<<i<<"\n";

}*/