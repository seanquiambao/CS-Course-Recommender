[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=8862854&assignment_repo_type=AssignmentRepo)

# Computer Science Course Recommender
 
 > Authors: [Nathan Chan](https://github.com/nchannoob), [Jeric Pascua](https://github.com/jericj), [Sean Quiambao](https://github.com/toastmeal), [Zachary Ta](https://github.com/ZacharyTa)

## Project Description
### Importance of the Project
 > This project is important to us since we wanted a more efficient and easier way to plan out our courses. We wanted to create a program that recommends engineering courses to take for each quarter depending on how difficult the class is (based from the UCR difficulty database spreadsheet). This program can allow us to even out our workload throughout the school year and help us take less strenuous classes.
### Planned Technologies
 > We plan to use the following technologies in this class:
 > * **Vim** - A text editor used to create files and edit code for our project
 > * **Visual** Studio Code - A source-code editor used to create files and write code for our program and is also used as a visual debugging tool.
 > * **Git** - A local-based version control system used to keep track of changes made by the contributors of the repository. We will use GitHub as our cloud-based to push any changes into our repository.
 > * **C++** - A programming language used to code our project.
 > * **GDB (GNU Debugger)** - A dynamic debugger tool used to identify issues within our program. This is used to detect bugs in our C++ code.
 > * **Valgrind** - An instrumentation framework used to check for memory management and threading bugs. This is used to detect memory leaks and dangling pointers within our program.
 > * **SQL & SQLite3** - SQL is a standard language responsible for accessing and manipulating database. We will use SQLite3 to write C++ to execute SQL commands to communicate the database.
### Input/Output
 > **Input** - The user can input the courses they have already taken, this can be inputted through either a .txt file or an Excel file. This input will be used to calculate the amount of credits taken, which can be used to calculate the amount of credits required. This will also be used as a prerequisite checklist for specific computer science courses. The user can also input classes into their planner, if they meet the required prerequisite.<br>
 > **Output** - The program will output a list of engineering courses, ordered from the least to most difficult. It will only output the courses that the user needs, and will only show the courses that meet the user’s prerequisites requirements. The program will also output the planner the user has created, which will output the average difficulty and the amount of units for that planned quarter.
### Features
 > * The user can create a planner for each quarter. The user is allowed to add or remove courses from the planner. When adding courses, the program will sum up all the units. The program will also show the average difficulty so that the user can see the amount of workload they have. This average difficulty is calculated based on the UCR difficulty database. This program can also calculate the expected graduation date.
 > * The user can search up the courses. The search bar will be divided whether the course is a lower division course, upper division course, or elective course. The program will also show some breadth courses for each area of study (we will focus on the three most popular breadth courses for each area of study). The user can select a course in the view finder, which will display the courses prerequisite, amount of units, and difficulty.

## Class Diagrams (First Sprint)
![UML Class Diagram](https://github.com/cs100/final-project-squia003-zta002-jpasc029-nchan089/blob/master/images/firstSprintUMLDiagram.png)
### SQL Class
 > SQL class is instantiated as a pointer object. This class is responsible for creating tables, inserting/reading data, and fetching query results of the SQL commands. 
 > * db is a sqlite3 pointer responsible for handling certain sqlite3 commands.
 > * zErrMsg stores the error message whenever db encounters any errors querying the SQL commands.
 > * rc essentially stores query results (returns an error code if db encounters an error).
 > * _createTable() creates a table using the CREATE SQL command and executing the instruction using rc and sqlite_exec function 
 > * readData() reads data from the two CSV files, which uses. It uses a the file stream library to read the CSV files.
 > * _insertTable takes in a vector of strings (data for each column in the table), and a string variable (tableName) and inserts each data into the table.
 > * _showErrMsg outputs an errMsg whenever the sqlite3 encounters an error. 
 > * _getValue() is a function that returns the data from the table in the database. IT takes in four strings, one selection column, one comparison column, the data to search in the comparison column, and the table name.
 > * _easyClass() is a function that returns a vector of strings (class names) according to the user's breadth requirements. It should take in the requirementName (eg. HUM-B, SS-A), and the tableName.
### Course Recommender and LoginPrompt
 > Both CourseRecommender and LoginPrompt uses the SQL class to execute certain SQL commands. Both of their relationships are aggregation because they can stand alone whenever SQL pointer class is deleted (though they render useless). The two classes also uses the DataTable class to retrieve query results. We will discuss about the DataTable class later.
#### Course Recommender
 > Course Recommender stores a vector of strings that stores the user's breadth requirements. 
 > * printEasiestClass() will output the top three easiest classes for each breadth requirements stored. The addRequirement function requests user input to add a breadth requirement. printHardestClass() lists the hardest class instead of the easiest. They are functionally the same.
 > * addRequirement() requires the user's input to add any breadth requirements (e.g. HUM-B, SS-A...)
 #### LoginSystem
 > loginSystem is responsible for handling user database.
 > * It will execute the loginPrompt() to ask for user input. 
 > * If the username is not in the dataase the program will ask the user to register and execute  registerUser() if they agree. 
 > * It uses the isRegistered() function to check if the user is already added the database.
 > * If the user does exist in the database, the user can input a password. The program uses isUser() to check if the user's password is typed in correctly.
 ### DataTable Struct
 > As previously mentioned, DataTable is a struct class that fetches query results based on the Course Difficulty Database. It's relation to the SQL class is composition, because if SQL is deleted, DataTable's query results will also be deleted. 
 > * When the SQL class executes fetchData(), the DataTable class will fetch the results of the SQL query command.
 > * Using the query results, we can select the data we want to return to the user using getData(). 
 > * isEmpty() checks whether the query result returns an empty table. 
 > * printTable() is prints the table of the query results. It is mostly used for debugging purposes.
 ### Second UML Diagram


 
 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on week 8 during lab time.
 > * Before the meeting you should perform a sprint plan like you did in Phase I.
 > * You should also make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
> 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
