/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 10 Part 1
// Name: Hau Hin Lai
// Student ID: 118795228
// Email: hlai23@myseneca.ca
// Section: ZAA
// Date of completion: 6 Aug 2023

   I have done all the coding by myself and only copied the code that my professor
   provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SDDS_SEARCHNLIST_H
#define SDDS_SEARCHNLIST_H

#include "Collection.h"

namespace sdds {
    //requirements:
    //typename T1 - must have an operator==() overloaded to work with T2.
    //typename T2 - can be any type but able to work with T1 through operator==() overloaded.
    template<typename T1, typename T2>
    bool search(Collection<T1>& collection, T1 array[], int arraySize, T2 key) {
        bool result = false;
        for(int i = 0; i < arraySize; i++) {
            if(array[i] == key) {
                result = true;
                collection.add(array[i]);
            }
        }
        return result;
    }
    //requirements:
    //typename U - must have an operator<<() overloaded to work with ostream.
    template<typename U>
    void listArrayElements(const char* title, const U array[], int arraySize) {
        std::cout << title << std:: endl;
        for(int i = 0; i < arraySize; i++) {
            std::cout << i + 1 << ": ";
            std::cout << array[i] << std::endl;
        }
    }
}

#endif //!SDDS_SEARCHNLIST_H