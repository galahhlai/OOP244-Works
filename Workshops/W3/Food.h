/** I have done all the coding by myself and only copied the code that my professor
    provided to complete my workshops and assignments. **/
/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 3 Part 2
// Version 1.0
// Name: Hau Hin Lai
// Student ID: 118795228
// Section: ZAA
// Description
// header file food.h
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_FOOD_H_
#define SDDS_FOOD_H_

#define MAX_FOOD_NAME_LENGTH 30

namespace sdds {
    class Food {
        char m_name[MAX_FOOD_NAME_LENGTH + 1]; //m_(variable) for class members
        int m_calories;
        int m_when;

    public:
        Food();
        void set(const char* name, int calories, int when);
        int calories() const;
        void display() const;
        bool isValid() const;
    };
}

#endif //!SDDS_FOOD_H_