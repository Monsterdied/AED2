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
void listagemAirlineNome(Manager manager, string nome);

void listagemAirlineNome(Manager manager ,string nome){
    for(auto it=manager.getAirlines().begin()++;it!=manager.getAirlines().end();it++){
        if(it->getName()==nome){
            cout<<"\n\nName:" + it->getName();
            cout<<"\nCountry:" + it->getCountry() + "\n\n";
            return;
        }
    }
    cout<<"Airport not found!\n ";
}  //Feito
void menuAirlinesEspecifica(Manager manager){
    cout << "_________________________________________________________________________________\n";
    cout << "|Escolha uma das opcoes seguintes:                                              |"
    << "\n"" |                                                                               |\n";
    cout <<
            "|1.Procurar pelo Nome                                                           |\n"
            "|2.Procurar pelo Code                                                           |\n"
            "|3.Procurar pelo CallSign                                                       |\n";
    cout << "|_______________________________________________________________________________|\n";
    string input;
    cin>>input;
    if(input=="1"){
        cout<<"Introduza o nome da Airline:\n";
        string nome;
        string nome1;
        cin>>nome;
        getline(cin,nome1);
        string nomefinal= nome + nome1;
        listagemAirlineNome(manager,nomefinal);
    }  //Feito
    if(input=="2"){
        cout<<"Introduza o codigo do Aeroporto:\n";
        string nome;
        cin>>nome;

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
}


void menuPrincipal(){
    cout << "_________________________________________________\n";
    cout << "|Welcome to Flight Network System L.EIC GUI     |"
     << "\n""|                                               |\n";
    cout << "|Selecione a opcao desejada:                    |\n"
            "|1.Ver Funcoes disponiveis.                     |\n"
            "|2.Sair do Programa.                            |\n";
    cout << "|_______________________________________________|\n";

}  //Feito


void listagemTotalAirlines(Manager manager){
    cout << "_____________________Name________________________________Callsign__________________________Country______________\n";
    for(auto it=manager.getAirlines().begin();it!=manager.getAirlines().end();it++){
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
        //se meter o getCode aqui dá um erro de badalloc (erro type 3) por nos problemas
    }
    cout << "_________________________________________________________________________________________________________________\n";
    cout <<"Print com sucesso 100%. Retornando ao menu principal...\n";
}
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
            cout << "Obrigado por usar o programa!";
            break;
        }
    }while(true);

}