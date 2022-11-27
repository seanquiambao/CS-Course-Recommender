#include <iostream>
#include <string>

#include "../include/CourseRecommender.h"
#include "../include/SQL.h"
#include "../include/loginSystem.h"
using namespace std;

int main() {
    SQL * database = new SQL();
    loginSystem login;
    string user = login.loginPrompt(database);
    if (user == "") 
        return 0;
    CourseRecommender* courseR = new CourseRecommender(user, database);
    // Example of how to use addRequirement(breadth) & printRec(SQL*, tableName)
    courseR->addRequirementPrompt(database);
    courseR->removeRequirementPrompt(database);
    courseR->printRec(database, "Breadth Courses");

    return 0;   
}
