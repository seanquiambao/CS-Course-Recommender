#include <iostream>
#include <string>

#include "../include/CourseRecommender.h"
#include "../include/SQL.h"
#include "../include/loginSystem.h"
#include "../include/UI.h"
using namespace std;

int main() {
    SQL * database = new SQL();
    loginSystem login;
    string user = login.loginPrompt(database);
    if (user == "") 
        return 0;
    
    UI ui;
    ui.menuSystem(user, database);

    delete database;
    return 0;   
}
