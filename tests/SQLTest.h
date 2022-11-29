#ifndef __SQLTEST_H__
#define __SQLTEST_H__
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../include/SQL.h"
#include "Instantiation.h"

using SQLDATABASE::db;

// ======================= CONSTRUCTOR SQL COMMANDS =============================
TEST(SQLTests, Constructor) {
    SQL* sql;
    ASSERT_NO_FATAL_FAILURE(sql = new SQL());
}


// ======================= GENERAL SQL COMMANDS =============================
TEST(SQLTests, createUserTable) {
    db->createUserTable("foo");
    EXPECT_EQ(SQLITE_OK, db->getRC());
}
TEST(SQLTests, deleteDataFromTable_Valid) {
    db->insertTable({"foo", "boo"}, "User Database");
    db->deleteDataFromTable("User Database", "username", "foo");
    EXPECT_EQ(SQLITE_OK, db->getRC());
    db->doesExist("foo", "username", "User Database");
    EXPECT_TRUE(db->dataTable->isEmpty());
}

TEST(SQLTests, deleteDataFromTable_InvalidTable) {
    db->deleteDataFromTable("soo", "username", "boo");
    EXPECT_NE(db->getRC(), SQLITE_OK);
}

TEST(SQLTests, InsertTable_Valid) {
    db->createUserTable("User Database");
    db->insertTable({"foo", "Bar"}, "User Database");
    EXPECT_EQ(SQLITE_OK, db->getRC());
    db->doesExist("foo", "username", "User Database");
    EXPECT_FALSE(db->dataTable->isEmpty());
}

TEST(SQLTests, fetchTable_Valid) {
    db->fetchTable("Course Difficulty");
    EXPECT_EQ(SQLITE_OK, db->getRC());
}

TEST(SQLTests, fetchTable_Invalid) {
    db->fetchTable("dsajgkdsa");
    EXPECT_NE(db->getRC(), SQLITE_OK);
}
// ======================= COURSE RECOMMENDER COMMANDS =============================
TEST(SQLTests, easyClass_ValidQuery) {
    db->easyClass("HUM-A", 10, "Breadth Courses");
    EXPECT_EQ(SQLITE_OK, db->getRC());
    EXPECT_FALSE(db->dataTable->isEmpty());
    
}

TEST(SQLTests, easyClass_EmptyQuery) {
    db->easyClass("SOPHOMORE", 10, "Breadth Courses");
    EXPECT_EQ(SQLITE_OK, db->getRC());
    EXPECT_TRUE(db->dataTable->isEmpty());
    
}

TEST(SQLTests, easyClass_InvalidTable) {
    db->easyClass("SOPHOMORE", 10, "Squidward");
    EXPECT_NE(db->getRC(), SQLITE_OK);
}

TEST(SQLTests, getValue_Valid) {
    db->getValue("difficulty", "name", "CS010A", "Course Difficulty");
    EXPECT_EQ("3.21", db->dataTable->getData(1,1));
    
}
TEST(SQLTests, getValue_EmptyQuery) {
    db->getValue("difficulty", "name", "foo", "Course Difficulty");
    EXPECT_TRUE(db->dataTable->isEmpty());
    
}
TEST(SQLTests, getValue_InvalidTable) {
    db->getValue("difficulty", "name", "foo", "foo");
    EXPECT_NE(SQLITE_OK, db->getRC());
}
// ======================= LOGIN SYSTEM =============================

TEST(SQLTests, doesExist_TRUE) {
    EXPECT_TRUE(db->doesExist("CS100", "name", "Computer Science Courses"));
    
}
TEST(SQLTests, doesExist_FALSE) {
    EXPECT_FALSE(db->doesExist("foo", "name", "Computer Science Courses"));
    
}


#endif