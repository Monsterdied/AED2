//
// Created by tomas on 12/26/2022.
//

#ifndef PROJ_AIRPORT_H
#define PROJ_AIRPORT_H


#include "Coordinates.h"
#include <iostream>
using namespace std;
/**
 * @class Airport
 * @brief Represents an airport.
 *
 * The Airport class represents an airport, with its coordinates, name, code, city, and country.
 */
class Airport {
private:
    /**
     * @brief The airport coordinates.
     */
    Coordinates cordenadas;

    /**
     * @brief The airport name.
     */
    string name;

    /**
     * @brief The airport code.
     */
    string code;

    /**
     * @brief The city where the airport is located.
     */
    string city;

    /**
     * @brief The country where the airport is located.
     */
    string country;

public:
    /**
     * @brief Constructs an Airport object with the given coordinates, name, code, city, and country.
     *
     * @param latitude The airport latitude.
     * @param longitude The airport longitude.
     * @param name The airport name.
     * @param code The airport code.
     * @param city The city where the airport is located.
     * @param country The country where the airport is located.
     */
    Airport(double latitude , double longitude , string name , string code , string city , string country );

    /**
     * @brief Constructs a default Airport object.
     */
    Airport();

    /**
     * @brief Returns the airport coordinates.
     \Complexity  0(1)
     * @return The airport coordinates.
     */
    Coordinates getCordenadas();

    /**
     * @brief Returns the airport name.
     \Complexity  0(1)
     * @return The airport name.
     */
    string getName() const;

    /**
     * @brief Returns the airport code.
     \Complexity  0(1)
     * @return The airport code.
     */
    string getCode() const;

    /**
     * @brief Returns the city where the airport is located.
     \Complexity  0(1)
     * @return The city where the airport is located.
     */
    string getCity() const;

    /**
     * @brief Returns the country where the airport is located.
     \Complexity  0(1)
     * @return The country where the airport is located.
     */
    string getCountry() const;

    /**
     * @brief Compares this Airport object with another for equality.
     \Complexity  0(1)
     * @param airport The Airport object to compare with.
     * @return `true` if the Airport objects are equal, `false` otherwise.
     */
    bool operator==(const Airport& airport) const;
};


#endif //PROJ_AIRPORT_H
