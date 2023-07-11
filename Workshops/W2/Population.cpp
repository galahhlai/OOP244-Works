#include <iostream>
#include "cstring.h"  // implemented in workshop 1 part 2 (DIY)
#include "File.h"
#include "Population.h"

using namespace std;
namespace sdds
{
    int noOfAreas;
    Area* area;

    void sort() //sort data
    {
        int i, j;
        Area temp;
        for (i = noOfAreas - 1; i > 0; i--)
        {
            for (j = 0; j < i; j++)
            {
                if(area[j].population > area[j + 1].population)
                {
                    temp = area[j];
                    area[j] = area[j + 1];
                    area[j + 1] = temp;
                }
            }
        }
    }
    bool load(Area* area) // load 1 area structure from the file
    {
        bool flag = false;
        char postal[4];

        if(read(postal) && read(&area->population))
        {
            int length = strLen(postal) + 1;
            area->postalCode = new char[length];
            strCpy(area->postalCode, postal);

            flag = true;
        }
        return flag;
    }
    bool load(const char* filename) // allocate dynamic memory for loading all the files
    {
        bool flag = false;
        int i = 0;
        if(openFile(filename))
        {
            noOfAreas = noOfRecords();
            area = new Area[noOfAreas];

            for(i = 0; i < noOfAreas; i++)
            {
                if(!load(&area[i]))
                    cout << "Error: incorrect number of records read; the data is possibly corrupted!" << endl;
                else
                    flag = true;
            }
            closeFile();
        }
        else
            cout << "Could not open data file: " << filename << endl;
        return flag;
    }
    void display(Area* area) // display 1 area structure
    {
        cout << area->postalCode << ":  " << area->population << endl;
    }
    void display()
    {
        int totalPop = 0;
        cout << "Postal Code: population" << endl;
        cout << "-------------------------" << endl;
        sort();
        for(int i = 0; i < noOfAreas; i++)
        {
            cout << i + 1 << "- ";
            display(&area[i]);
            totalPop += area[i].population;
        }
        cout << "-------------------------" << endl;
        cout << "Population of Canada: " << totalPop << endl;
    }
    void deallocateMemory()
    {
        for(int i = 0; i < noOfAreas; i++)
        {
            delete[] area[i].postalCode;
        }
        delete[] area;
    }
}