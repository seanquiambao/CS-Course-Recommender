CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
SET(CMAKE_CXX_STANDARD 11)
PROJECT(compileProject)
ADD_SUBDIRECTORY(third-party-sqlite)
ADD_SUBDIRECTORY(googletest)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build) 




ADD_LIBRARY(CourseRecFunctions
  lib/loginSystem.cpp
  lib/SQL.cpp
  lib/CourseRecommender.cpp
  lib/DataTable.cpp
  lib/UI.cpp
)
TARGET_INCLUDE_DIRECTORIES(CourseRecFunctions PUBLIC
  "${PROJECT_SOURCE_DIR}/include"
)

ADD_EXECUTABLE(CSCourseRecommender
    lib/main.cpp
)
ADD_EXECUTABLE(UnitTest
    tests/UnitTests.cpp
)
INCLUDE_DIRECTORIES(
  ${CMAKE_SOURCE_DIR}/test/lib/googletest/include/
  ${CMAKE_SOURCE_DIR}/test/lib/googlemock/include/
)

TARGET_LINK_LIBRARIES(CSCourseRecommender PUBLIC CourseRecFunctions sqlite3 gtest gmock)
TARGET_LINK_LIBRARIES(UnitTest PUBLIC CourseRecFunctions sqlite3 gtest gmock)


