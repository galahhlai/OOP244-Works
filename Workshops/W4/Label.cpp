/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 4 Part 2
// Name: Hau Hin Lai
// Student ID: 118795228
// Email: hlai23@myseneca.ca
// Section: ZAA
// Date of completion: 9 June 2023

   I have done all the coding by myself and only copied the code that my professor
   provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include "Label.h"
#include "cstring.h"

#define MAX_CONTENT_LENGTH 70

using namespace std;

namespace sdds
{
    Label::Label()
    {
        //set the m_frame to default pattern using strCpy function
        strCpy(m_frame, "+-+|+-+|");
        //default m_content set to null
        m_content = nullptr;
    }
    Label::Label(const char* frameArg)
    {
        //using strCpy function to copy the customized frame pattern to m_frame
        strCpy(m_frame, frameArg);
        //default m_content set to null
        m_content = nullptr;
    }
    Label::Label(const char* frameArg, const char* content)
    {
        //using strCpy function to copy the customized frame pattern to m_frame
        strCpy(m_frame, frameArg);
        //assign dynamic memory for m_content
        m_content = new char[strLen(content) + 1];
        //using strCpy function to copy the content to m_content
        strCpy(m_content, content);
    }
    Label::~Label()
    {
        //delete the dynamic memory allocated to prevent memory leaks
        delete[] m_content;
        //set the class member variables to null
        m_frame[0] = '\0';
        m_content = nullptr;
    }
    void Label::readLabel()
    {
        char content[MAX_CONTENT_LENGTH + 1];
        //receive input of content from standard input, length is 70 - 1 + 1 = 70
        cin.getline(content, MAX_CONTENT_LENGTH + 1);
        //delete dynamic memory allocated
        delete [] m_content;
        //then reassign the dynamic memory for content
        m_content = new char[strLen(content) + 1];
        //using strCpy function to copy the content to m_content
        strCpy(m_content, content);
    }
    ostream& Label::printLabel() const
    {
        //return nothing if no content is provided
        if (m_content == nullptr)
        {
            return cout;
        }
        //first line of sticker
        cout << m_frame[0];
        for (int i = 0; i < strLen(m_content) + 2; i++)
        {
            cout << m_frame[1];
        }
        cout << m_frame[2] << endl;
        //second line of sticker
        cout << m_frame[7];
        for (int i = 0; i < strLen(m_content) + 2; i++)
        {
            cout << ' ';
        }
        cout << m_frame[3] << endl;
        //third line of sticker
        cout << m_frame[7] << ' ' << m_content << ' ' << m_frame[3] << endl;
        //forth line of sticker
        cout << m_frame[7];
        for (int i = 0; i < strLen(m_content) + 2; i++)
        {
            cout << ' ';
        }
        cout << m_frame[3] << endl;
        //fifth line of sticker
        cout << m_frame[6];
        for (int i = 0; i < strLen(m_content) + 2; i++)
        {
            cout << m_frame[5];
        }
        cout << m_frame[4];
        return cout;
    }
}