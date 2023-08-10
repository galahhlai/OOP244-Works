// Final Project Milestone 5
// Publication Module
// File	Publication.h
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
#ifndef SDDS_PUBLICATION_H
#define SDDS_PUBLICATION_H

#include <iostream>
#include <cstring>
#include "Streamable.h"
#include "Date.h"
#include "Lib.h"

namespace sdds {
    class Publication: public Streamable {
        char* m_title;
        char m_shelfId[5]; //last char for null terminator
        int m_membership;
        int m_libRef;
        Date m_date;
    public:
        Publication();
        // Sets the membership attribute to either zero or a five-digit integer.
        virtual void set(int member_id);
        // Sets the **libRef** attribute value
        void setRef(int value);
        // Sets the date to the current date of the system.
        void resetDate();
        //Returns the character 'P' to identify this object as a "Publication object"
        virtual char type()const;
        //Returns true is the publication is checkout (membership is non-zero)
        bool onLoan()const;
        //Returns the date attribute
        Date checkoutDate()const;
        //Returns true if the argument title appears anywhere in the title of the
        //publication. Otherwise, it returns false; (use strstr() function in <cstring>)
        bool operator==(const char* title)const;
        //Returns the title attribute
        operator const char* ()const;
        //Returns the libRef attribute.
        int getRef()const;
        //return true if the object is an input or output object
        bool conIO(std::ios& io) const;

        std::ostream& write(std::ostream& os) const;
        std::istream& read(std::istream& istr);
        operator bool() const;

        //destructor, copy constructor and copy assignment operator under rule of three
        ~Publication();
        Publication(const Publication& other);
        Publication& operator=(const Publication& other);
    };
}

#endif //!SDDS_PUBLICATION_H
