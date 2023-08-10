// Final Project Milestone 5
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
#include "Publication.h"
#include "Book.h"
#include "Lib.h"

namespace sdds {
   class LibApp {
       char m_filename[256] {'\0'};
       bool m_changed;
       Menu m_mainMenu;
       Menu m_exitMenu;
       //publication type menu
       Menu m_pubMenu;
       //publication pointer array
       Publication* m_ppa[SDDS_LIBRARY_CAPACITY] {};
       //no of loaded publications
       int m_nolp {};
       //last library reference number
       int m_llrn {};

       bool confirm(const char* message);
       void load();
       void save();
       int search(int mode) const;
       void returnPub();
       void newPublication();
       void removePublication();
       void checkOutPub();
       Publication* getPub(int libRef) const;
   public:
       LibApp(const char* filename);
       ~LibApp();
       void run();
   };
}
#endif //!SDDS_LIBAPP_H



