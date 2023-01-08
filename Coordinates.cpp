//
// Created by tomas on 12/26/2022.
//

#include <cmath>
#include "Coordinates.h"
Coordinates::Coordinates(double latitude , double longitude){
    this->latitude = latitude;
    this->longitude = longitude;
}
double Coordinates::getLatitude(){
    return latitude;
}
double Coordinates::getLongitude(){
    return longitude;
}

Coordinates::Coordinates() {
    latitude = 0;
    longitude=0;
}

double Coordinates::getDistance(Coordinates coordinates ){
    double lat1 = this->latitude;
    double lat2 = coordinates.latitude;
    double lon1 = this->longitude;
    double lon2 = coordinates.longitude;

    double dLat = (lat2 - lat1) *
                  M_PI / 180.0;
    double dLon = (lon2 - lon1) *
                  M_PI / 180.0;

    // convert to radians
    lat1 = (lat1) * M_PI / 180.0;
    lat2 = (lat2) * M_PI / 180.0;

    // apply formulae
    double a = pow(sin(dLat / 2), 2) +
               pow(sin(dLon / 2), 2) *
               cos(lat1) * cos(lat2);
    double rad = 6371;
    double c = 2 * asin(sqrt(a));
    return rad * c;


}

bool Coordinates::operator==(const Coordinates& coordinates) const
{
    if (this->latitude == coordinates.latitude && this->longitude == coordinates.longitude) return true;
    else return false;
}
