// CourseRecommender.h
#include <string>
#include <vector>

#include "SQL.h"

using namespace std;

#ifndef __COURSERECOMMENDER_H__
#define __COURSERECOMMENDER_H__

class CourseRecommender {
    private:
        vector<string> requiredBreadth;
    public:
        void printRec(SQL*, string); // Loop through required breadth vector, each elements calls print easiest class.
        void printEasiestClasses(SQL*, string, string);
        void addRequirement(string requirementName);
        void removeRequirement(string requirementName);
};

#endif
