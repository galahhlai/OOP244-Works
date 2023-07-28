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

#include "Line.h"

namespace sdds {
    Line::Line(): LblShape(), m_length(0) {}

    Line::Line(const char* label, unsigned length):
       LblShape(label), m_length(length) {}

    Line::~Line() = default;

    void Line::getSpec(std::istream &is) {
        LblShape::getSpec(is);  // read the string from the instream using the base class function
        is >> m_length; //as delimiter is discarded in base class function, read the instream directly and store it as length
        is.ignore(1000,'\n'); //clear the remaining input buffer
    }

    void Line::draw(std::ostream& os) const {
        if(m_length > 0 && label() != nullptr) {
            os << label() << std::endl; //print the string
            for(unsigned i = 0; i < m_length; i++) {    //loop for the line
                os << '=';
            }
        }
    }
}
