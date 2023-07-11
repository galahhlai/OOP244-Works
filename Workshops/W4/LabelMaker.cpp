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

#include "LabelMaker.h"

using namespace std;

namespace sdds
{
    LabelMaker::LabelMaker(int noOfLabels)
    {
        m_noOfLabels = noOfLabels;
        //assign dynamic memory for array of labels
        m_labels = new Label[m_noOfLabels];
    }
    LabelMaker::~LabelMaker()
    {
        //delete the dynamic memory
        delete[] m_labels;
        m_labels = nullptr;
    }
    void LabelMaker::readLabels()
    {
        //loop readlabel function in label.cpp for m_noOfLabels times
        cout << "Enter " << m_noOfLabels << " labels:" << endl;
        for (int i = 0; i < m_noOfLabels; i++)
        {
            cout << "Enter label number " << i + 1 << endl << "> ";
            m_labels[i].readLabel();
        }
    }
    void LabelMaker::printLabels() const
    {
        //loop printlabel for m_noOfLabels times
        for (int i = 0; i < m_noOfLabels; i++)
        {
            m_labels[i].printLabel();
            cout << endl;
        }
    }
}