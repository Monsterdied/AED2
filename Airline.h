//
// Created by tomas on 12/27/2022.
//

#ifndef PROJ_AIRLINE_H
#define PROJ_AIRLINE_H
#include <iostream>
using namespace std;
/**
 * @class Airline
 * @brief Represents an airline.
 *
 * The Airline class represents an airline, with its code, name, callsign, and country.
 */
class Airline {
private:
    /**
     * @brief The airline code.
     */
    string code;

    /**
     * @brief The airline name.
     */
    string name;

    /**
     * @brief The airline callsign.
     */
    string callsign;

    /**
     * @brief The country where the airline is based.
     */
    string country;

public:
    /**
     * @brief Constructs a default Airline object.
     */
    Airline();

    /**
     * @brief Constructs an Airline object with the given code, name, callsign, and country.
     *
     * @param code The airline code.
     * @param name The airline name.
     * @param callsign The airline callsign.
     * @param country The country where the airline is based.
     */
    Airline(string code,string name,string callsign,string country);

    /**
     * @brief Returns the airline code.
     \Complexity  0(1)
     * @return The airline code.
     */
    string getCode();

    /**
     * @brief Returns the airline name.
     \Complexity  0(1)
     * @return The airline name.
     */
    string getName();

    /**
     * @brief Returns the airline callsign.
     \Complexity  0(1)
     * @return The airline callsign.
     */
    string getCallSign();

    /**
     * @brief Returns the country where the airline is based.
     \Complexity  0(1)
     * @return The country where the airline is based.
     */
    string getCountry();
};


#endif //PROJ_AIRLINE_H
