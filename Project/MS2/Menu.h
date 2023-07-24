// Final Project Milestone 2
// Menu Module
// File	Menu.h
// Version 1.0
// Student ID: 118795228
// Email: hlai23@myseneca.ca
// Section: ZAA
// =================================================================
// I have done all the coding by myself and only copied the code that my professor
// provided to complete my workshops and assignments.
// =================================================================
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
//
/////////////////////////////////////////////////////////////////
#ifndef SDDS_MENU_H__
#define SDDS_MENU_H__
#include<iostream>
#include <cstring>

#define MAX_MENU_ITEMS 20

namespace sdds {
    class Menu; // forward declaration

    class MenuItem {
        friend class Menu;
        char* m_content = nullptr;

        MenuItem(const char* content);
        MenuItem(const MenuItem&) = delete; //no copy constructor allowed
        MenuItem& operator=(const MenuItem&) = delete; //no copy assignment operator allowed
        ~MenuItem();
        operator bool() const;
        operator const char*() const;
        void display() const;
    };

    class Menu {
        MenuItem* m_title = nullptr;
        MenuItem* m_items[MAX_MENU_ITEMS] {nullptr};
        int m_noOfItems;

    public:
        Menu();
        Menu(const char* title);
        ~Menu();
        Menu(const Menu&) = delete; //copy constructor not allowed
        Menu& operator=(const Menu&) = delete; //copy assignment operator not allowed

        void displayTitle() const; //display menu title
        void display() const; //display menu items
        unsigned run() const; //the process of displaying menu and receive selection from input

        //overload operators
        unsigned operator~() const;
        Menu& operator<<(const char* menuItemContent);
        operator int() const;
        operator unsigned() const;
        operator bool() const;
        friend std::ostream& operator<<(std::ostream&, const Menu&);
        const char* operator[](int) const;
    };
}
#endif //!SDDS_MENU_H__