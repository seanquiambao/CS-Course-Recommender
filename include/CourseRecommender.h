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
        CourseRecommender();
        void printRec();
        void printEasiestClasses();
        void addRequirement(string requirementName);
        void removeRequirement(string requirementName);
};

#endif
