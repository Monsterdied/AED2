//
// Created by Utilizador on 12/28/2022.
//

#include "Flight.h"

Flight::Flight(string source, string target, string airline) {
    this->source=source;
    this->target=target;
    this->airline=airline;
    this->used = false;
}
bool Flight::getUsed() const{
    return used;
}
void Flight::setUsed(bool us){
    used = us;
}
string Flight::getSource() const{
    return this->source;
}
string Flight::getTarget() const{
    return this->target;
}
string Flight::getAirline() const{
    return this->airline;
}
bool Flight::operator==(const Flight& flight1) const{
    if(source == flight1.source && target == flight1.target && airline == flight1.airline)
        return true;
    return false;
}