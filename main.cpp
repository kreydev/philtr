#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "trek.h"
#include "attr.h"

int main(int argc, char** argv) {
    if (argc != 2) {std::cerr << "Incorrect number of args." << std::endl; return 1;}

    // TODO: Loading details from file

    std::string datadir = argv[1];

    std::cout << "--------\n Philtr \n--------" << std::endl;

    std::string year;
    std::cout << "Enter year: ";
    std::cin >> year;

    // ask for attribute names
    std::vector<Attr> attrList;
    std::string attrGet;
    while (true) {
        std::cout << "Enter attribute name (s to stop): ";
        std::getline(std::cin, attrGet);
        if (attrGet == "s") {break;}
        attrList.push_back(Attr(attrGet));
    }

    // save attribute names to a file
    std::ofstream attrOut("./" + datadir + "/" + year + "attrs.txt");
    if (!attrOut.is_open()) {std::cerr << "./" + datadir + "/" + year + "attrs.txt is inaccessable."; return 1;}
    for (int i = 0; i < attrList.size(); i++) {
        attrOut << attrList[i].GetName() << std::endl;
    }
    std::cout << "Attribute names saved." << std::endl;
    attrOut.close();

    // ask for activity names
    std::vector<std::string> activList;
    std::string activGet;
    while (true) {
        std::cout << "Enter activity name (s to stop): ";
        std::getline(std::cin, activGet);
        if (activGet == "s") {break;}
        activList.push_back(activGet);
    }

    // save activity names to a file
    std::ofstream activOut("./" + datadir + "/" + year + "activ.txt");
    if (!activOut.is_open()) {std::cerr << "./" + datadir + "/" + year + "activ.txt is inaccessable."; return 1;}
    for (int i = 0; i < activList.size(); i++) {
        activOut << activList[i] << std::endl;
    }
    std::cout << "Activity names saved." << std::endl;
    activOut.close();

    // ask for number of treks
    std::cout << "Number of treks to enter: ";
    int trekc;
    std::cin >> trekc;
    std::vector<Trek> trekList(trekc);

    // ask for trek attrs
    

    // ask for trek activities
    std::cout << "--- Trek Activities ---";
    for (int i = 0; i < trekc; i++) {
        for (int j = 0; j < activList.size(); i++) {
            std::cout << "Has " + activList[j] + " (y/n) ?";
            char yn;
            std::cin >> yn;
            if (yn == 'y') {
                trekList[i].AddActiv(activList[i]);
            }
        }
    }

    // save treks to files


    // narrow search by difficulty


    // narrow search by min/max of each attr


    // narrow search by wanted activities


    // narrow search by not wanted activities


    // save final trek numbers to file


    // output results


    return 0;
}