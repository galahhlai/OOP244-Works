/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 6 Part 1
// Name: Hau Hin Lai
// Student ID: 118795228
// Email: hlai23@myseneca.ca
// Section: ZAA
// Date of completion: 10 July 2023

   I have done all the coding by myself and only copied the code that my professor
   provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include "cstring.h"
using namespace std;
namespace sdds {
    Line::operator const char* () const {
        return m_value;
    }

    Line& Line::operator=(const char* lineContent) {
        //delete the original and assign new dynamic memory
        delete[] m_value;
        m_value = new char[strLen(lineContent) + 1];
        //copy the line content
        strCpy(m_value, lineContent);
        return *this;
    }

    Line::~Line() {
        delete[] m_value;
    }

    Line::Line() {
        m_value = nullptr;
    }

    void TextFile::setEmpty() {
        //deallocate the dynamic memory and set them to nullptr
        delete[] m_textLines;
        m_textLines = nullptr;
        delete[] m_filename;
        m_filename = nullptr;
        m_noOfLines = 0;
    }

    void TextFile::setFilename(const char* fname, bool isCopy) {
        //deallocate the original dynamic memory
        delete[] m_filename;

        if (!isCopy) {
            //if isCopy is false as default, allocate new dynamic memory and copy the filename to it
            m_filename = new char[strLen(fname) + 1];
            strCpy(m_filename, fname);
        } else {
            //if isCopy is true, add "C_" before the name and concatenate them
            m_filename = new char[strLen(fname) + 3];
            strCpy(m_filename, "C_");
            strCat(m_filename, fname);
        }
    }

    void TextFile::setNoOfLines() {
        unsigned i = 0;
        string line;
        ifstream file(m_filename);
        if (file.is_open()) {
            //loop until the file reaches its eof
            while (!file.eof()) {
                //read a line of the content until it reaches '\n'
                getline(file, line);
                //no of lines + 1
                i++;
            }
            file.close();
        }
        if(i == 0) {
            //if no lines counted in a file, set it invalid
            delete[] m_filename;
            m_filename = nullptr;
        }
        //copy the no from count to m_noOfLines
        m_noOfLines = i;
    }

    void TextFile::loadText() {
        if(m_filename != nullptr) {
            //reassignment of dynamic memory
            delete[] m_textLines;
            m_textLines = new Line[m_noOfLines];

            ifstream file(m_filename);
            unsigned i = 0;
            if(file.is_open()) {
                string line;
                //loop while it reads the line from the file
                while(getline(file, line)) {
                    //copy each line to m_textLines[i]
                    m_textLines[i] = line.c_str();
                    i++;
                }
                file.close();
            }
            //update of m_noOfLines
            m_noOfLines = i;
        }
    }

    void TextFile::saveAs(const char *fileName) const {
        ofstream file(fileName);
        if(file.is_open()) {
            //write each line to the new file named fileName
            for(unsigned i = 0; i < m_noOfLines; i++) {
                file << m_textLines[i] << endl;
            }
            file.close();
        }
    }

    TextFile::TextFile(unsigned int pageSize) {
        //set all attributes to nullptr except m_pageSize as initialized
        m_filename = nullptr;
        m_textLines = nullptr;
        m_noOfLines = 0;
        m_pageSize = pageSize;
    }

    TextFile::TextFile(const char* filename, unsigned int pageSize) {
        //same as one-argument constructor
        m_filename = nullptr;
        m_textLines = nullptr;
        m_noOfLines = 0;
        m_pageSize = pageSize;
        //set filename as initialized and read the file with same filename into the object
        if(filename != nullptr) {
            setFilename(filename);
            setNoOfLines();
            loadText();
        }
    }

    TextFile::TextFile(const TextFile& other) {
        //copy constructor
        m_filename = nullptr;
        m_noOfLines = 0;
        m_textLines = nullptr;
        m_pageSize = other.m_pageSize;
        //if the source is valid, copy the filename and content to the object
        if(other) {
            setFilename(other.m_filename, true);
            other.saveAs(m_filename);
            setNoOfLines();
            loadText();
        }
    }

    TextFile& TextFile::operator=(const TextFile& other) {
        //copy assignment operator
        //check for self-assignment
        if(this != &other) {
            //if both source and destination are valid
            if(*this && other) {
                delete[] m_textLines;
                m_textLines = nullptr;
                m_noOfLines = 0;
                m_pageSize = other.m_pageSize;

                other.saveAs(m_filename);
                setNoOfLines();
                loadText();
            }
        }
        return *this;
    }

    TextFile::~TextFile() {
        setEmpty();
    }

    unsigned TextFile::lines() const {
        return m_noOfLines;
    }

    ostream& TextFile::view(ostream& ostr) const {
        if(*this) {
            //display the file name and the '=' under the filename
            ostr << m_filename << endl;
            for (unsigned i = 0; i < strLen(m_filename); i++) {
                ostr << "=";
            }
            ostr << endl;
            ifstream file(m_filename);
            unsigned i = 0;
            if(file.is_open()) {
                string line;
                //loop while it reads every line from the file
                while(getline(file, line)) {
                    //display every line it reads
                    ostr << line.c_str() << endl;
                    i++;
                    //if the no of lines reaches the page size, pause and continue when the cin receives '\n'
                    if(i % m_pageSize == 0) {
                        ostr << "Hit ENTER to continue...";
                        cin.get();
                    }
                }
                file.close();
            }
        }
        return ostr;
    }

    istream& TextFile::getFile(std::istream &istr) {
        string filename;
        //receive input from instream and store the input into filename
        getline(istr, filename);
        //set the filename of the object to what instream received
        setFilename(filename.c_str());
        //open the file with same file name and reads its content
        setNoOfLines();
        loadText();
        return istr;
    }

    const char* TextFile::operator[](unsigned index) const {
        if(*this) {
            //if the index exceeds m_noOfLines, it will loop again starting from 0
            index %= m_noOfLines;
            return m_textLines[index];
        }
        return nullptr;
    }

    TextFile::operator bool() const {
        return (m_filename != nullptr);
    }

    const char* TextFile::name() const {
        return m_filename;
    }

    ostream& operator<<(ostream& ostr, const TextFile& text) {
        text.view(ostr);
        return ostr;
    }

    istream& operator>>(istream& istr, TextFile& text) {
        return text.getFile(istr);
    }
}