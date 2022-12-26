//
// Created by tomas on 12/26/2022.
//

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
