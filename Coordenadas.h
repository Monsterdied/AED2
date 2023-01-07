//
// Created by tomas on 12/26/2022.
//

#ifndef PROJ_COORDENADAS_H
#define PROJ_COORDENADAS_H


/**
 * @class Coordenadas
 * @brief Represents a set of coordinates.
 *
 * The Coordenadas class represents a set of coordinates, with a latitude and longitude.
 */
class Coordenadas {
private:
    /**
     * @brief The latitude.
     */
    double latitude;

    /**
     * @brief The longitude.
     */
    double longitude;

public:
    /**
     * @brief Constructs a Coordenadas object with the given latitude and longitude.
     *
     * @param latitude The latitude.
     * @param longitude The longitude.
     */
    Coordenadas(double latitude , double longitude);

    /**
     * @brief Constructs a default Coordenadas object.
     \Complexity  0(1)
     */
    Coordenadas();

    /**
     * @brief Calculates the distance between this Coordenadas object and another.
     \Complexity  0(1)
     * @param coordenadas The Coordenadas object to calculate the distance to.
     * @return The distance between the Coordenadas objects.
     */
    double getDistance(Coordenadas coordenadas);

    /**
     * @brief Returns the latitude.
     \Complexity  0(1)
     * @return The latitude.
     */
    double getlatitude();

    /**
     * @brief Returns the longitude.
     \Complexity  0(1)
     * @return The longitude.
     */
    double getlongitude();

    /**
     * @brief Compares this Coordenadas object with another for equality.
     \Complexity  0(1)
     * @param cordenada The Coordenadas object to compare with.
     * @return `true` if the Coordenadas objects are equal, `false` otherwise.
     */
    bool operator==(const Coordenadas& cordenada) const;
};


#endif //PROJ_COORDENADAS_H
