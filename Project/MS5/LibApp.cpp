// Final Project Milestone 5
// Menu Module
// File	LibApp.cpp
// Version 1.0
// Student ID: 118795228
// Email: hlai23@myseneca.ca
// Section: ZAA
// =================================================================
// I have done all the coding by myself and only copied the code that my professor
// provided to complete my workshops and assignments.
// =================================================================
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
//
/////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <cstring>
#include "LibApp.h"
#include "PublicationSelector.h"


namespace sdds {
    bool LibApp::confirm(const char *message) {
        Menu confirm(message);                              //create a menu
        confirm << "Yes";                                   //add a menuitem called "Yes"
        return confirm.run() == 1;                          //if user select "Yes", return true
    }
    void LibApp::load() {
        std::cout << "Loading Data" << std::endl;
        std::ifstream fin(m_filename);
        char type {};
        for(int i = 0; fin; i++) {
            fin >> type;
            fin.ignore();
            if(fin) {
                if(type == 'B') {
                    m_ppa[i] = new Book;
                } else if(type == 'P') {
                    m_ppa[i] = new Publication;
                }
                if(m_ppa[i]) {
                    fin >> *m_ppa[i];
                    m_llrn = m_ppa[i]->getRef();
                    m_nolp++;
                }
            }
        }
        fin.close();
    }
    void LibApp::save() {
        std::cout << "Saving Data" << std::endl;
        std::ofstream fout(m_filename);
        for(int i = 0; i < m_nolp; i++) {
            if(m_ppa[i]->getRef() != 0) {
                fout << *m_ppa[i] << std::endl;
            }
        }
        fout.close();
    }
    int LibApp::search(int mode) const {
        //create a publication selector
        PublicationSelector selector("Select one of the following found matches:");
        char type {};
        char title[256] {};
        bool quit = false;
        int pubRef {};
        unsigned selection = m_pubMenu.run();
        if(selection == 1) {
            type = 'B';
        } else if(selection == 2) {
            type = 'P';
        } else if(selection == 0) {
            quit = true;
            std::cout << "Aborted!" << std::endl;
        }
        if(!quit) {
            std::cin.ignore();
            std::cout << "Publication Title: ";
            std::cin.getline(title, 256, '\n');
        }
        if(mode == 1) { //search all items
            for(int i = 0; i < m_nolp; i++) {
                if(m_ppa[i]->getRef() != 0 && m_ppa[i]->type() == type && std::strstr((const char*)*m_ppa[i], title)) {
                    selector << *m_ppa[i];
                }
            }
        } else if(mode == 2) {   //search on loan items
            for(int i = 0; i < m_nolp; i++) {
                if(m_ppa[i]->onLoan() && m_ppa[i]->getRef() != 0 && m_ppa[i]->type() == type && std::strstr((const char*)*m_ppa[i], title)) {
                    selector << *m_ppa[i];
                }
            }
        } else if(mode == 3) {  //search on available items
            for(int i = 0; i < m_nolp; i++) {
                if(!m_ppa[i]->onLoan() && m_ppa[i]->getRef() != 0 && m_ppa[i]->type() == type && std::strstr((const char*)*m_ppa[i], title)) {
                    selector << *m_ppa[i];
                }
            }
        }
        if(selector) {
            selector.sort();
            pubRef = selector.run();   //selector returns the libRef of selected publication or return 0 if exit
            if(pubRef != 0) {   //if not exit return the publication
                std::cout << *getPub(pubRef) << std::endl;
            } else {    //if exit manually pubRef = 0
                std::cout << "Aborted!" << std::endl;
            }
        } else {    //if !selector no results found
            std::cout << "No matches found!" << std::endl;
        }
        return pubRef;
    }
    Publication* LibApp::getPub(int libRef) const {
        Publication* result{};
        for(int i = 0; i < m_nolp && result == nullptr; i++) {
            if(m_ppa[i]->getRef() == libRef) {
                result = m_ppa[i];
            }
        }
        return result;
    }
    void LibApp::returnPub() {
        int pubRef {};
        std::cout << "Return publication to the library" << std::endl;
        pubRef = search(2); //search on loan items
        if(pubRef != 0){
            if(confirm("Return Publication?")) {
                Date currentDate;
                if(currentDate - getPub(pubRef)->checkoutDate() > SDDS_MAX_LOAN_DAYS) {
                    std::cout << "Please pay $";
                    fixed(std::cout);
                    std::cout.precision(2);
                    std::cout << (double)(currentDate - getPub(pubRef)->checkoutDate() - SDDS_MAX_LOAN_DAYS) * 0.5;
                    std::cout << " penalty for being " << (currentDate - getPub(pubRef)->checkoutDate() - SDDS_MAX_LOAN_DAYS) << " days late!" << std::endl;
                }
                getPub(pubRef)->set(0);
                m_changed = true;
                std::cout << "Publication returned" << std::endl;
            } else {
                std::cout << "Aborted!" << std::endl;
            }
        }
    }
    void LibApp::newPublication() {
        if(m_nolp == SDDS_LIBRARY_CAPACITY){
            std::cout << "Library is at its maximum capacity!" << std::endl;
        } else {
            std::cout << "Adding new publication to the library" << std::endl;
            Publication* newPublication {};
            unsigned selection = m_pubMenu.run();
            if(selection == 1) {
                newPublication = new Book;
            } else if(selection == 2) {
                newPublication = new Publication;
            } else if(selection == 0) {
                std::cout << "Aborted!" << std::endl;
            }
            std::cin.ignore(1000, '\n');
            //read from cin
            if(newPublication) {
                newPublication->read(std::cin);
                if(!std::cin.fail()) {
                    if(confirm("Add this publication to the library?") == 1) {  //call confirm() to check if the user has confirmed
                        if(*newPublication) {
                            m_llrn++;
                            m_ppa[m_nolp] = newPublication;
                            m_ppa[m_nolp]->setRef(m_llrn);
                            m_nolp++;
                            m_changed = true;
                            std::cout << "Publication added" << std::endl;
                        } else {
                            delete newPublication;
                            std::cout << "Failed to add publication!" << std::endl;
                        }
                    } else {
                        delete newPublication;
                        std::cout << "Aborted!" << std::endl;
                    }
                } else {
                    delete newPublication;
                    std::cin.ignore(1000, '\n');
                    std::cin.clear();
                    std::cout << "Aborted!" << std::endl;
                }
            }
        }
    }
    void LibApp::removePublication() {
        int pubRef {};
        std::cout << "Removing publication from the library" << std::endl;
        pubRef = search(1);  //search all publications
        if(pubRef != 0) {
            if (confirm("Remove this publication from the library?") == 1) {    //call confirm() to check if the user has confirmed
                getPub(pubRef)->setRef(0);
                m_changed = true;
                std::cout << "Publication removed" << std::endl;
            } else {
                std::cout << "Aborted!" << std::endl;
            }
        }
    }
    void LibApp::checkOutPub() {
        int pubRef {};
        int memNo {};
        bool validNo = false;
        std::cout << "Checkout publication from the library" << std::endl;
        pubRef = search(3);  //search available items
        if (pubRef != 0) {
            if (confirm("Check out publication?") == 1) {   //call confirm() to check if the user has confirmed
                std::cout << "Enter Membership number: ";
                while (!validNo) {
                    std::cin >> memNo;
                    if (!std::cin.fail()) {
                        if (memNo >= 10000 && memNo <= 99999) {
                            validNo = true;
                        } else {
                            memNo = 0;
                            std::cout << "Invalid membership number, try again: ";
                        }
                    } else {
                        std::cin.ignore(1000, '\n');
                        std::cin.clear();
                        std::cout << "Invalid membership number, try again: ";
                    }
                }
                getPub(pubRef)->set(memNo);
                m_changed = true;
                std::cout << "Publication checked out" << std::endl;
            } else {
                std::cout << "Aborted!" << std::endl;
            }
        }
    }
    LibApp::LibApp(const char* filename) : m_filename{}, m_changed(false), m_mainMenu("Seneca Library Application"),  //initialize m_changed to false, the title of m_mainMenu as "Seneca Library Application"
                       m_exitMenu("Changes have been made to the data, what would you like to do?"),    //initialize title of m_exitMenu as "Changes have been made to the data, what would you like to do?"
                       m_pubMenu("Choose the type of publication:") {    //initialize title of m_pubMenu as "Choose the type of publication:"
        m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" //add menuitem to m_mainMenu
                   << "Return publication to library";
        m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu"; //add menuitem to m_exitMenu
        m_pubMenu << "Book" << "Publication";   //add menuitem to m_pubMenu
        if(filename) {
            strcpy(m_filename, filename);
        }
        load(); //call load()
    }
    LibApp::~LibApp() {
        for(int i = 0; i < m_nolp; i++) {
            delete m_ppa[i];
        }
    }

