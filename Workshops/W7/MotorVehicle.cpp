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

#include "cstring.h"
#include <iomanip>
#include "MotorVehicle.h"

namespace sdds {
    MotorVehicle::MotorVehicle(const char* licenceNo, int yearBuilt) {
        strnCpy(m_licenseNo, licenceNo, 8);     //at most 8 characters for the license, the ninth place in the array will be null terminator
        m_licenseNo[8]='\0';                    //assign null terminator to last place of the C string
        strCpy(m_address, "Factory");           //by default the address will be "Factory"
        m_yearBuilt = yearBuilt;
    }

    void MotorVehicle::moveTo(const char* address) {
        if(strCmp(m_address, address) != 0) {   //if the address is different
            std::cout << "|";                   //format of showing the address and address to-be-changed
            std::cout << std::right;
            std::cout.width(8);
            std::cout << m_licenseNo << "| |";
            std::cout.width(20);
            std::cout << m_address << " ---> ";
            std::cout << std::left;
            std::cout.width(20);
            std::cout << address << "|" << std::endl;
            strCpy(m_address, address);         //update the address after display
            m_address[strLen(address)] = '\0';
        }
    }

    std::ostream& MotorVehicle::write(std::ostream& os) const {
        os << "| " << m_yearBuilt << " | " << m_licenseNo << " | " << m_address;
        return os;
    }

    std::istream& MotorVehicle::read(std::istream& is) {
        std::cout << "Built year: ";
        is >> m_yearBuilt;
        std::cout << "License plate: ";
        is >> m_licenseNo;
        is.ignore();                            //clear input buffer
        std::cout << "Current location: ";
        is.getline(m_address, '\n');            //cin.getline() function reads whitespace as well and stops before newline is read
        return is;
    }

    std::ostream& operator<<(std::ostream& os, const MotorVehicle& other) {
        return other.MotorVehicle::write(os);
    }

    std::istream& operator>>(std::istream& is, MotorVehicle& other) {
        return other.MotorVehicle::read(is);
    }
}