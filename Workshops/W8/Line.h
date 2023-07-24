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

#ifndef SDDS_LINE_H
#define SDDS_LINE_H

#include "LblShape.h"

namespace sdds {
    class Line: public LblShape {
        unsigned m_length;
    public:
        Line();
        Line(const char* label, unsigned length);
        ~Line();
        void getSpec(std::istream& is);
        void draw(std::ostream& os) const;
    };
}



#endif //!SDDS_LINE_H
