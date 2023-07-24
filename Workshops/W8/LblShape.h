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

#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H

#include <cstring>
#include <string>
#include "Shape.h"

namespace sdds {
    class LblShape: public Shape {
        char* m_label{};
    protected:
        const char* label() const;
    public:
        LblShape();
        LblShape(const char* label);
        ~LblShape();
        LblShape(const LblShape&) = delete;
        LblShape& operator=(const LblShape&) = delete;
        void getSpec(std::istream& is);
    };
}

#endif //!SDDS_LBLSHAPE_H
