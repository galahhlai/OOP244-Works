/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 4 Part 2
// Name: Hau Hin Lai
// Student ID: 118795228
// Email: hlai23@myseneca.ca
// Section: ZAA
// Date of completion: 9 June 2023

   I have done all the coding by myself and only copied the code that my professor
   provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef LABEL_H
#define LABEL_H

#include <iostream>

using namespace std;

namespace sdds
{
    class Label {
        char m_frame[9];
        char* m_content;

    public:
        Label();
        Label(const char* frameArg);
        Label(const char* frameArg, const char* content);
        ~Label();
        void readLabel();
        ostream& printLabel() const;
    };
}


#endif //!LABEL_H
