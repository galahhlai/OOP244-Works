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

#include "Rectangle.h"

namespace sdds {
    Rectangle::Rectangle(): LblShape(), m_width(0), m_height(0) {}

    Rectangle::Rectangle(const char* label, unsigned width, unsigned height)
                : LblShape(label), m_width(width), m_height(height) {
        if(m_height < 3 || m_width < (std::strlen(label) + 2)) {    //if height < 3 or width < length of the label string + 2
            m_height = 0;   //set it as empty
            m_width = 0;    //set it as empty
        }
    }

    Rectangle::~Rectangle() = default;

    void Rectangle::getSpec(std::istream &is) {
        LblShape::getSpec(is);  //read the string first using base class function
        is >> m_width;  //as delimiter is discarded, directly read the input and store it as width
        is.ignore();    //ignore the delimiter
        is >> m_height; //read the input and store it as height
        is.ignore(1000,'\n');   //clear the remaining input buffer
    }

    void Rectangle::draw(std::ostream &os) const {
        if(m_width != 0 && m_height != 0) {
            unsigned i{};
            os << '+';  //first line
            for( i = 0; i < (m_width - 2); i++) {
                os << '-';
            }
            os << '+' << std::endl;
            os << '|' << label();   //second line
            for( i = 0; i < (m_width - std::strlen(label()) - 2); i++) {    //third line to the second last line
                os << ' ';
            }
            os << '|' << std::endl;
            for( i = 0; i < (m_height - 3); i++) {
                os << '|';
                for(unsigned j = 0; j < (m_width - 2); j++) {
                    os << ' ';
                }
                os << '|' << std::endl;
            }
            os << '+';  //last line
            for( i = 0; i < (m_width - 2); i++) {
                os << '-';
            }
            os << '+';
        }
    }
}