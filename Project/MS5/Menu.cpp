// Final Project Milestone 5
// Menu Module
// File	Menu.cpp
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
#include <iostream>
#include <cstring>
#include "Menu.h"

using namespace std;

namespace sdds {
    MenuItem::MenuItem(const char* content) {
        if(content) {
            delete[] m_content;
            m_content = new char[strlen(content) + 1];
            strcpy(m_content, content);
        } else {
            m_content = nullptr;
        }
    }

    MenuItem::~MenuItem() {
        delete[] m_content;
        m_content = nullptr;
    }

    MenuItem::operator bool() const {
        return (m_content != nullptr);
    }

    MenuItem::operator const char*() const {
        return m_content;
    }

    void MenuItem::display() const {
        if(m_content) {
            cout << m_content;
        }
    }

    Menu::Menu() {
        m_title = nullptr;
        for(int i = 0; i < MAX_MENU_ITEMS; i++) {
            m_items[i] = nullptr;
        }
        m_noOfItems = 0;
    }

    Menu::Menu(const char* title) {
        m_title = new MenuItem(title); //assign title
        for(int i = 0; i < MAX_MENU_ITEMS; i++) {
            m_items[i] = nullptr;
        }
        m_noOfItems = 0;
    }

    Menu::~Menu() {
        delete m_title;
        m_title = nullptr;
        for(int i = 0; i < MAX_MENU_ITEMS; i++) { //delete all dynamic memory for each menu item
            delete m_items[i];
            m_items[i] = nullptr;
        }
    }

    void Menu::displayTitle() const {
        if(m_title != nullptr) {
            cout << m_title->m_content;
        }
    }

    void Menu::display() const {
        if(m_title) {
            displayTitle();
            cout << endl;
        }
        for(int i = 0; i < m_noOfItems; i++) {
            cout.width(2);
            cout << right << (i + 1) << "- " << m_items[i]->m_content << endl;
        }
        cout << " 0- Exit" << endl << "> ";
    }

    unsigned Menu::run() const {
        unsigned select;
        display();
        cin >> select;                                        //receive selection from input
        while(cin.fail() || select > (unsigned)m_noOfItems) { //if the input type does not match unsigned type OR greater than the no of items inside the menu
            cin.clear();                                      //clear error flag in input
            cin.ignore(1000, '\n');                           //clear input buffer
            cout << "Invalid Selection, try again: ";         //error message
            cin >> select;                                    //ask user to input again
        }
        return select;
    }

    unsigned int Menu::operator~() const {
        return run();
    }

    Menu& Menu::operator<<(const char* menuItemContent) {        //add new item into the menu
        if(m_noOfItems < MAX_MENU_ITEMS) {                       //if the menu is not full yet
            MenuItem* newItem = new MenuItem(menuItemContent);   //instantiate new menuitem
            m_items[m_noOfItems] = newItem;                      //put the new item into the array of menuitem in menu
            m_noOfItems++;                                       //update no of items in the menu
        }
        return *this;
    }

    Menu::operator int() const {
        return m_noOfItems;
    }

    Menu::operator unsigned() const {
        return m_noOfItems;
    }

    Menu::operator bool() const {
        return (m_noOfItems > 0);
    }

    ostream& operator<<(ostream& os, const Menu& menu) {
        if(menu.m_title != nullptr) {
            menu.displayTitle();
        }
        return os;
    }

    const char* Menu::operator[](int index) const {
        return m_items[index % m_noOfItems]->m_content;    //index will loop from 0 again if it exceeds no of items
    }
}