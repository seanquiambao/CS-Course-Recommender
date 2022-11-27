#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "SQLTest.h"
#include "CourseRecommenderTest.h"
#include "UIMenuTest.h"
#include "DataTableTest.h"
#include "LoginSystemTest.h"

int main (int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
