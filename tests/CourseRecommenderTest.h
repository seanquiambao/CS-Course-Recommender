#ifndef __COURSERECOMMENDERTEST_H__
#define __COURSERECOMMENDERTEST_H__
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../include/CourseRecommender.h"
#include "Instantiation.h"
using SQLDATABASE::db;

// TEST(CourseRecommender, TestCheck) {
//     EXPECT_TRUE(true);
// }
TEST(CourseRecommender, ConstructorNoThrow) {
    db->createUserTable("test");
    db->insertTable({""}, "test");
    EXPECT_NO_THROW(CourseRecommender courseR("test", db));
}
TEST(CourseRecommender, printRecBreadthCourses) {
    db->createUserTable("test");
    db->insertTable({""}, "test");
    CourseRecommender courseR("test", db);
    EXPECT_NO_THROW(courseR.printRec(db, "Breadth Courses"));
}
TEST(CourseRecommender, printRecCSCourses) {
    db->createUserTable("test");
    db->insertTable({""}, "test");
    CourseRecommender courseR("test", db);
    EXPECT_NO_THROW(courseR.printRec(db, "Computer Science Courses"));
}
// EXPECT_NO_THROW(courseR.printEasiestClasses(db, "", "Breadth Courses"));
//     EXPECT_NO_THROW(courseR.printEasiestClasses(db, "Computer Science Courses"));
TEST(CourseRecommender, printEasiestClassesENGL) {
    CourseRecommender courseR("test", db);
    EXPECT_NO_THROW(courseR.printEasiestClasses(db, "ENGL", "Breadth Courses"));
}
TEST(CourseRecommender, printEasiestClassesHUMA) {
    CourseRecommender courseR("test", db);
    EXPECT_NO_THROW(courseR.printEasiestClasses(db, "HUM-A", "Breadth Courses"));
}
TEST(CourseRecommender, printEasiestClassesHUMB) {
    CourseRecommender courseR("test", db);
    EXPECT_NO_THROW(courseR.printEasiestClasses(db, "HUM-B", "Breadth Courses"));
}
TEST(CourseRecommender, printEasiestClassesHUMC) {
    CourseRecommender courseR("test", db);
    EXPECT_NO_THROW(courseR.printEasiestClasses(db, "HUM-C", "Breadth Courses"));
}
TEST(CourseRecommender, printEasiestClassesSSA) {
    CourseRecommender courseR("test", db);
    EXPECT_NO_THROW(courseR.printEasiestClasses(db, "SS-A", "Breadth Courses"));
}
TEST(CourseRecommender, printEasiestClassesSSB) {
    CourseRecommender courseR("test", db);
    EXPECT_NO_THROW(courseR.printEasiestClasses(db, "SS-B", "Breadth Courses"));
}
TEST(CourseRecommender, printEasiestClassesSSC) {
    CourseRecommender courseR("test", db);
    EXPECT_NO_THROW(courseR.printEasiestClasses(db, "SS-C", "Breadth Courses"));
}
TEST(CourseRecommender, addRequirementValid) {
    CourseRecommender courseR("test", db);
    EXPECT_NO_THROW(courseR.addRequirement("ENGL", db));
    EXPECT_EQ(SQLITE_OK,db->getRC());             // data is correct
}
TEST(CourseRecommender, addRequirementInvalid) {
    CourseRecommender courseR("test", db);
    EXPECT_NO_THROW(courseR.addRequirement("a", db));
    EXPECT_EQ(SQLITE_OK,db->getRC());             // data is correct
}
// TEST(CourseRecommender, addRequirementPromptNoThrow) {
//     SQL db;
//     CourseRecommender courseR("test", db);
//     EXPECT_NO_THROW(courseR.addRequirementPrompt(db));
// }
TEST(CourseRecommender, removeRequirementValid) {
    CourseRecommender courseR("test", db);
    EXPECT_NO_THROW(courseR.removeRequirement("ENGL", db));
}
TEST(CourseRecommender, removeRequirementInvalid) {
    CourseRecommender courseR("test", db);
    EXPECT_NO_THROW(courseR.removeRequirement("a", db));
    EXPECT_EQ(SQLITE_OK,db->getRC());             // data is correct
}
// TEST(CourseRecommender, removeRequirementPromptNoThrow) {
//     SQL db;
//     CourseRecommender courseR("test", db);
//     EXPECT_NO_THROW(courseR.removeRequirementPrompt(db));
// }
TEST(CourseRecommender, validBreadthTrue) {
    CourseRecommender courseR("test", db);
    EXPECT_EQ(courseR.validBreadth("ENGL"), true);
}
TEST(CourseRecommender, validBreadthFalse) {
    CourseRecommender courseR("test", db);
    EXPECT_EQ(courseR.validBreadth("a"), false);
}
// TEST(CourseRecommender, changeClassLevelNoThrow) {
//     SQL db;
//     CourseRecommender courseR("test", db);
//     EXPECT_NO_THROW(courseR.changeClassLevel());
// }
#endif