/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 3 Part 1
// Version 1.0
// Name: Hau Hin Lai
// Student ID: 118795228
// Section: ZAA
// Description
// source file item.cpp
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include "cstring.h"
#include "Item.h"
using namespace std;

namespace sdds
{
    void Item::setName(const char* name)
    {
        strnCpy(m_itemName, name, 20);
        m_itemName[20] = '\0';
    }
    void Item::setEmpty()
    {
        m_itemName[0] = '\0';
        m_price = 0.0;
    }
    void Item::set(const char* name, double price, bool taxed)
    {
        if (price < 0.0 || name == nullptr)
        {
            setEmpty();
        }
        else
        {
            setName(name);
            m_price = price;
            m_taxed = taxed;
        }
    }
    double Item::price() const
    {
        return m_price;
    }
    double Item::tax() const
    {
        const double taxRate = 0.13;
        return (m_taxed ? m_price * taxRate : 0.0);
    }
    bool Item::isValid() const
    {
        if(m_itemName[0] != '\0')
        {
            return true;
        }
        return false;
    }
    void Item::display() const
    {
        if(isValid())
        {
            cout << "| ";
            cout.width(20),
            cout.fill('.');
            cout << left << m_itemName << " | " ;
            cout.width(7), cout.fill(' '), cout.setf(ios::fixed), cout.precision(2);
            cout << right << m_price << " | " << (m_taxed ? "Yes" : "No ") << " |" << endl;
        }
        else
        {
            cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
        }
    }
}