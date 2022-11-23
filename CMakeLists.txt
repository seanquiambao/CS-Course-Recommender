CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
project(compileProject)
ADD_SUBDIRECTORY(third-party-sqlite)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build) 
ADD_EXECUTABLE(fullCompile
    lib/main.cpp
    lib/loginSystem.cpp
    lib/SQL.cpp
    lib/CourseRecommender.cpp
    lib/DataTable.cpp
)

TARGET_LINK_LIBRARIES(fullCompile sqlite3)