    void LibApp::run() {
        bool done = false;
        while (!done) {                                     //if done is false, loop the following; as done is initialize as false, it will loop at least one time
            unsigned selection = m_mainMenu.run();          //call the run() for m_mainMenu and store the return into selection
            if(selection == 1) {                            //start checking the return value to call respective functions
                newPublication();
                std::cout << std::endl;
            } else if(selection == 2) {
                removePublication();
                std::cout << std::endl;
            } else if(selection == 3) {
                checkOutPub();
                std::cout << std::endl;
            } else if(selection == 4) {
                returnPub();
                std::cout << std::endl;
            } else if(selection == 0) {
                if(m_changed) {                             //if user choose exit from the menu, check whether m_changed is set to true
                    unsigned exit = m_exitMenu.run();       //if m_changed is true, call run() for m_exitMenu and store the return into exit
                    if(exit == 1) {                         //start checking the return value to have respective actions
                        save();                             //call save()
                        done = true;                        //set done to true to leave the loop
                        std::cout << std::endl;
                        std::cout << "-------------------------------------------" << std::endl;
                        std::cout << "Thanks for using Seneca Library Application" << std::endl;
                    } else if(exit == 0) {
                        if (confirm("This will discard all the changes are you sure?")) {
                            done = true;                    //set done to true to leave the loop
                            std::cout << std::endl;
                            std::cout << "-------------------------------------------" << std::endl;
                            std::cout << "Thanks for using Seneca Library Application" << std::endl;
                        }
                    } else if(exit == 2) {
                        std::cout << std::endl;
                    }
                } else {
                    done = true;                            //set done to true to leave the loop
                    std::cout << std::endl;
                    std::cout << "-------------------------------------------" << std::endl;
                    std::cout << "Thanks for using Seneca Library Application" << std::endl;
                }
            }
        }
    }
}
