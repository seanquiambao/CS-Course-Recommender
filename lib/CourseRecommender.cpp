#include <iostream>
#include <vector>
#include <string>
#include <iterator>

#include "../include/CourseRecommender.h"

using namespace std;

//Constructor stores breadth requirements and displays classes

void CourseRecommender::printRec(SQL* db) {
    for(int i = 0; i < this->requiredBreadth.size(); ++i)
    {
        printEasiestClasses(db, requiredBreadth[i]);
    }
}

void CourseRecommender::printEasiestClasses(SQL* db, string breadth) {

    db->easyClass(breadth, 10);
    cout << breadth << endl;
    cout << "=======================" << endl;
    db->dataTable->printTable();
    cout << endl << "=======================" << endl;
}

void CourseRecommender::addRequirement(string requirementName) {
    this->requiredBreadth.push_back(requirementName);
}
