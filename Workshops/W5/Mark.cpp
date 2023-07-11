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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Mark.h"

using namespace std;
namespace sdds {
    //set the mark to be invalid
    void Mark::setEmpty() {
        m_mark = -1;
    }
    //default constructor setting the mark to 0
    Mark::Mark() {
        m_mark = 0;
    }
    //constructor with one argument setting the mark to the value of the argument if the value is valid
    Mark::Mark(int mark) {
        if(mark >= 0 && mark <= 100) {
            m_mark = mark;
        } else {
            setEmpty();
        }
    }
    //return the mark value of the class
    Mark::operator int() const {
        return (m_mark >= 0 && m_mark <= 100 ? m_mark : 0);
    }
    //return the gpa value based the mark value of the class
    Mark::operator double() const {
        if(m_mark >= 0 && m_mark < 50) {
            return 0.0;
        } else if(m_mark >= 50 && m_mark < 60) {
            return 1.0;
        } else if(m_mark >= 60 && m_mark < 70) {
            return 2.0;
        } else if(m_mark >= 70 && m_mark < 80) {
            return 3.0;
        } else if(m_mark >= 80 && m_mark <= 100) {
            return 4.0;
        } else {
            return 0.0;
        }
    }
    //return the grade based on the mark value of the class
    Mark::operator char() const {
        if(m_mark >= 0 && m_mark < 50) {
            return 'F';
        } else if(m_mark >= 50 && m_mark < 60) {
            return 'D';
        } else if(m_mark >= 60 && m_mark < 70) {
            return 'C';
        } else if(m_mark >= 70 && m_mark < 80) {
            return 'B';
        } else if(m_mark >= 80 && m_mark <= 100) {
            return 'A';
        } else {
            return 'X';
        }
    }
    //directly set the mark value to the value in the argument if the value in argument is valid
    Mark& Mark::operator=(int value) {
        if(value >= 0 && value <= 100) {
            m_mark = value;
        } else {
            //set to invalid if the value in argument is invalid
            setEmpty();
        }
        return *this;
    }
    //add the value in the argument to the mark of the class
    Mark& Mark::operator+=(int value) {
        if(m_mark >= 0 && m_mark <= 100) {
            m_mark += value;
        }
        //if the mark is invalid, ignore action
        return *this;
    }
    //add the mark value of the class to another value
    int operator+=(int& value, const Mark& mark) {
        //add the mark value to another value if the mark is valid
        if(int(mark) != 0) {
            value += int(mark);
        } else {
            //ignore the mark and return the original value
            return value;
        }
        return value;
    }
}