/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 4 Part 1
// Name: Hau Hin Lai
// Student ID: 118795228
// Email: hlai23@myseneca.ca
// Section: ZAA
// Date of completion: 7 June 2023

   I have done all the coding by myself and only copied the code that my professor
   provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////
***********************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "cstring.h"  // using strLen, strCpy and strCmp 
#include "Canister.h"
using namespace std;
namespace sdds
{
    double PI = 3.14159265;     //global variable
    void Canister::setToDefault()
    {
        m_contentName = nullptr;
        m_height = 13.0;
        m_diameter = 10.0;
        m_contentVolume = 0.0;
        m_usable = true;
    }
    bool Canister::isEmpty() const
    {
        if(m_contentVolume < 0.00001)
        {
            return true;
        }
        return false;
    }
    bool Canister::hasSameContent(const Canister &C) const
    {
        if(m_contentName != nullptr && C.m_contentName != nullptr)      //both the current object and the input object have assigned a content
        {
            return (strCmp(m_contentName, C.m_contentName) == 0);       //check whether their content are same
        }
        return false;
    }
    void Canister::setName(const char *Cstr)
    {
        if(Cstr != nullptr && m_usable)     //check if the input content name is not null and the current object is usable
        {
            delete[] m_contentName;     //if so, delete the original content name
            m_contentName = nullptr;    //set the content name to safe state first

            int CstrLength = strLen(Cstr);
            m_contentName = new char[CstrLength + 1];       //allocate new memory for the content name dynamically
            strCpy(m_contentName, Cstr);        //copy the name from input to the newly allocated memory
        }
    }
    Canister::Canister()        //constructor setting the object to default
    {
        setToDefault();
    }
    Canister::Canister(const char *contentName)     //constructor with content name input
    {
        setToDefault();
        setName(contentName);
    }
    Canister::Canister(double height, double diameter, const char *contentName)     //constructor with dimensions and content name input
    {
        setToDefault();
        if(height >= 10.0 && height <= 40.0 && diameter >= 10.0 && diameter <= 30.0)    //constraints for the dimensions of the canister
        {
            m_height = height;
            m_diameter = diameter;
            m_contentVolume = 0.0;
            setName(contentName);
        }
        else
        {
            m_usable = false;       //regard as unusable if the dimensions are out of range
        }
    }
    Canister::~Canister()
    {
        delete[] m_contentName;     //destructor to remove the dynamic memory allocated to the object to prevent memory leak
        m_contentName = nullptr;
    }
    void Canister::clear()  //clear the content of the canister and make it usable
    {
        delete[] m_contentName;
        m_contentName = nullptr;
        m_contentVolume = 0.0;
        m_usable = true;
    }
    double Canister::capacity() const       //calculate the capacity of the object by its dimensions
    {
        double capacity = PI * (m_height - 0.267) * m_diameter / 2 * m_diameter / 2;
        return capacity;
    }
    double Canister::volume() const     //show the volume of the object
    {
        return m_contentVolume;
    }
    Canister& Canister::setContent(const char *contentName)     //set the content of the object
    {
        if (contentName == nullptr)     //if the input content name is null
        {
            m_usable = false;       //if so set it to unusable
        }
        else if(isEmpty())      //if the canister is empty
        {
            setName(contentName);       //if so, change the content name to reuse it
        }
        else if(!hasSameContent(contentName))       //if the canister is not empty but the new content name and the original content name is different
        {
            m_usable = false;       //make it unusable
        }
        return *this;
    }
    Canister& Canister::pour(double quantity)
    {
        if(m_usable && quantity > 0 && ((quantity + volume()) <= capacity()))       //if the canister is usable and the new volume of the canister after pouring does not exceed its capacity
        {
            m_contentVolume += quantity;        //if so add to the the volume of the current canister
        }
        else        //if not
        {
            m_usable = false;       //make it unusable
        }
        return *this;
    }
    Canister& Canister::pour(Canister& C)
    {
        setContent(C.m_contentName);        //set the content name to the argument canister
        if(C.m_contentVolume > (capacity() - volume()))     //if the remaining capacity cannot hold the volume of the argument canister
        {
            C.m_contentVolume -= (capacity() - volume());       //reduce the argument volume by the remaining capacity
            m_contentVolume = capacity();       //now the current canister is full of capacity
        }
        else        //if the remaining capacity can hold
        {
            pour(C.m_contentVolume);        //pour from argument to current canister
            C.m_contentVolume = 0.0;        //the argument canister is now empty
        }
        return *this;
    }
    ostream& Canister::display() const
    {
        cout << fixed << setprecision(1);
        cout << setw(7) << capacity() << "cc (" << m_height << "x" << m_diameter <<") Canister";
        if(!m_usable)
        {
            cout << " of Unusable content, discard!";
        }
        else if(m_contentName != nullptr)
        {
            cout << " of " << setw(7) << m_contentVolume << "cc   " << m_contentName;
        }
        return cout;
    }
}