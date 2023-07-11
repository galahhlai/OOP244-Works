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

#ifndef LABELMAKER_H
#define LABELMAKER_H

#include "Label.h"

namespace sdds
{
    class LabelMaker {
        Label* m_labels;
        int m_noOfLabels;

    public:
        LabelMaker(int noOfLabels);
        ~LabelMaker();
        void readLabels();
        void printLabels() const;
    };
}

#endif //!LABELMAKER_H
