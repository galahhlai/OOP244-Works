// Final Project Milestone 2
// Menu Module
// File	LibApp.h
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
#ifndef SDDS_LIBAPP_H
#define SDDS_LIBAPP_H

#include "Menu.h"

namespace sdds {
   class LibApp {
       bool m_changed;
       Menu m_mainMenu;
       Menu m_exitMenu;

       bool confirm(const char* message);
       void load();
       void save();
       void search();
       void returnPub();
       void newPublication();
       void removePublication();
       void checkOutPub();
   public:
       LibApp();
       void run();
   };
}
#endif //!SDDS_LIBAPP_H



