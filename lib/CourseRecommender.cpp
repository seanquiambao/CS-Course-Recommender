#include <iostream>
#include <vector>
#include <string>

#include "../include/CourseRecommender.h"

using namespace std;

void CourseRecommender::printRec() {
    for (unsigned i = 0; i < this->requiredBreadth.size(); ++i) {
        cout << "Easiest " + this->requiredBreadth.at(i) + "Course: " + getEasiestCourse(requiredBreadth.at(i)) << endl;
    }
}

//PrintTopEasiest("ART") -> "DNCD003"
void CourseRecommender::printEasiestClasses(string requirementName) {
    //ECON003
}

void CourseRecommender::addRequirement(string requirementName) {
    this->requiredBreadth.push_back(requirementName);
}
