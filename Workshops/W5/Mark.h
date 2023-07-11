/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 5 Part 2
// Name: Hau Hin Lai
// Student ID: 118795228
// Email: hlai23@myseneca.ca
// Section: ZAA
// Date of completion: 15 June 2023

   I have done all the coding by myself and only copied the code that my professor
   provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef WS05_MARK_H
#define WS05_MARK_H

namespace sdds {
    class Mark
    {
        int m_mark;
        void setEmpty ();

    public:
        Mark();
        Mark(int mark);
        operator int() const;
        operator double() const;
        operator char() const;
        Mark& operator=(int value);
        Mark& operator+=(int value);
        friend int operator+=(int& value, const Mark& mark);
    };
}

#endif //WS05_MARK_H

