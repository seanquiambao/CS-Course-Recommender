#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include "../include/CourseRecommender.h"

using namespace std;

//Constructor stores breadth requirements and displays classes

void CourseRecommender::printRec(SQL* db, string tableName) {
    if(tableName == "Breadth Courses") {
        for(int i = 0; i < this->requiredBreadth.size(); ++i)
        {
            printEasiestClasses(db, requiredBreadth[i], tableName);
        }
    }
    else {
        printEasiestClasses(db, "SOPHOMORE", tableName);
    }
    
}

void CourseRecommender::printEasiestClasses(SQL* db, string breadth, string tableName) {

    db->easyClass(breadth, 10, tableName);
    cout << breadth << endl;
    cout << "=======================" << endl;
    db->dataTable->printTable();
    cout << endl << "=======================" << endl;
}

void CourseRecommender::addRequirement(string requirementName) {
    this->requiredBreadth.push_back(requirementName);
}

void CourseRecommender::requirementPrompt() {
    string breadth;
    cout << "Enter breadth courses not taken yet: ENGL, HUM-A, HUM-B, HUM-C, SS-A, SS-B, SS-C, ETHNICITY, SCI-A, SCI-B (q to finish):" << endl;
    cin >> breadth;
    while (breadth != "q") {
        if (validBreadth(breadth)) {
            if (find(requiredBreadth.begin(), requiredBreadth.end(), breadth) != requiredBreadth.end()) {
            cout << breadth << " is already in the requirements." << endl;
            }
            else {
                addRequirement(breadth);
                cout << breadth << " has been added." << endl;
            }
        }
        cout << "Enter breadth courses not taken yet: ENGL, HUM-A, HUM-B, HUM-C, SS-A, SS-B, SS-C, ETHNICITY, SCI-A, SCI-B (q to finish):" << endl;
        cin >> breadth;
    }
    cout << "Exiting..." << endl;
}

bool CourseRecommender::validBreadth(string breadth) {
    if (breadth == "ENGL" || breadth == "HUM-A" || breadth == "HUM-B" || 
        breadth == "HUM-C" || breadth == "SS-A" || breadth == "SS-B" || 
        breadth == "SS-C" || breadth == "ETHNICITY" || breadth == "SCI-A" || 
        breadth == "SCI-B") {
        return true;
    }
    else {
        return false;
    }

}