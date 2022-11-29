#ifndef __LOGINSYSTEMTEST_H__
#define __LOGINSYSTEMTEST_H__
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../include/loginSystem.h"
#include "../include/SQL.h"
#include "Instantiation.h"

using SQLDATABASE::db;
using ::testing::InSequence;

loginSystem login;

TEST(LoginSystemTest, RegisterUserValid_01) {
    login.registerUser("zach29", "wassword", db);
    EXPECT_EQ(SQLITE_OK, db->getRC());
}

TEST(LoginSystemTest, RegisterUserValid_02) {
    login.registerUser("squia003", "woogie", db);
    EXPECT_EQ(SQLITE_OK, db->getRC());
}

TEST(LoginSystemTest, isRegisteredValid) {
    bool valid = login.isRegistered("squia003", db);
    EXPECT_TRUE(valid);
}

TEST(LoginSystemTest, isRegisteredInvalid) {
    bool valid = login.isRegistered("squidward", db);
    EXPECT_FALSE(valid);
}

TEST(LoginSystemTest, isUserFalsePassword) {
    bool valid = login.isUser("squia003", "spongebob", db);
    EXPECT_FALSE(valid);
}

TEST(LoginSystemTest, isUserFalseUser) {
    bool valid = login.isUser("squidward", "woot", db);
    EXPECT_FALSE(valid);
}

TEST(LoginSystemTest, isUserTrue) {
    bool valid = login.isUser("zach29", "wassword", db);
    EXPECT_TRUE(valid);
}

#endif