/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 3 Part 1
// Version 1.0
// Name: Hau Hin Lai
// Student ID: 118795228
// Section: ZAA
// Description
// source file bill.cpp
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include "cstring.h"
#include "Bill.h"
using namespace std;
namespace sdds
{
    void Bill::setEmpty()
    {
        m_title[0] = '\0';
        m_items = nullptr;
    }
    bool Bill::isValid() const
    {
        if(m_title[0] == '\0' || m_items == nullptr)
        {
            return false;
        }
        for(int i = 0; i < m_noOfItems; i++)
        {
            if(!m_items[i].isValid())
            {
                return false;
            }
        }
        return true;
    }
    double Bill::totalTax() const
    {
        double totalTax = 0.0;
        for (int i = 0; i < m_itemsAdded; i++)
        {
            totalTax += m_items[i].tax();
        }
        return totalTax;
    }
    double Bill::totalPrice() const
    {
        double totalPrice = 0.0;
        for (int i = 0; i < m_itemsAdded; i++)
        {
            totalPrice += m_items[i].price();
        }
        return totalPrice;
    }
    void Bill::Title() const
    {
        cout << "+--------------------------------------+" << endl;
        if(isValid())
        {
            cout << "| ";
            cout.width(36);
            cout << left << m_title << " |" << endl;
        }
        else
        {
            cout << "| Invalid Bill                         |" << endl;
        }
        cout << "+----------------------+---------+-----+" << endl;
        cout << "| Item Name            | Price   + Tax |" << endl;
        cout << "+----------------------+---------+-----+" << endl;
    }
    void Bill::footer() const
    {
        cout << "+----------------------+---------+-----+" << endl;
        if(isValid())
        {
            cout << "|                Total Tax: ";
            cout.width(10), cout.setf(ios::fixed), cout.precision(2);
            cout << right << totalTax() << " |" << endl;
            cout << "|              Total Price: ";
            cout.width(10), cout.setf(ios::fixed), cout.precision(2);
            cout << right << totalPrice() << " |" << endl;
            cout << "|          Total After Tax: ";
            cout.width(10), cout.setf(ios::fixed), cout.precision(2);
            cout << right << totalPrice() + totalTax() << " |" << endl;
        }
        else
        {
            cout << "| Invalid Bill                         |" << endl;
        }
        cout << "+--------------------------------------+" << endl;
    }
    void Bill::init(const char* title, int noOfItems)
    {
        if(title == nullptr || noOfItems <= 0)
        {
            setEmpty();
        }
        else
        {
            m_noOfItems = noOfItems;
            m_itemsAdded = 0;
            strnCpy(m_title, title, 36);
            m_title[36] = '\0';

            m_items = new Item[m_noOfItems];
            for (int i = 0; i < m_noOfItems; i++)
            {
                m_items[i].setEmpty();
            }
        }
    }
    bool Bill::add(const char* item_name, double price, bool taxed)
    {
        if(m_itemsAdded < m_noOfItems)
        {
            m_items[m_itemsAdded].set(item_name, price, taxed);
            m_itemsAdded++;
            return true;
        }
        return false;
    }
    void Bill::display() const
    {
        Title();
        for(int i = 0; i < m_noOfItems; i++)
        {
            m_items[i].display();
        }
        footer();
    }
    void Bill::deallocate()
    {
        delete[] m_items;
        m_items = nullptr;
    }
}