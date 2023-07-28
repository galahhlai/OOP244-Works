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
#define _CRT_SECURE_NO_WARNINGS
#include "LblShape.h"

namespace sdds {
    const char* LblShape::label() const {
        return m_label;
    }

    LblShape::LblShape(): m_label(nullptr) {}

    LblShape::LblShape(const char* label) {
        m_label = new char[std::strlen(label) + 1];
        std::strcpy(m_label, label);
    }

    LblShape::~LblShape() {
        delete[] m_label;
    }

    void LblShape::getSpec(std::istream &is) {
        std::string spec;   //as the length of output is unknown
        getline(is, spec, ','); //read the string until the delimiter from instream and store it in spec, the delimiter will be discarded

        delete[] m_label;   //deallocate the memory before reallocate new one
        m_label = new char[spec.length() + 1];
        std::strcpy(m_label, spec.c_str()); //change the spec back to cstring using c_str()
    }
}
