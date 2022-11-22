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

    courseR->addRequirement("HUM-A");
    courseR->addRequirement("HUM-B");
    courseR->printRec(database);

    login.loginPrompt(database);

    return 0;
}
