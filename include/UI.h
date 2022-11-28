#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <string>

#include "../include/SQL.h"
#include "../include/CourseRecommender.h"

using namespace std;

#ifndef __UI_H__
#define __UI_H__

class UI {
    public: 
        void menuSystem(string, SQL*);
        void menuPrompt();
        void viewRecCourses(CourseRecommender, SQL*);
        // void addBreadthCourses();
        // void removeBreadthCourses();
        // void changeClassLevel();
};

#endif
