/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 1 Part1
// Name: HAU HIN LAI
// SID: 118795228
// Section: ZAA
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/

#ifndef SDDS_SHOPPINGREC_H
#define SDDS_SHOPPINGREC_H

const int MAX_TITLE_LENGTH = 50;

struct ShoppingRec {
    char m_title[MAX_TITLE_LENGTH + 1];
    int m_quantity;
    bool m_bought;
};

namespace sdds {
    ShoppingRec getShoppingRec();
    void displayShoppingRec(const ShoppingRec* shp);
    void toggleBoughtFlag(ShoppingRec* rec);
    bool isShoppingRecEmpty(const ShoppingRec* shp);
}

#endif // !SDDS_SHOPPINGREC_H