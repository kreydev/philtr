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
    std::vector<std::string> attrList;
    std::string attrGet;
    std::cout << std::endl;
    std::cin.clear();
    while (true) {
        std::cout << "Enter attribute name (s to stop): ";
        std::getline(std::cin, attrGet);
        if (attrGet == "s") {break;}
        attrList.push_back(attrGet);
    }

    // save attribute names to a file
    std::ofstream attrOut("./" + datadir + "/" + year + "attrs.txt");
    if (!attrOut.is_open()) {std::cerr << "./" + datadir + "/" + year + "attrs.txt is inaccessable."; return 1;}
    for (int i = 0; i < attrList.size(); i++) {
        attrOut << attrList[i] << std::endl;
    }
    std::cout << "Attribute names saved." << std::endl;
    attrOut.close();

    // ask for activity names
    std::vector<std::string> activList;
    std::string activGet;
    std::cout << std::endl;
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
    std::vector<Trek> trekList;
    std::ofstream numFile("./" + datadir + "/" + year + "num.txt");
    if (!numFile.is_open()) {std::cerr << "./" + datadir + "/" + year + "num.txt is inaccessable."; return 1;}
    numFile << trekc;
    numFile.close();

    // ask for trek details
    std::cout << "--- Trek Details ---" << std::endl;
    for (int i = 0; i < trekc; i++) {
        std::string diff;
        std::cout << "Difficulty of Trek " << i+1 << ": ";
        std::cin >> diff;
        std::cout << std::endl;
        trekList.push_back(Trek(i+1));
        for (int j = 0; j < attrList.size(); j++) {
            std::cout << "Trek " << i+1 << " value of " + attrList[j] + ": ";
            int attrVal;
            std::cin >> attrVal;
            trekList.back().AddAttr(Attr(attrList[j], attrVal));
        }
        for (int j = 0; j < activList.size(); j++) {
            std::cout << "Trek " << i+1 << ": has " + activList[j] + " (y/n)? ";
            char yn;
            std::cin >> yn;
            if (yn == 'y') {
                trekList.back().AddActiv(activList[j]);
            }
        }
    }

    // ask for trek activities
    //std::cout << "--- Trek Activities ---" << std::endl;
    //for (int i = 0; i < trekc; i++) {
    //    trekList.push_back(Trek(i+1));
    //    for (int j = 0; j < activList.size(); j++) {
    //        std::cout << "Trek " << i+1 << ": has " + activList[j] + " (y/n)? ";
    //        char yn;
    //        std::cin >> yn;
    //        if (yn == 'y') {
    //            trekList.back().AddActiv(activList[j]);
    //        }
    //    }
    //}

    // save treks to files


    // narrow search by difficulty


    // narrow search by min/max of each attr


    // narrow search by wanted activities


    // narrow search by not wanted activities


    // save final trek numbers to file


    // output results


    return 0;
}
