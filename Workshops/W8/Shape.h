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

#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H

#include <iostream>

namespace sdds {
    class Shape {
    public:
        virtual void draw(std::ostream& os) const = 0;
        virtual void getSpec(std::istream& is) = 0;
        virtual ~Shape() = default;
    };
    std::ostream& operator<<(std::ostream&, const Shape&);
    std::istream& operator>>(std::istream&, Shape&);
}

#endif //!SDDS_SHAPE_H
