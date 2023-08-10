// Final Project Milestone 5
// Book Module
// File	Book.h
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

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H

#include "Publication.h"

namespace sdds {
    class Book: public Publication {
        char* m_author {};
    public:
        Book();
        //rule of three
        ~Book();
        Book(const Book& other);
        Book& operator=(const Book& other);
        //methods to be overridden by derived classes
        char type() const;
        std::ostream& write(std::ostream& os) const;
        std::istream& read(std::istream& is);
        void set(int member_id);
        operator bool() const;
    };
}

#endif //!SDDS_BOOK_H