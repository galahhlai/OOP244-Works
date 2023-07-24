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

#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H

#include "LblShape.h"
#include <cstring>

namespace sdds {
    class Rectangle: public LblShape {
        unsigned m_width;
        unsigned m_height;
    public:
        Rectangle();
        Rectangle(const char* label, unsigned width, unsigned height);
        ~Rectangle();
        void getSpec(std::istream& is);
        void draw(std::ostream& os) const;
    };
}



#endif //!SDDS_RECTANGLE_H
