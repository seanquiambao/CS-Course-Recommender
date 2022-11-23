#include <iostream>
#include <string>

#include "../include/CourseRecommender.h"
#include "../include/SQL.h"
#include "../include/loginSystem.h"
using namespace std;

int main() {
    SQL * database = new SQL();
    loginSystem login;
    CourseRecommender* courseR = new CourseRecommender();
    string user = login.loginPrompt(database);
    
    // Example of how to use addRequirement(breadth) & printRec(SQL*, tableName)
    courseR->addRequirement("HUM-A");
    courseR->addRequirement("HUM-B");
    courseR->printRec(database, "Computer Science Courses");

    return 0;
}
