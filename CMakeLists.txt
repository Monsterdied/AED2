cmake_minimum_required(VERSION 3.23)
project(Proj)

set(CMAKE_CXX_STANDARD 14)


add_executable(Proj main.cpp Coordinates.cpp Coordinates.h Airport.cpp Airport.h Airline.cpp Airline.h Manager.cpp Manager.h Flight.cpp Flight.h Graph.cpp Graph.h)

