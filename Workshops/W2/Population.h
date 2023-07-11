#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

namespace sdds
{
    struct Area
    {
        char* postalCode;
        int population;
    };

    void sort(); // sort data
    bool load(Area* area); // load 1 area structure from the file
    bool load(const char* filename); // allocate dynamic memory for loading all the files
    void display(Area* area); // display 1 area structure
    void display(); //display all area structures after sorting
    void deallocateMemory(); // deallocate the dynamic memory

}
#endif // SDDS_POPULATION_H_