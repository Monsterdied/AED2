//
// Created by tomas on 12/26/2022.
//

#ifndef PROJ_COORDINATES_H
#define PROJ_COORDINATES_H


class Coordinates {
private:
    double latitude;
    double longitude;
public:
    Coordinates(double latitude, double longitude);
    Coordinates();
    double getDistance(Coordinates coordinates);
    double getLatitude();
    double getLongitude();
    bool operator==(const Coordinates& coordinates) const;
};


#endif //PROJ_COORDINATES_H
