/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 7 Part 1
// Name: Hau Hin Lai
// Student ID: 118795228
// Email: hlai23@myseneca.ca
// Section: ZAA
// Date of completion: 16 July 2023

   I have done all the coding by myself and only copied the code that my professor
   provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef TRUCK_H
#define TRUCK_H

#include "MotorVehicle.h"

namespace sdds {

    class Truck : public MotorVehicle {
        double m_loadCapacity;
        double m_currentLoad;
    public:
        Truck(const char* licenseNo, int yearBuilt, double loadCapacity, const char* address);
        bool addCargo(double cargo);
        bool unloadCargo();
        std::ostream& write(std::ostream& os);
        std::istream& read(std::istream& is);
        friend std::ostream& operator<<(std::ostream& os, Truck& other);
        friend std::istream& operator>>(std::istream& is, Truck& other);
    };

}

#endif //!TRUCK_H
