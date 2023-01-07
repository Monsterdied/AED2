//
// Created by Utilizador on 12/28/2022.
//

#ifndef PROJ_FLIGHT_H
#define PROJ_FLIGHT_H
#include "string"

using namespace std;
/**
 * @class Flight
 * @brief Represents a flight.
 *
 * The Flight class represents a flight, with its source and target airports, and the airline operating the flight.
 */
class Flight {
private:
    /**
     * @brief The source airport code.
     */
    string source;

    /**
     * @brief The target airport code.
     */
    string target;

    /**
     * @brief The airline code operating the flight.
     */
    string airline;

    /**
     * @brief Indicates whether the flight has been used or not.
     */
    bool used;

public:
    /**
     * @brief Constructs a Flight object with the given source, target, and airline codes.
     *
     * @param source The source airport code.
     * @param target The target airport code.
     * @param airline The airline code operating the flight.
     */
    Flight(string source,string target,string airline);

    /**
     * @brief Returns the source airport code.
     \Complexity  0(1)
     * @return The source airport code.
     */
    string getSource() const;

    /**
     * @brief Returns the target airport code.
     \Complexity  0(1)
     * @return The target airport code.
     */
    string getTarget() const;

    /**
     * @brief Returns the airline code operating the flight.
     \Complexity  0(1)
     * @return The airline code operating the flight.
     */
    string getAirline() const;

    /**
     * @brief Returns whether the flight has been used or not.
     \Complexity  0(1)
     * @return `true` if the flight has been used, `false` otherwise.
     */
    bool getUsed() const;

    /**
     * @brief Sets the used status of the flight.
     \Complexity  0(1)
     * @param use The used status of the flight.
     */
    void setUsed(bool use);

    /**
     * @brief Compares this Flight object with another for equality.
     \Complexity  0(1)
     * @param flight1 The Flight object to compare with.
     * @return `true` if the Flight objects are equal, `false` otherwise.
     */
    bool operator==(const Flight& flight1) const;
};
#endif //PROJ_FLIGHT_H
