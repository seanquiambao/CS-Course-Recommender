// CourseRecommender.h
#include <string>
#include <vector>
<<<<<<< HEAD


=======
>>>>>>> a691bb97b1777b54d89da1b30d0e332bc8b7e566
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
