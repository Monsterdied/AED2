//
// Created by Utilizador on 12/28/2022.
//

#include "Flight.h"

Flight::Flight(string source, string target, string airline) {
    this->source=source;
    this->target=target;
    this->airline=airline;
}

string Flight::getSource() {
    return this->source;
}
string Flight::getTarget() {
    return this->target;
}
string Flight::getAirline() {
    return this->airline;
}
bool Flight::operator==(const Flight& flight1) const{
    if(source == flight1.source && target == flight1.target && airline == flight1.airline)
        return true;
    return false;
}