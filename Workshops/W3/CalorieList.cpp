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
// source file CalorieList.cpp
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "CalorieList.h"
#include "cstring.h"

using namespace std;

namespace sdds
{
    //constructor of object: CalorieList
    CalorieList::CalorieList()
    {
        m_foodItem = nullptr;
        m_noOfItems = 0;
        m_noOfItemsAdded = 0;
    }
    void CalorieList::init(int size)
    {
        //object will only be initialized when the size is a positive number
        if(size > 0)
        {
            this->m_noOfItems = size;
            m_foodItem = new Food[m_noOfItems];
            m_noOfItemsAdded = 0;
        }
    }
    bool CalorieList::add(const char* item_name, int calories, int when)
    {
        //if foodItem is valid and the no. of item added not yet exceed the list size
        if(m_foodItem != nullptr && m_noOfItemsAdded < m_noOfItems)
        {
            m_foodItem[m_noOfItemsAdded].set(item_name, calories, when);
            m_noOfItemsAdded++;
            return true;
        }
        return false;
    }
    //validation of displaying the correct list outlook
    bool CalorieList::isValid() const
    {
        if(m_foodItem == nullptr)
        {
            return false;
        }
        for (int i = 0; i < m_noOfItems; i++)
        {
            if(!m_foodItem[i].isValid())
                return false;
        }
        return true;
    }
    //part of the display function
    void CalorieList::header() const
    {
        cout << "+----------------------------------------------------+" << endl;
        if(isValid())
        {
            cout << "|  Daily Calorie Consumption                         |" << endl;
        }
        else
        {
            cout << "| Invalid Calorie Consumption list                   |" << endl;
        }
        cout << "+--------------------------------+------+------------+" << endl;
        cout << "| Food name                      | Cals | When       |" << endl;
        cout << "+--------------------------------+------+------------+" << endl;
    }
    //for summation of calories on the list
    int CalorieList::totalCalories() const
    {
        int totalCalories = 0;
        for(int i = 0; i < m_noOfItemsAdded; i++)
        {
            totalCalories += m_foodItem[i].calories();
        }
        return totalCalories;
    }
    //part of the display function
    void CalorieList::footer() const
    {
        cout << "+--------------------------------+------+------------+" <<endl;
        if(isValid())
        {
            cout << "|    Total Calories for today:";
            cout.width(9);
            cout.fill(' ');
            cout << right << totalCalories();
            cout << " |            |" << endl;
        }
        else
        {
            cout << "|    Invalid Calorie Consumption list                |" << endl;
        }
        cout << "+----------------------------------------------------+" <<endl;
    }
    void CalorieList::display() const
    {
        header(); //part of the display function
        //for loop to display every food object
        if(m_foodItem != nullptr)
        {
            for (int i = 0; i < m_noOfItems; i++)
            {
                m_foodItem[i].display();
            }
        }
        footer(); //part of the display function
    }
    //for de-allocation of dynamic memory
    void CalorieList::deallocate()
    {
        delete[] m_foodItem;
        m_foodItem = nullptr;
        m_noOfItems = 0;
        m_noOfItemsAdded = 0;
    }
}