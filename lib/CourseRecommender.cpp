#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include "../include/CourseRecommender.h"

using namespace std;

//Constructor stores breadth requirements and displays classes
CourseRecommender::CourseRecommender(string user, SQL* db) {
    int limit = db->get_nRow();
    username = user;
    db->fetchTable(user);
    for (int i = 0; i < limit; i++) {
        requiredBreadth.push_back(db->dataTable->getData(1, i));
    }
}

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

void CourseRecommender::addRequirement(string requirementName, SQL* db) {
    this->requiredBreadth.push_back(requirementName);
    db->insertTable(requiredBreadth, username);
}

void CourseRecommender::addRequirementPrompt(SQL* db) {
    string breadth;
    cout << "Enter breadth courses not taken yet: ENGL, HUM-A, HUM-B, HUM-C, SS-A, SS-B, SS-C, ETHNICITY, SCI-A, SCI-B (q to finish):" << endl;
    cin >> breadth;
    while (breadth != "q") {
        if (validBreadth(breadth)) {
            if (find(requiredBreadth.begin(), requiredBreadth.end(), breadth) != requiredBreadth.end()) {
            cout << breadth << " is already in the requirements." << endl;
            }
            else {
                addRequirement(breadth, db);
                cout << breadth << " has been added." << endl;
            }
        }
        cout << "Enter breadth courses not taken yet: ENGL, HUM-A, HUM-B, HUM-C, SS-A, SS-B, SS-C, ETHNICITY, SCI-A, SCI-B (q to finish):" << endl;
        cin >> breadth;
    }
    cout << "Exiting..." << endl;
}

void CourseRecommender::removeRequirement(string requirementName, SQL* db) {
    vector<string>::iterator it = find(requiredBreadth.begin(), requiredBreadth.end(), requirementName);
    if (it != requiredBreadth.end()) {
        requiredBreadth.erase(it);
        db->deleteDataFromTable(username, "breadth", requirementName);
    }
    else {
        cout << requirementName << " is not in the requirements.";
    }
}

void CourseRecommender::removeRequirementPrompt(SQL* db) {
    string breadth;
    cout << "Enter breadth courses to remove from requirements: ENGL, HUM-A, HUM-B, HUM-C, SS-A, SS-B, SS-C, ETHNICITY, SCI-A, SCI-B (q to finish):" << endl;
    cin >> breadth;
    while (breadth != "q") {
        if (validBreadth(breadth)) {
            if (find(requiredBreadth.begin(), requiredBreadth.end(), breadth) != requiredBreadth.end()) {
                removeRequirement(breadth, db);
                cout << breadth << " has been removed." << endl;
            }
            else {
                cout << breadth << " is not in the requirements." << endl;
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