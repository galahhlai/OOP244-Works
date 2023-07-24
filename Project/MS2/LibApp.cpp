// Final Project Milestone 2
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
#include "LibApp.h"

namespace sdds {
    bool LibApp::confirm(const char *message) {
        Menu confirm(message);                              //create a menu
        confirm << "Yes";                                   //add a menuitem called "Yes"
        return confirm.run() == 1;                          //if user select "Yes", return true
    }

    void LibApp::load() {
        std::cout << "Loading Data" << std::endl;
    }

    void LibApp::save() {
        std::cout << "Saving Data" << std::endl;
    }

    void LibApp::search() {
        std::cout << "Searching for publication" << std::endl;
    }

    void LibApp::returnPub() {
        search();                                           //call search()
        std::cout << "Returning publication" << std::endl;
        std::cout << "Publication returned" << std::endl;
        m_changed = true;                                   //set m_changed to true
    }

    void LibApp::newPublication() {
        std::cout << "Adding new publication to library" << std::endl;
        if (confirm("Add this publication to library?") == 1) { //call confirm function with the title name and check whether it returns 1
            m_changed = true;                               //set m_changed to true
            std::cout << "Publication added" << std::endl;
        }
    }

    void LibApp::removePublication() {
        std::cout << "Removing publication from library" << std::endl;
        search();
        if (confirm("Remove this publication from the library?") == 1) {    //call confirm function with the title name and check whether it returns 1
            m_changed = true;                               //set m_changed to true
            std::cout << "Publication removed" << std::endl;
        }
    }

    void LibApp::checkOutPub() {
        search();                                           //call search()
        if (confirm("Check out publication?") == 1) {       //call confirm function with the title name and check whether it returns 1
            m_changed = true;                               //set m_changed to true
            std::cout << "Publication checked out" << std::endl;
        }
    }

    LibApp::LibApp() : m_changed(false), m_mainMenu("Seneca Library Application"),  //initialize m_changed to false, the title of m_mainMenu as "Seneca Library Application"
                       m_exitMenu("Changes have been made to the data, what would you like to do?") { //initialize title of m_exitMenu as "Changes have been made to the data, what would you like to do?"
        m_mainMenu << "Add New Publication" << "Remove Publication" << "Checkout publication from library" //add menuitem to m_mainMenu
                   << "Return publication to library";
        m_exitMenu << "Save changes and exit" << "Cancel and go back to the main menu"; //add menuitem to m_exitMenu
        load();                                             //call load()
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
