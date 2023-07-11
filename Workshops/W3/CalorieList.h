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
// header file CalorieList.h
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_CALORIELIST_H_
#define SDDS_CALORIELIST_H_

#include "Food.h"

namespace sdds
{
    class CalorieList {
        Food* m_foodItem;
        int m_noOfItems;
        int m_noOfItemsAdded;

    public:
        CalorieList();
        void init(int size);
        bool add(const char* item_name, int calories, int when);
        bool isValid() const;
        void header() const;
        int totalCalories() const;
        void footer() const;
        void display()const;
        void deallocate();
    };
}



#endif //!SDDS_CALORIELIST_H_
