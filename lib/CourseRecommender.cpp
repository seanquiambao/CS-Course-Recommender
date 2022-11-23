#include <iostream>
#include <vector>
#include <string>
#include <iterator>

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
