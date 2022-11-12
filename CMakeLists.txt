CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
project(compileTest)
ADD_SUBDIRECTORY(sqlite3)

ADD_EXECUTABLE(compileTest
    lib/main.cpp
    lib/SQL.cpp
    lib/CourseRecommender.cpp
)

TARGET_LINK_LIBRARIES(compileTest sqlite3)