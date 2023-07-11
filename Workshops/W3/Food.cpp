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
// source file food.cpp
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include "Food.h"
#include "cstring.h"

using namespace std;

namespace sdds
{
    //constructor of object Food
    Food::Food()
    {
        m_name[0] = '\0';
        m_calories = 0;
        m_when = 0;
    }
    void Food::set(const char* name, int calories, int when)
    {
        //if the parameters are valid
        if (name != nullptr && calories >= 0 && calories <= 3000 && when >= 1 && when <= 4)
        {
            //update the object
            strnCpy(m_name, name, MAX_FOOD_NAME_LENGTH);
            m_name[MAX_FOOD_NAME_LENGTH] = '\0';
            m_calories = calories;
            m_when = when;
        }
        else
        {
            //set the object to empty state
            m_name[0] = '\0';
            m_calories = 0;
            m_when = 0;
        }
    }
    int Food::calories() const
    {
        //retrieve the value from private class member m_calories
        return m_calories;
    }
    void Food::display() const
    {
        // check if the object is valid
        if(isValid())
        {
            //display the corresponding information
            cout << "| ";
            cout.width(30);
            cout.fill('.');
            cout << left << m_name << " | " ;
            cout.width(4);
            cout.fill(' ');
            cout << right << m_calories << " | ";

            //transforming the mealtime code into words
            switch(m_when)
            {
                case 1:
                    cout << "Breakfast  |" << endl;
                    break;
                case 2:
                    cout << "Lunch      |" << endl;
                    break;
                case 3:
                    cout << "Dinner     |" << endl;
                    break;
                case 4:
                    cout << "Snack      |" << endl;
                    break;
            }
        }
        else
        {
            cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
        }
    }
    bool Food::isValid() const
    {
        //constraints of a valid object
        if(m_name[0] != '\0' && m_calories >= 0 && m_calories <= 3000 && m_when >= 1 && m_when <= 4)
        {
            return true;
        }
        return false;
    }
}