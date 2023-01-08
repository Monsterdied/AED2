//
// Created by tomas on 12/26/2022.
//

#ifndef PROJ_COORDINATES_H
#define PROJ_COORDINATES_H


/**
 * @class Coordinates
 * @brief Represents a set of coordinates.
 *
 * The Coordinates class represents a set of coordinates, with a latitude and longitude.
 */
class Coordinates {
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
     * @brief Constructs a Coordinates object with the given latitude and longitude.
     *
     * @param latitude The latitude.
     * @param longitude The longitude.
     */
    Coordinates(double latitude , double longitude);

    /**
     * @brief Constructs a default Coordinates object.
     \Complexity  0(1)
     */
    Coordinates();

    /**
     * @brief Calculates the distance between this Coordinates object and another.
     \Complexity  0(1)
     * @param coordenadas The Coordinates object to calculate the distance to.
     * @return The distance between the Coordinates objects.
     */
    double getDistance(Coordinates coordenadas);

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
     * @brief Compares this Coordinates object with another for equality.
     \Complexity  0(1)
     * @param cordenada The Coordinates object to compare with.
     * @return `true` if the Coordinates objects are equal, `false` otherwise.
     */
    bool operator==(const Coordinates& cordenada) const;
};


#endif //PROJ_COORDINATES_H
