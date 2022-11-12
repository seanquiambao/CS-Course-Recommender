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

void CourseRecommender::printRec() {
<<<<<<< HEAD
    
}

void CourseRecommender::printEasiestClasses(string requirementName) {
    
=======
    for (unsigned i = 0; i < this->requiredBreadth.size(); ++i) {
        cout << "Easiest " + this->requiredBreadth.at(i) + "Course: " + getEasiestCourse(requiredBreadth.at(i)) << endl;
    }
}

void CourseRecommender::printEasiestClasses(string requirementName) {
    string poop = getEasiestCourse(requirementName);
>>>>>>> b2779245b6a4f63fffa91aff0caffff723ae3802
}

void CourseRecommender::addRequirement(string requirementName) {
    this->requiredBreadth.push_back(requirementName);
}
