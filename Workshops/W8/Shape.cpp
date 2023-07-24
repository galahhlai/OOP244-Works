/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 8 Part 1
// Name: Hau Hin Lai
// Student ID: 118795228
// Email: hlai23@myseneca.ca
// Section: ZAA
// Date of completion: 23 July 2023

   I have done all the coding by myself and only copied the code that my professor
   provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include "Shape.h"

namespace sdds {
    std::ostream& operator<<(std::ostream& os, const Shape& shape) {
        shape.draw(os);
        return os;
    }

    std::istream& operator>>(std::istream& is, Shape& shape) {
        shape.getSpec(is);
        return is;
    }
}