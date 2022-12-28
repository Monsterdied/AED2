//
// Created by tomas on 12/26/2022.
//

#include <cmath>
#include "Cordenadas.h"
Cordenadas::Cordenadas(double latitude , double longitude){
    this->latitude = latitude;
    this->longitude = longitude;
}
double Cordenadas::getlatitude(){
    return latitude;
}
double Cordenadas::getlongitude(){
    return longitude;
}

Cordenadas::Cordenadas() {
    latitude = 0;
    longitude=0;
}
double Cordenadas::getDistance(Cordenadas cordenadas ){
    double lat1 = this->latitude;
    double lat2 = cordenadas.latitude;
    double lon1 = this->longitude;
    double lon2 = cordenadas.longitude;

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
bool Cordenadas::operator==(const Cordenadas& cordenada) const
{
    if (this->latitude == cordenada.latitude && this->longitude == cordenada.longitude) return true;
    else return false;
}
