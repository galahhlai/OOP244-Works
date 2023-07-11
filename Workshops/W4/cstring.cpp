/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 4 Part 1
// Name: Hau Hin Lai
// Student ID: 118795228
// Email: hlai23@myseneca.ca
// Section: ZAA
// Date of completion: 7 June 2023

   I have done all the coding by myself and only copied the code that my professor
   provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////
***********************************************************************/

#include "cstring.h"

namespace sdds
{
    void strCpy(char* des, const char* src)
    {
        while (*src != '\0')
        {
        *des = *src;
        des++;
        src++;
        }
        *des = '\0';
    }

    void strnCpy(char* des, const char* src, int len)
    {
        int i = 0;
        while (*src != '\0' && i < len)
        {
            *des = *src;
            des++;
            src++;
            i++;
        }
        if (i < len)
        {
            *des = '\0';
        }
    }

    int strCmp(const char* s1, const char* s2)
    {
        while (*s1 == *s2)
        {
            if (*s1 == '\0')
                return 0;
            s1++;
            s2++;
        }
        return *s1 - *s2;
    }

    int strnCmp(const char* s1, const char* s2, int len)
    {
        int i = 0;
        while (*s1 == *s2 && i < len)
        {
            if (*s1 == '\0')
                return 0;
            s1++;
            s2++;
            i++;
        }
        if (i == len)
            return 0;
        return *s1 - *s2;
    }

    int strLen(const char* s)
    {
        int len = 0;
        while (*s != '\0')
        {
            len++;
            s++;
        }
        return len;
    }

    const char* strStr(const char* str1, const char* str2)
    {
        while (*str1 != '\0')
        {
            const char* p1 = str1;
            const char* p2 = str2;
            while (*p1 == *p2 && *p2 != '\0')
            {
                p1++;
                p2++;
            }
            if (*p2 == '\0')
                return str1;
            str1++;
        }
        return nullptr;
    }

    void strCat(char* des, const char* src)
    {
        while (*des != '\0')
        {
            des++;
        }
        while (*src != '\0')
        {
            *des = *src;
            des++;
            src++;
        }
        *des = '\0';
    }
}