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
    
}

void CourseRecommender::printEasiestClasses(string requirementName) {
    
}

void CourseRecommender::addRequirement(string requirementName) {
    this->requiredBreadth.push_back(requirementName);
}
