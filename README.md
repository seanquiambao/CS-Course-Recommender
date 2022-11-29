[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=8862854&assignment_repo_type=AssignmentRepo)

# Computer Science Course Recommender
 
 > Authors: [Nathan Chan](https://github.com/nchannoob), [Jeric Pascua](https://github.com/jericj), [Sean Quiambao](https://github.com/toastmeal), [Zachary Ta](https://github.com/ZacharyTa)

## Project Description
### Importance of the Project
 This project is important to us since we wanted a more efficient and easier way to plan out our courses. We wanted to create a program that recommends engineering and breadth courses to take for each quarter depending on how difficult the class is (based from the UCR difficulty database spreadsheet). This program can allow us to even out our workload throughout the school year and help us take less strenuous classes.
### Planned Technologies
 We plan to use the following technologies in this class:
 > * **Vim** - A text editor used to create files and edit code for our project
 > * **Visual** Studio Code - A source-code editor used to create files and write code for our program and is also used as a visual debugging tool.
 > * **Git** - A local-based version control system used to keep track of changes made by the contributors of the repository. We will use GitHub as our cloud-based to push any changes into our repository.
 > * **C++** - A programming language used to code our project.
 > * **GDB (GNU Debugger)** - A dynamic debugger tool used to identify issues within our program. This is used to detect bugs in our C++ code.
 > * **Valgrind** - An instrumentation framework used to check for memory management and threading bugs. This is used to detect memory leaks and dangling pointers within our program.
 > * **SQL & SQLite3** - SQL is a standard language responsible for accessing and manipulating database. We will use SQLite3 to write C++ to execute SQL commands to communicate the database.
### Input/Output
 **Input** - The user can input the breadth requirements they need to fulfill. The user can also input their login information (username and password) in order for the program to store and remember their data. The user can also change their class level (whether they are FRESHMEN, SOPHOMORE, etc).<br>
 **Output** - The program will output a list of engineering courses, ordered from the least to most difficult. It will only output depending on the user's class level. The program will also output a list of breadth courses based on what breadth requirements the user has selected.
### Features
 * The user can store their required breadth courses (we will focus on the three most popular breadth courses for each area of study). The user is allowed to select what breadth requirements that they need to fulfill (HUM-A, SS-A, ..., etc). The program will show the top 10 easiest classes (some rankings are limited to smaller numbers due to data limitations) for each breadth courses.
 * The program will include a login system for the user to remember their breadth requirements. The student can register their login information. When the user exits the program, the program will remember the breadth requirements that the user selected.
 * The program will also show a list of the top 10 easiest computer science courses based on UC Riverside BCOE's Computer Science Course plan. The user can select their class level and the program will recommend some lower and upper division CS courses.
## Class Diagram
![UML Class Diagram](https://github.com/cs100/final-project-squia003-zta002-jpasc029-nchan089/blob/master/images/finalUMLDiagram.png)
### SQL Class
 > SQL class is instantiated as a pointer object. This class is responsible for creating tables, inserting/reading data, and fetching query results of the SQL commands. 
 * db is a sqlite3 pointer responsible for handling certain sqlite3 commands.
 * zErrMsg stores the error message whenever db encounters any errors querying the SQL commands.
 * rc essentially stores query results (returns an error code if db encounters an error).
 * dataTable stores the databases queried table. It is used whenever `_fetchSQL()` executes, and used whenever the program needs to access the queried data table.
 * _showErrMsg outputs an errMsg whenever the sqlite3 encounters an error. It requires a `db` in order to retrieve the error message.
 * _createTable() creates a table using the CREATE SQL command and executing the instruction using rc and sqlite_exec function 
 * _readData() reads data from the three `.csv` files, which uses. It uses a the file stream library to read the CSV files.
 * _fetchSQL() fetches the an SQL statement and instantiates a table based on the queried SQL statement. It requires an SQL statement to fetch a queried table result.
 * _executeSQL() executes any SQL statements. This functions similarly to _fetchSQL(), however this is typically used for inserting, deleting or creating tables. This is not used for querying a table.
 * SQL() is a constructor responsible for opening the database, creating tables, reading the `.csv` files and writing the data into the tables.
 * ~SQL() responsible for closing the sqlite3 database and setting `zErrMsg` to null.
 * fetchTable() fetches and retrieves the whole table from the database. It uses a one of the table's name in order to fetch the table from the database.
 * easyClass() is a function that returns a vector of strings (class names) according to the user's breadth requirements. It should take in the requirementName (eg. HUM-B, SS-A), and the tableName.
 * insertTable() takes in a vector of strings (data for each column in the table), and a string variable (tableName) and inserts each data into the table.
 * deleteDataFromTable() removes selected data from the table. It requires a table name, column name, and a data from that column. All three parameters are passed as strings.
 * getValue() is a function that returns the data from the table in the database. IT takes in four strings, one selection column, one comparison column, the data to search in the comparison column, and the table name.
 * createUserTable() creates a table whenever a student registers into the database. It requires a username, which will be used as the "table name" to store user data.
 * getRC() returns the result code `rc`. This is mostly used for testing and debugging purposes.
 
### Course Recommender and LoginSystem
  > Both CourseRecommender and LoginSystem uses the SQL class to execute certain SQL commands. Both have an aggregation relationship with the SQL class because when the SQL class deletes, the CourseRecommender and loginSystem can still exist. The two classes also uses the DataTable class to retrieve query results. 
  > Likewise with the SQL class, both of them have an aggregation relationship with the DataTable class.
  > The CourseRecommender and loginSystem both have a simple association for the reason that the loginPrompt returns a string that the CourseReccommender will use to fetch the user's data.
#### Course Recommender
 > Course Recommender stores a vector of strings that stores the user's breadth requirements.
 * username stores the student's username when they logged in. This will allow the program to store breadth requirement data in the `User Table` table.
 * classLevel stores the user's class level.
 * requiredBreadth stores the breadth requirements of the user.
 * CourseRecommender() constructs and loads in the user's log in information. It requires an SQL* and the username in order to store user data.
 * printRec() prints the recommended classes. It requires a string which differentiates whether the user wants to print breadth courses or CS courses.
 * printEasiestClass() will output the top three easiest classes for each breadth requirements stored. The addRequirement function requests user input to add a breadth requirement.
 * addRequirement() requires the user's input to add any breadth requirements (e.g. HUM-B, SS-A...). It uses the SQL database in order for the program to remember the student's updated breadth requirements.
 * removeRequirement() allows the user to remove a breadth requirement. It uses the SQL database in order for the program to remember the student's updated breadth requirements.
 * addRequirementPrompt() and removeRequirementPrompt() are just UI classes that take the user's input.
 * validBreadth() determines whether the user's input is an actual breadth requirement.
 * changeClassLevel() allows the user to change their classLevel.
 * getClassLevel() returns the user's class level.
 
 
 #### LoginSystem
 > loginSystem is responsible for handling user database.
 * loginPrompt() is a UI function designed to take in user input.
 * The program will check first if the user is registered using the isRegistered() function. This requires an SQL* pointer and string to access and find the database.
 * If the username is found in the database, then the program will ask if the user wants to register using the registerUser() function.
 * If the user does exist in the database, the user can input a password. The program uses isUser() to check if the user's password is typed in correctly. It also uses the SQL* database to access the database.
 
 
 ### DataTable Struct
 > As previously mentioned, DataTable is a struct class that fetches query results based on the Course Difficulty Database. It's relation to the SQL class is composition, because if SQL is deleted, DataTable's query results will also be deleted. 
  * When the SQL class executes fetchData(), the DataTable class will fetch the results of the SQL query command. DataTable() will construct the queried result based on the SQL statement given.
  * ~DataTable() deallocates any instantiated DataTable.
  * getData() allows the program to retrieve a data element from the queried table. It uses int values to select what row and columns to select and return the data.
 * isEmpty() checks whether the query result returns an empty table. 
 * printTable() is prints the table of the query results. It is mostly used for debugging purposes.
 * numResults() is used to determined the number of rows of the queried table.
 
 ### UI
 > The UI class is used as a menu system for the program. It has a simple association with the Course Recommender class because the UI class calls the Course Recommender functions.
 * menuPrompt() outputs a list of options on whether the user wants to view recommended courses or add breadth requirements.
 * menuSystem() takes in the user inputs and calls the appropriate Course Recommender functions
 * viewCourseOptions() is a sub-menu prompting the user if they want to see recommended CS courses or breadth courses.

 
 ## Screenshots
 ### Input
 ![Input of program](https://github.com/cs100/final-project-squia003-zta002-jpasc029-nchan089/blob/master/images/io_01.png)

 ### Output
 ![Input and output of program](https://github.com/cs100/final-project-squia003-zta002-jpasc029-nchan089/blob/master/images/io_02.png)
 
 ![Output of program](https://github.com/cs100/final-project-squia003-zta002-jpasc029-nchan089/blob/master/images/io_03.png)
 
 ## Installation/Usage
 Please note that the project will not run on the SSH server. The program uses sqlite3, which requires the sqlite library. With the limitations of the SSH server, it is not possible to retrieve the sqlite library without administration priveleges. Without the sqlite library, the program will not compile properly. This means that you have to clone the project outside the SSH server.
 
 First clone the repository and cd into it:
 
    $ git clone --recursive https://github.com/cs100/final-project-squia003-zta002-jpasc029-nchan089.git
    $ cd final-project-squia003-zta002-jpasc029-nchan089
 
 To properly compile the code, there are a few things to install:
 > * CMake
 > * Make
 > * gcc
 
 There are different ways to install the compilers and build automators depending on the operating system you are using:
 
 ### Windows Compiling
 You need to use MinGW in order to install the compilers and build automators. There is a tutorial on [VSCode](https://code.visualstudio.com/docs/cpp/config-mingw) that can assist with the installing compilers and build automators.

Execute cmake and make. The CMake file will create a build directory for you. You do not need to create a build directory.

    $ cmake -G "MinGW Makefiles" .
    $ mingw32-make
 ### macOS Compiling 
 The program requires that you use CMake and Make. For ARM silicon processor (M1 Chip), you need to install [Rosetta2](https://osxdaily.com/2020/12/04/how-install-rosetta-2-apple-silicon-mac/) first before installing Homebrew.

For all macOSes, you need to install [Homebrew](https://brew.sh/) in order to install CMake and Make.

After installing, run the following commands:

	% cmake .
	% make 

 ### Linux Compiling
 The program requires CMake to compile. After installing CMake first run the following commands

    $ cmake .
    $ make
    
After compiling all of the projects, `cd` into build and run the program

    $ cd build
    $ ./CSCourseRecommender

 ## Testing

 After compiling the projects, there should be two executables in build. All of the unit testing are done using [googletest](https://github.com/google/googletest) as our testing framework. The unit tests was designed to check whether SQLite3 returns a valid query results, returns an empty query results or returns an invalid result (whether `rc` does not equal to `SQLITE_OK`).  Testing was also done on the `DataTable`, `loginSystem`, `UI`, and `CourseRecommender` files to ensure that the program was storing and retrieving the right data. 
 
 To run the unit tests, `cd` into build and run the `UnitTest` executable.
 
    $ ./UnitTest
    
Valgrind was also used to find detect memory leaks in the program. You can run valgrind by running the `CSCourseRecommender` executable.

    $ valgrind --leak-check=full ./CSCourseRecommender
 
