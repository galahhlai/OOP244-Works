// Final Project Milestone 3
// Publication Module
// File	Publication.cpp
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
#include "Publication.h"

namespace sdds {
    Publication::Publication(): m_title(nullptr), m_shelfId{'\0'}, m_membership(0), m_libRef(-1), m_date(Date()) {}

    void Publication::set(int member_id) {
        //if it is 5-digit
        if(member_id >= 10000 && member_id < 100000) {
            m_membership = member_id;
        } else {
            //set to 0 if it is not 5-digit
            m_membership = 0;
        }
    }
    void Publication::setRef(int value) {
        m_libRef = value;
    }
    void Publication::resetDate() {
        m_date = Date();
    }
    //if a publication object calls this method, it returns 'P
    char Publication::type() const {
        return 'P';
    }
    bool Publication::onLoan() const {
        if(m_membership != 0) {
            return true;
        }
        return false;
    }
    Date Publication::checkoutDate() const {
        return m_date;
    }
    //if the cstring in parameter is included in the title of the object, return true
    bool Publication::operator==(const char* title) const {
        if(strstr(m_title, title) != nullptr) {
            return true;
        }
        return false;
    }
    Publication::operator const char*() const {
        return m_title;
    }
    int Publication::getRef() const {
        return m_libRef;
    }
    //return true if the address of the io object is either address of cin or cout
    bool Publication::conIO(std::ios& io) const {
        if(&io == &std::cin || &io == &std::cout) {
            return true;
        }
        return false;
    }
    std::ostream& Publication::write(std::ostream& os) const {
        if(conIO(os)) {
            //shelfId
            os << "| " << m_shelfId << " | ";
            //title
            os.width(30);
            os.fill('.');
            os << std::left << m_title;
            os << " | ";
            //shows membership no if it is not 0, or shows " N/A " if it is 0
            if(m_membership != 0) {
                os << m_membership;
            } else {
                os << " N/A ";
            }
            os << " | ";
            //date
            os << m_date << " |";
        } else {
            //display in another format if conIO(os) is not true
            os << type() << '\t' << m_libRef << '\t' << m_shelfId << '\t' << m_title << '\t';
            if(m_membership != 0) {
                os << m_membership;
            } else {
                os << " N/A ";
            }
            os << '\t' << m_date;
        }
        return os;
    }
    std::istream& Publication::read(std::istream& istr) {
        //set all to default
        delete[] m_title;
        m_title = nullptr;
        m_shelfId[0] = '\0';
        m_membership = 0;
        m_libRef = -1;
        m_date = Date();

        //temporary variables set to safe state for storing the input before validation
        char temp_title[SDDS_TITLE_WIDTH + 1] {'\0'};
        char temp_shelfId[SDDS_SHELF_ID_LEN + 1] {'\0'};
        int temp_membership = 0;
        int temp_libRef = 0;
        Date temp_date;

        if(conIO(istr)) {
            std::cout << "Shelf No: ";
            //it reads the istr and store it into m_shelfId
            istr.getline(temp_shelfId, SDDS_SHELF_ID_LEN + 1);
            //if length of temp_shelfId is less than 4, return fail state in istr
            if(std::strlen(temp_shelfId) != SDDS_SHELF_ID_LEN) {
                istr.setstate(std::ios::failbit);
            }
            std::cout << "Title: ";
            //read the istr and store as temp_title
            istr.getline(temp_title, SDDS_TITLE_WIDTH + 1);

            std::cout << "Date: ";
            //read the istr and store as temp_date
            istr >> temp_date;
        } else {
            istr >> temp_libRef;
            //ignore the '\t' character from istr
            istr.ignore(1, '\t');
            //read the istr for 4 characters or until read the delimiter '\t' and store as temp_shelfId, the delimiter will be extracted and discarded
            istr.getline(temp_shelfId, SDDS_SHELF_ID_LEN + 1, '\t');
            //read the istr for 30 characters or until read the delimiter '\t' and store as temp_title, the delimiter will be extracted and discarded
            istr.getline(temp_title, SDDS_TITLE_WIDTH + 1, '\t');

            istr >> temp_membership;
            //ignore the '\t' character from istr
            istr.ignore(1, '\t');
            istr >> temp_date;
            }
        //return fail state for istr if the date is not a valid date
        if(!temp_date) {
            istr.setstate(std::ios::failbit);
        }
        //if istr is not in fail state
        if(!istr.fail()) {
            //copy the title to dynamically allocated m_title from temp
            m_title = new char[std::strlen(temp_title) + 1];
            std::strcpy(m_title, temp_title);
            //copy other attributes from temp
            std::strcpy(m_shelfId, temp_shelfId);
            m_membership = temp_membership;
            m_date = temp_date;
            m_libRef = temp_libRef;
        }
        return istr;
    }
    Publication::operator bool() const {
        if(m_title != nullptr && m_shelfId[0] != '\0') {
            return true;
        }
        return false;
    }
    //rule of three
    Publication::~Publication() {
        delete[] m_title;
    }
    Publication::Publication(const Publication& other) {
        //shallow copy
        m_membership = other.m_membership;
        m_date = other.m_date;
        m_libRef = other.m_libRef;
        std::strcpy(m_shelfId, other.m_shelfId);

        //deep copy
        if(other.m_title != nullptr ) {
            m_title = new char[std::strlen(other.m_title) + 1];
            std::strcpy(m_title, other.m_title);
        }
    }
    Publication& Publication::operator=(const Publication& other) {
        if(this != &other) {
            //shallow copy
            m_membership = other.m_membership;
            m_date = other.m_date;
            m_libRef = other.m_libRef;
            std::strcpy(m_shelfId, other.m_shelfId);

            //deep copy
            if(other.m_title != nullptr) {
                delete[] m_title;
                m_title = new char[std::strlen(other.m_title) + 1];
                std::strcpy(m_title, other.m_title);
            }
        }
        return *this;
    }
}