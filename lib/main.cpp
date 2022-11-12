#include <iostream>
#include <string>

#include "../include/CourseRecommender.h"
#include "../include/SQL.h"
using namespace std;

int main() {
    cout << "Compiled YES" << endl;
    SQL* database = new SQL();

    cout << "Creating tables..." << endl;
    database->_createTable("Breadth Courses");
    database->_createTable("Course Difficulty");
    cout << "Reading Data..." << endl;
    database->readData("../db/breadthCourses.csv", "Breadth Courses");
    database->readData("../db/difficultyDatabase.csv", "Course Difficulty");

    vector<string> classes = database->_easyClass("HUM-B", 10);

    for(int i = 0; i < classes.size(); ++i)
    {
        cout << classes[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < classes.size(); ++i)
    {
        cout << database->_getValue("difficulty", "name", classes[i], "Course Difficulty") << " ";
    }

    return 0;
}