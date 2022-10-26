[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=8862854&assignment_repo_type=AssignmentRepo)

# <\Computer Science Course Recommender\>
 
 > Authors: \[Nathan Chan](https://github.com/nchannoob)\, \[Jeric Pascua](https://github.com/jericj)\, \[Sean Quiambao](https://github.com/toastmeal)\, \<[Zachary Ta](https://github.com/ZacharyTa)\

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
 > * **LibXL** - A C++ Excel Library for reading/writing data from an excel file (Google Sheets UCR Difficulty Database will be exported into an excel file). This will be used to read input given by the user, which will be discussed in a later segment.
### Input/Output
 > **Input** - The user can input the courses they have already taken, this can be inputted through either a .txt file or an Excel file. This input will be used to calculate the amount of credits taken, which can be used to calculate the amount of credits required. This will also be used as a prerequisite checklist for specific computer science courses. The user can also input classes into their planner, if they meet the required prerequisite.<br>
 > **Output** - The program will output a list of engineering courses, ordered from the least to most difficult. It will only output the courses that the user needs, and will only show the courses that meet the user’s prerequisites requirements. The program will also output the planner the user has created, which will output the average difficulty and the amount of units for that planned quarter.
### Features
 > * The user can create a planner for each quarter. The user is allowed to add or remove courses from the planner. When adding courses, the program will sum up all the units. The program will also show the average difficulty so that the user can see the amount of workload they have. This average difficulty is calculated based on the UCR difficulty database. This program can also calculate the expected graduation date.
 > * The user can search up the courses. The search bar will be divided whether the course is a lower division course, upper division course, or elective course. The program will also show some breadth courses for each area of study (we will focus on the three most popular breadth courses for each area of study). The user can select a course in the view finder, which will display the courses prerequisite, amount of units, and difficulty.

 > ## Phase II
 > In addition to completing the "Class Diagram" section below, you will need to:
 > * Create an "Epic" (note) for each feature. Place these epics in the `Product Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Break down the "Epics" into smaller actionable user stories (i.e. smaller development tasks). Convert them into issues and assign them to team members. Place these in the `TODO` column.
 >   * These cards should represent roughly 7 days worth of development time for your team. Then, once the sprint is over you should be repeating these steps to plan a new sprint, taking you until your second scrum meeting with the reader in phase III.
 > * Schedule two check-ins using Calendly. You need to pick both time slots during your lab on week 6. Your entire team must be present for both check-ins.
 >   * The first check-in needs to be scheduled with your lab TA. During that meeting, you will discuss your project design/class diagram from phase II.
 >   * The second check-in should be scheduled with a reader. During that meeting you will discuss:
 >     * The tasks you are planning for the first sprint
 >     * How work will be divided between the team members
## Class Diagram
 > Include a **class diagram(s)** for your project and a **description** of the diagram(s). Your class diagram(s) should include all the main classes you plan for the project. This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper UML notation (as discussed in the course slides).
 
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
 
