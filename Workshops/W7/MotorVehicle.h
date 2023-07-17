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

#ifndef MOTORVEHICLE_H
#define MOTORVEHICLE_H

#include <iostream>

namespace sdds {

    class MotorVehicle {
        char m_licenseNo[9]{};
        char m_address[64]{};
        int m_yearBuilt;
    public:
        MotorVehicle(const char* licenseNo, int yearBuilt);
        void moveTo(const char* address);
        virtual std::ostream& write(std::ostream& os) const;      //virtual therefore latest method will be called
        virtual std::istream& read(std::istream& is);       //virtual therefore latest method will be called
        friend std::ostream& operator<<(std::ostream& os, const MotorVehicle& other);
        friend std::istream& operator>>(std::istream& is, MotorVehicle& other);
    };

}

#endif //!MOTORVEHICLE_H
