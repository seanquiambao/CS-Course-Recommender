#include <iostream>
#include <vector>
#include <string>

#include "../include/CourseRecommender.h"

using namespace std;

// class CourseRecommender : public SQL {
//     private:
//         vector<string> requiredBreadth;
//     public:
//         void printRec() {
//             for (unsigned i = 0; i < requiredBreadth.size(); ++i) {
//                 cout << "Easiest " + requiredBreadth.at(i) + "Course: " + getEasiestCouse(requiredBreadth.at(i)) << endl;
//             }
//         }
// }

void CourseRecommender::printRec() {

}

void CourseRecommender::printEasiestClasses() {
    SQL* database = new SQL();

    cout << "Creating tables..." << endl;
    database->_createTable("Breadth Courses");
    database->_createTable("Course Difficulty");
    cout << "Reading Data..." << endl;
    database->readData("../db/breadthCourses.csv", "Breadth Courses");
    database->readData("../db/difficultyDatabase.csv", "Course Difficulty");

    vector<string> classes = database->_easyClass("HUM-B", 10);
    cout << "Easiest Breadth Classes" << endl;
    cout << "=======================" << endl;
    for(int i = 0; i < 3; ++i)
    {
        cout << classes[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < 3; ++i)
    {
        cout << database->_getValue("difficulty", "name", classes[i], "Course Difficulty") << " ";
    }
    cout << endl << "=======================" << endl;
}

void CourseRecommender::addRequirement(string requirementName) {
    this->requiredBreadth.push_back(requirementName);
}
