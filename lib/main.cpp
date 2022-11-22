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
    courseR->printEasiestClasses();
    database->_createTable("User Database");
    
    login.loginPrompt(database);

    
    return 0;
}
