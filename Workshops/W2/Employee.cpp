#include <iostream>
#include "cstring.h"  // implemented in workshop 1 part 2 (DIY)
#include "Employee.h"
#include "File.h"
using namespace std;
namespace sdds
{
   int noOfEmployees;
   Employee* employees;


   void sort()
   {
      int i, j;
      Employee temp;
      for (i = noOfEmployees - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (employees[j].m_empNo > employees[j + 1].m_empNo) {
               temp = employees[j];
               employees[j] = employees[j + 1];
               employees[j + 1] = temp;
            }
         }
      }
   }
   // reads one employee record from the file and loads it into the employee reference
   // argument
   bool load(Employee* employee)
   {
       bool ok = false;
       char name[128];

       if (read(&employee->m_empNo) && read(&employee->m_salary) && read(name))
       {
           int length = strLen(name) + 1;
           employee->m_name = new char[length];
           strCpy(employee->m_name, name);
           ok = true;
       }
       /* if reading of employee number, salay and name are successful
               allocate memory to the size of the name + 1
               and keep its address in the name of the Employee Reference

               copy the name into the newly allocated memroy

               make sure the "ok" flag is set to true
          end if
       */
       return ok;
   }

   bool load() {
      bool ok = false;
      int i = 0;
      if (openFile(DATAFILE))
      {
          noOfEmployees = noOfRecords();
          employees = new Employee[noOfEmployees];

          for(i = 0; i < noOfEmployees; i++)
          {
              if(!load(&employees[i]))
              {
                  cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
              }
              else
              {
                  ok = true;
              }
          }
          closeFile();
         /* 
          Set the noOfEmployees to the number of recoreds in the file.
          dyanamically allocated an array of employees into the global
          Employee pointer; "employees" to the size of the noOfEmployees.

          In a loop load the employee records from the file into 
          the dynamic array.

          If the number of the records does not match the number of reads
             print the message
            "Error: incorrect number of records read; the data is possibly corrupted"
          Otherwise
             set the ok flag to true
          End if

          close the file
          */
      }
      else
      {
         cout << "Could not open data file: " << DATAFILE<< endl;
      }
      return ok;
   }

   void display(Employee* employee)
   {
        cout << employee->m_empNo << ": " << employee->m_name << ", " << employee->m_salary << endl;
   }

   void display()
   {
       cout << "Employee Salary report, sorted by employee number" << endl;
       cout << "no- Empno, Name, Salary" << endl;
       cout << "------------------------------------------------" << endl;

       sort();

       for (int i = 0; i < noOfEmployees; i++)
       {
           cout << i + 1 << "- ";
           display(&employees[i]);
       }
   }

   void deallocateMemory()
   {
       for(int i = 0; i < noOfEmployees; i++)
       {
           delete[] employees[i].m_name;
       }
       delete[] employees;
   }
}