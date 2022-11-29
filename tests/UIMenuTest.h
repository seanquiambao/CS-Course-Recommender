#ifndef __UIMENUTEST_H__
#define __UIMENUTEST_H__
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../include/UI.h"
#include "../include/SQL.h"
#include "../include/CourseRecommender.h"
#include "Instantiation.h"

using SQLDATABASE::db;

TEST(UIMenuTest, testMenuPrompmt) {
    UI ui;
    EXPECT_NO_THROW({
        ui.menuPrompt();
    });
}

TEST(UIMenuTest, testMenuSystem) {
    UI ui;
    EXPECT_NO_THROW({
        db->createUserTable("123");
        ui.menuSystem("123", db);
    });
}

TEST(UIMenuTest, testViewRecCourses) {
    UI ui;
    CourseRecommender courseReco("123", db);
    EXPECT_NO_THROW({
        ui.viewRecCoursesOptions(courseReco, db);
    });
}

#endif