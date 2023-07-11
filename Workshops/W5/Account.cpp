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

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
   void Account::setEmpty() {
      m_number = -1;
      m_balance = 0.0;
   }
   // New account
   Account::Account() {  
      m_number = 0;
      m_balance = 0.0;
   }
   Account::Account(int number, double balance ) {
      setEmpty();
      if (number >= 10000 && number <= 99999
         && balance > 0) {
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Account::display() const{
      if (*this) {  
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << "  NEW  |         0.00 ";
      }
      else {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }
   //type conversion operators
   Account::operator bool() const
   {
       //5-digit account number and not negative balance
       return (m_number >= 10000 && m_number <= 99999 && m_balance >= 0);
   }
   Account::operator int() const
   {
       //refer to account number
       return m_number;
   }
   Account::operator double() const
   {
       //refer to account balance
       return m_balance;
   }
   //unary member operator
   bool Account::operator~() const
   {
       //account is new only when account number is 0
       return (m_number == 0);
   }
   //binary member operators
   Account& Account::operator=(int number)
   {
       //assign account number only when the current account object is new
       if(m_number == 0)
       {
           //if the account number in parameter is valid
           if(number != -1)
           {
               m_number = number;
           }
           //invalidate the account if the parameter is invalid
           else
           {
               setEmpty();
           }
       }
       return *this;
   }
   Account& Account::operator=(Account& other)
   {
       //if the current account object is new and the account in parameter is valid
       if(~*this && other.m_number != -1)
       {
           //copy the account details from the parameter one
           this->m_number = other.m_number;
           this->m_balance = other.m_balance;
           other.m_number = 0;
           other.m_balance = 0.0;
       }
       return *this;
   }
   Account& Account::operator+=(double amount)
   {
       //the current account object is valid and the amount to be deposited is not negative
       if(this->m_number != -1 && amount >= 0.0)
       {
           this->m_balance += amount;
       }
       return *this;
   }
   Account& Account::operator-=(double amount)
   {
       // the current account object is valid,
       // the amount to be withdrawn cannot be negative or exceed the account balance
       if(this->m_number != -1 && amount >= 0.0 && amount <= this->m_balance)
       {
           this->m_balance -= amount;
       }
       return *this;
   }
   Account& Account::operator<<(Account& other)
   {
       //both the current account object and the account in parameter is valid,
       //they cannot refer to same account
       if(this->m_number != -1 && other.m_number != -1 && this != &other)
       {
           this->m_balance += other.m_balance;
           other.m_balance = 0;
       }
       return *this;
   }
   Account& Account::operator>>(Account& other)
   {
       //both the current account object and the account in parameter is valid,
       //they cannot refer to same account
       if(this->m_number != -1 && other.m_number != -1 && this != &other)
       {
           other.m_balance += this->m_balance;
           this->m_balance = 0;
       }
       return *this;
   }
   //binary helper operators
   double operator+(const Account& a, const Account& b)
   {
       //if both account are valid
       if(a && b)
       {
           return (a.m_balance + b.m_balance);
       }
       else
       {
           //ignore case if one of the accounts is invalid
           return 0.0;
       }
   }
   double operator+=(double& sum, const Account& a)
   {
       //if the account is valid
       if(a)
       {
           sum += a.m_balance;
           return sum;
       }
       else
       {
           //ignore case if one of the accounts is invalid
           return 0.0;
       }
   }
}