/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 5 Part 1
// Name: Hau Hin Lai
// Student ID: 118795228
// Email: hlai23@myseneca.ca
// Section: ZAA
// Date of completion: 13 June 2023

   I have done all the coding by myself and only copied the code that my professor
   provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();

   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;
      //type conversion operator prototypes
      operator bool() const;
      operator int() const;
      operator double() const;
      //unary member operator prototype
      bool operator ~() const;
      //binary member operator prototypes
      Account& operator=(int number);
      Account& operator=(Account& other);
      Account& operator+=(double amount);
      Account& operator-=(double amount);
      Account& operator<<(Account& other);
      Account& operator>>(Account& other);
      //binary helper operator prototypes
      friend double operator+(const Account& a, const Account& b);
      friend double operator+=(double& sum, const Account& a);
   };
}
#endif // SDDS_ACCOUNT_H_