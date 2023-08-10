// Final Project Milestone 5
// Book Module
// File	Book.cpp
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
#include "Book.h"

namespace sdds {
    Book::Book():Publication(), m_author{} {}
    char Book::type() const {
        return 'B';
    }
    std::ostream& Book::write(std::ostream& os) const {
        //call base class method
        Publication::write(os);
        //check whether write on standard io stream
        if(conIO(os)) {
            os << ' ';
            os.width(SDDS_AUTHOR_WIDTH);
            //if length of author is out of preset width, write until the width
            if(std::strlen(m_author) > SDDS_AUTHOR_WIDTH) {
                char author[SDDS_AUTHOR_WIDTH + 1] {'\0'};
                std::strncpy(author, m_author, SDDS_AUTHOR_WIDTH);
                os << std::left << author;
                os << " |";
            } else {
                //write whole author name
                os << std::left << m_author;
                os << " |";
            }
        } else {
            //if not standard io stream
            os << '\t' << m_author;
        }
        return os;
    }
    std::istream& Book::read(std::istream& is) {
        //call the base class method
        Publication::read(is);
        //clear the dynamic allocation
        delete[] m_author;
        m_author = nullptr;
        //temp variable for validation
        char temp_author[256] {'\0'};

        if (conIO(is)) {
            //if standard io stream
            is.ignore(1, '\n');
            std::cout << "Author: ";
            //get user input
            is.getline(temp_author, 256);
        } else {
            //if not standard io stream
            is.ignore(1, '\t');
            is.get(temp_author, 256);
        }
        //if valid input i.e. not exceed the temp variable length
        if(!is.fail()) {
            //dynamic memory allocation
            m_author = new char[std::strlen(temp_author) + 1];
            std::strcpy(m_author, temp_author);
        }
        return is;
    }
    void Book::set(int member_id) {
        Publication::set(member_id);
        Publication::resetDate();
    }
    Book::operator bool() const {
        if(m_author && m_author[0] != '\0' && Publication::operator bool()) {
            return true;
        }
        return false;
    }
    //rule of three
    Book::~Book() {
        delete[] m_author;
    }
    Book::Book(const Book& other): Publication(other), m_author{} {
        if(other.m_author) {
            m_author = new char[std::strlen(other.m_author) + 1];
            std::strcpy(m_author, other.m_author);
        }
    }
    Book& Book::operator=(const Book& other) {
        //call base class operator first
        Publication::operator=(other);
        //handle the additional attributes in the derived class
        if(this != &other) {
            delete[] m_author;
            m_author = nullptr;
            if(other.m_author) {
                m_author = new char[strlen(other.m_author) + 1];
                strcpy(m_author, other.m_author);
            }
        }
        return *this;
    }
}