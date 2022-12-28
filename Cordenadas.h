//
// Created by tomas on 12/26/2022.
//

#ifndef PROJ_CORDENADAS_H
#define PROJ_CORDENADAS_H


class Cordenadas {
private:
    double latitude;
    double longitude;
public:
    Cordenadas(double latitude , double longitude);

    Cordenadas();
    double getDistance(Cordenadas cordenadas);
    double getlatitude();
    double getlongitude();
    bool operator==(const Cordenadas& cordenada) const;
};


#endif //PROJ_CORDENADAS_H
