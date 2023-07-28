// Final Project Milestone 3
// Streamable Module
// File	Streamable.cpp
// Version 1.0
// Student ID: 118795228
// Email: hlai23@myseneca.ca
// Section: ZAA
// =================================================================
// I have done all the coding by myself and only copied the code that my professor
// provided to complete my workshops and assignments.
// =================================================================
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
//
/////////////////////////////////////////////////////////////////
#include "Streamable.h"

namespace sdds {
    std::ostream& operator<<(std::ostream& os, const Streamable& other) {
        if(other) {
            other.write(os);
        }
        return os;
    }
    std::istream& operator>>(std::istream& is, Streamable& other) {
        other.read(is);
        return is;
    }
}