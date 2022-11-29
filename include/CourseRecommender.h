// CourseRecommender.h
#include <string>
#include <vector>

#include "SQL.h"

using namespace std;

#ifndef __COURSERECOMMENDER_H__
#define __COURSERECOMMENDER_H__

class CourseRecommender {
    private:
		string username;
		string classLevel;
    vector<string> requiredBreadth;

    public:
        CourseRecommender(string user, SQL* db);
        void printRec(SQL*, string); // Loop through required breadth vector, each elements calls print easiest class.
        /*print breadth courses: courseR->printRec(database, "Breadth Courses");
          print CS courses:      courseR->printRec(database, "Computer Science Courses"); */
        void printEasiestClasses(SQL*, string, string);
        void addRequirement(string requirementName, SQL* db);
        void removeRequirement(string requirementName, SQL* db);
        void addRequirementPrompt(SQL* db); // prompts user to enter breadth requirements
        void removeRequirementPrompt(SQL* db); // prompts user to remove breadth requirements
        bool validBreadth(string); // checks if string is a valid breadth
        void changeClassLevel(); // changes between freshman all the way to senior
        string getClassLevel();

};

#endif
