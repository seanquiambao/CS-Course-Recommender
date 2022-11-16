#include <iostream>
#include <vector>
#include <string>
#include <iterator>

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

//Constructor stores breadth requirements and displays classes
CourseRecommender::CourseRecommender() {
    //stores all breadth classes in SQL database
    SQL *breadthDatabase = new SQL();
    breadthDatabase->_createTable("Breadth Courses");
    breadthDatabase->_createTable("Course Difficulty");
    breadthDatabase->readData("../db/breadthCourses.csv", "Breadth Courses");
    breadthDatabase->readData("../db/difficultyDatabase.csv", "Course Difficulty");

    //need: to store all breadth classes into requiredBreadth vector
    //need: a SQL function that takes in all classes as a vector

    //problem: easyClass only stores classes with lowest rated difficulty

    //maybe want: a function that creates a vector of classes by requirement (i.e. "HUM-A")
    //other possible solution: concatenate all breadth requirements using easyclass function 
    requiredBreadth = breadthDatabase->_easyClass("HUM-B", 10);

    for(int i = 0; i < requiredBreadth.size(); ++i)
    {
        cout << requiredBreadth[i] << " " << breadthDatabase->_getValue("difficulty", "name", requiredBreadth[i], "Course Difficulty") << endl;
    }
}

void CourseRecommender::printRec() {
    
}

void CourseRecommender::printEasiestClasses(string requirementName) {
    
}

void CourseRecommender::addRequirement(string requirementName) {
    this->requiredBreadth.push_back(requirementName);
}
