//
// Created by Utilizador on 12/28/2022.
//

#ifndef PROJ_FLIGHT_H
#define PROJ_FLIGHT_H
#include "string"

using namespace std;
class Flight {
private:
    string source,target,airline;
    bool used ;
public:
    Flight(string source,string target,string airline);
    string getSource() const;
    string getTarget() const;
    string getAirline() const;
    bool getUsed() const;
    void setUsed(bool use);
    bool operator==(const Flight& flight1) const;
};
#endif //PROJ_FLIGHT_H
