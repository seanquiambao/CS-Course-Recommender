CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
SET(CMAKE_CXX_STANDARD 11)
PROJECT(compileProject)
ADD_SUBDIRECTORY(third-party-sqlite)
ADD_SUBDIRECTORY(googletest)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build) 

ADD_EXECUTABLE(CSCourseRecommender
    lib/main.cpp
    lib/loginSystem.cpp
    lib/SQL.cpp
    lib/CourseRecommender.cpp
    lib/DataTable.cpp
)
ADD_EXECUTABLE(UnitTest
    tests/UnitTests.cpp
    lib/loginSystem.cpp
    lib/SQL.cpp
    lib/CourseRecommender.cpp
    lib/DataTable.cpp
)
INCLUDE_DIRECTORIES(
  ${CMAKE_SOURCE_DIR}/test/lib/googletest/include/
  ${CMAKE_SOURCE_DIR}/test/lib/googlemock/include/
)



TARGET_LINK_LIBRARIES(CSCourseRecommender sqlite3)
TARGET_LINK_LIBRARIES(UnitTest sqlite3)
TARGET_LINK_LIBRARIES(UnitTest gtest)
TARGET_LINK_LIBRARIES(UnitTest gmock)
