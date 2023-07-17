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

#include "Truck.h"

namespace sdds {
    Truck::Truck(const char* licenseNo, int yearBuilt, double loadCapacity, const char* address) : MotorVehicle(licenseNo, yearBuilt) {     //calling base class constructor
        m_loadCapacity = loadCapacity;
        m_currentLoad = 0.0;
        moveTo(address);
    }

    bool Truck::addCargo(double cargo) {
        if(m_currentLoad == m_loadCapacity) {                   //if full load, then no change in loading, return false
            return false;
        } else if(m_currentLoad + cargo <= m_loadCapacity) {    //if no exceeding capacity after adding cargo, return true
            m_currentLoad += cargo;
            return true;
        } else {
            m_currentLoad = m_loadCapacity;                     //if exceeds capacity after adding cargo, set current load to capacity (full load), return true
            return true;
        }
    }

    bool Truck::unloadCargo() {
        if(m_currentLoad > 0.0) {
            m_currentLoad = 0.0;
            return true;
        }
        return false;
    }

    std::ostream& Truck::write(std::ostream& os) {
        MotorVehicle::write(os);
        os << " | " << m_currentLoad << "/" << m_loadCapacity;
        return os;
    }

    std::istream& Truck::read(std::istream& is) {
        MotorVehicle::read(is);
        std::cout << "Capacity: ";
        is >> m_loadCapacity;
        std::cout << "Cargo: ";
        is >> m_currentLoad;
        return is;
    }

    std::ostream& operator<<(std::ostream& os, Truck& other) {
        return other.Truck::write(os);
    }

    std::istream& operator>>(std::istream& is, Truck& other) {
        return other.Truck::read(is);
    }
}