#include "../include/UI.h"
#include "../include/CourseRecommender.h"

void UI::menuSystem(string user, SQL* database) {

    cout << endl;
    CourseRecommender courseReco(user, database);
    char choice = '0';

    do {
        menuPrompt();
        cin >> choice;

        switch(choice) {
            case '1':
                //system("CLS") does not work on macOS
                //not sure if system("clear") works on Windows
                cout << endl;

                //problem: stacking printRec() functions on recursive calls, like so, causes weird behavior on output
                //courseReco.printRec(database, "Computer Science Courses");
                //courseReco.printRec(database, "Breadth Courses");

                viewRecCoursesOptions(courseReco, database);
                break;
            case '2':
                cout << endl;
                courseReco.addRequirementPrompt(database);
                break;
            case '3':
                cout << endl;
                courseReco.removeRequirementPrompt(database);
                break;
            case '4':
                cout << endl;
                courseReco.changeClassLevel();
                break;
            case '5':
                cout << endl;
                cout << "Goodbye." << endl;
                break;
            default:
                cout << endl;
                cout << "Please select 1-5" << endl;
                break;
        }

    } while(choice != '5');
}

void UI::menuPrompt() {
    cout << "Main Menu" << endl;
    cout << "1. View Recommended Courses" << endl;
    cout << "2. Add Breadth Requirement" << endl;
    cout << "3. Remove Breadth Requirement" << endl;
    cout << "4. Change Class Level" << endl;
    cout << "5. To Exit" << endl;
    cout << "Please choose: ";
}

void UI::viewRecCoursesOptions(CourseRecommender courseReco, SQL* database) {

    int choice = 0;

    do {

        cout << "1. View " << courseReco.getClassLevel() << " CompSci Courses\n";
        cout << "2. View Breadth Courses\n";
        cout << "3. Return to Main Menu\n";
        cout << "Please choose: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << endl;
                courseReco.printRec(database, "Computer Science Courses");
                break;
            case 2:
                cout << endl;
                courseReco.printRec(database, "Breadth Courses");
                break;
            case 3:
                cout << endl;
                cout << "Returning...\n";
                break;
            default:
                cout << endl;
                cout << "Invalid input.\n";
                break;
        }

    } while(choice != 3);
}