#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include "../include/CourseRecommender.h"

using namespace std;

//Constructor stores breadth requirements and displays classes
CourseRecommender::CourseRecommender(string user, SQL* db) {
    this->username = user;
    this->classLevel = "FRESHMEN";
    db->fetchTable(this->username);
    if(db->dataTable->isEmpty())
    {
        cout << "Empty!" << endl;
        return;
    }
    int limit = db->dataTable->numResults();
    for (int i = 1; i <= limit; i++) {
        cout << "Pushing" << endl;
        requiredBreadth.push_back(db->dataTable->getData(1, i));
    }
    delete db->dataTable;
}

void CourseRecommender::printRec(SQL* db, string tableName) {
    if(tableName == "Breadth Courses") {
        for(int i = 0; i < this->requiredBreadth.size(); ++i)   // start at 1 since 0 is "breadth"
        {
            printEasiestClasses(db, requiredBreadth[i], tableName);
        }
    }
    else {
        printEasiestClasses(db, classLevel, tableName);
    }
    
}

void CourseRecommender::printEasiestClasses(SQL* db, string course, string tableName) {
    db->easyClass(course, 10, tableName);
    cout << course << endl;
    cout << "=======================" << endl;
    db->dataTable->printTable();
    cout << endl << "=======================" << endl;
    delete db->dataTable;
}

void CourseRecommender::addRequirement(string requirementName, SQL* db) {
    vector<string> column;
    this->requiredBreadth.push_back(requirementName);
    column.push_back(requirementName);
    db->insertTable(column, username);
}

void CourseRecommender::addRequirementPrompt(SQL* db) {
    string breadth;
    while (breadth != "q") {
                cout << "Enter breadth courses not taken yet: ENGL, HUM-A, HUM-B, HUM-C, SS-A, SS-B, SS-C, ETHNICITY, SCI-A, SCI-B (q to finish):" << endl;
        cin >> breadth;
        if (validBreadth(breadth)) {
            if (find(requiredBreadth.begin(), requiredBreadth.end(), breadth) != requiredBreadth.end()) {
            cout << breadth << " is already in the requirements." << endl;
            }
            else {
                addRequirement(breadth, db);
                cout << breadth << " has been added." << endl;
            }
        }
        else {
            cout << breadth << " is not a valid breadth course." << endl;
        }

    }
    cout << "Exiting adding requirements" << endl;
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
    while (breadth != "q") {
        cout << "Enter breadth courses to remove from requirements: ENGL, HUM-A, HUM-B, HUM-C, SS-A, SS-B, SS-C, ETHNICITY, SCI-A, SCI-B (q to finish):" << endl;
        cin >> breadth;
        if (validBreadth(breadth)) {
            if (find(requiredBreadth.begin(), requiredBreadth.end(), breadth) != requiredBreadth.end()) {
                removeRequirement(breadth, db);
                cout << breadth << " has been removed." << endl;
            }
            else {
                cout << breadth << " is not in the requirements." << endl;
            }
        }   
    }
    cout << "Exiting removing requirement" << endl;
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

void CourseRecommender::changeClassLevel() {
    string level;
    cout << "What is your class level, FRESHMEN, SOPHOMORE, JUNIOR, SENIOR? (q to exit): " << endl;
    cin >> level;
    while (level != "q") {
        if (level == "FRESHMEN" || level == "SOPHOMORE" || level == "JUNIOR" || level == "SENIOR"){
            classLevel = level;
            cout << "Class level has been changed to " << level << endl;
            break;
        }
        else {
            cout << "Invalid class level" << endl;
            cout << "What is your class level, FRESHMAN, SOPHOMORE, JUNIOR, SENIOR? (q to exit): " << endl;
            cin >> level;
        }
    }  
    cout << "Exiting changing class level" << endl;
}