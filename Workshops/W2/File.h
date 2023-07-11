#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
#define DATAFILE "PCpopulation.csv"

namespace sdds {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   bool read(char* postalCode);
   bool read(int* population);
}
#endif // !SDDS_FILE_H_
