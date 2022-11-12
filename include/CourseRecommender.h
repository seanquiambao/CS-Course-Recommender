// CourseRecommender.h
#include <string>
#include <vector>
#include "SQL.h"

using namespace std;

#ifndef __COURSERECOMMENDER_H__
#define __COURSERECOMMENDER_H__

class CourseRecommender : public SQL {
    private:
        vector<string> requiredBreadth;
    public:
        void printRec();
        void printEasiestClasses(string requirementName);
        void addRequirement(string requirementName);
};

#endif
