#ifndef __DATATABLETEST_H__
#define __DATATABLETEST_H__
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../include/DataTable.h"


TEST(DataTableTest, Constructor_NotEmpty) {
    char charArr[] = "A\0B\0a\0b\0c\0d\0";
    char *colAp = &charArr[0];char *colBp = &charArr[2];
    char *ap = &charArr[4];char *bp = &charArr[6];
    char *cp = &charArr[8];char *dp = &charArr[10];
    char **pazResult = new char *[6];
    pazResult[0] = colAp;pazResult[1] = colBp;
    pazResult[2] = ap;pazResult[3] = bp;
    pazResult[4] = cp;pazResult[5] = dp;
    DataTable *dataTable = new DataTable(pazResult, 2, 2);
    delete [] pazResult;
    EXPECT_EQ(dataTable->isEmpty(), false);
    EXPECT_EQ(dataTable->getData(1, 1), "a");
    EXPECT_EQ(dataTable->getData(2, 1), "b");
    EXPECT_EQ(dataTable->getData(1, 2), "c");
    EXPECT_EQ(dataTable->getData(2, 2), "d");
}

TEST(DataTableTest, Constructor_Empty) {
    char **pazResult = new char *[0];
    DataTable *dataTable = new DataTable(pazResult, 0, 0);
    delete [] pazResult;
    EXPECT_EQ(dataTable->isEmpty(), true);
    EXPECT_EQ(dataTable->getData(1, 1), "");
    EXPECT_EQ(dataTable->getData(2, 1), "");
    EXPECT_EQ(dataTable->getData(1, 2), "");
    EXPECT_EQ(dataTable->getData(2, 2), "");
}

TEST(DataTableTest, IsEmpty_Empty) {
    char **pazResult = new char *[0];
    DataTable *dataTable = new DataTable(pazResult, 0, 0);
    delete [] pazResult;
    EXPECT_EQ(dataTable->isEmpty(), true);
}

TEST(DataTableTest, IsEmpty_NotEmpty) {
    char charArr[] = "A\0B\0a\0b\0c\0d\0";
    char *colAp = &charArr[0];char *colBp = &charArr[2];
    char *ap = &charArr[4];char *bp = &charArr[6];
    char *cp = &charArr[8];char *dp = &charArr[10];
    char **pazResult = new char *[6];
    pazResult[0] = colAp;pazResult[1] = colBp;
    pazResult[2] = ap;pazResult[3] = bp;
    pazResult[4] = cp;pazResult[5] = dp;
    DataTable *dataTable = new DataTable(pazResult, 2, 2);
    delete [] pazResult;
    EXPECT_EQ(dataTable->isEmpty(), false);
}

TEST(DataTableTest, getData_NotEmpty) {
    char charArr[] = "A\0B\0a\0b\0c\0d\0";
    char *colAp = &charArr[0];char *colBp = &charArr[2];
    char *ap = &charArr[4];char *bp = &charArr[6];
    char *cp = &charArr[8];char *dp = &charArr[10];
    char **pazResult = new char *[6];
    pazResult[0] = colAp;pazResult[1] = colBp;
    pazResult[2] = ap;pazResult[3] = bp;
    pazResult[4] = cp;pazResult[5] = dp;
    DataTable *dataTable = new DataTable(pazResult, 2, 2);
    delete [] pazResult;
    EXPECT_EQ(dataTable->getData(1, 1), "a");
    EXPECT_EQ(dataTable->getData(2, 1), "b");
    EXPECT_EQ(dataTable->getData(1, 2), "c");
    EXPECT_EQ(dataTable->getData(2, 2), "d");
}

TEST(DataTableTest, getData_Empty) {
    char **pazResult = new char *[0];
    DataTable *dataTable = new DataTable(pazResult, 0, 0);
    delete [] pazResult;
    EXPECT_EQ(dataTable->getData(1, 1), "");
    EXPECT_EQ(dataTable->getData(2, 1), "");
    EXPECT_EQ(dataTable->getData(1, 2), "");
    EXPECT_EQ(dataTable->getData(2, 2), "");
}

TEST(DataTableTest, numResults_NotEmpty) {
    char charArr[] = "A\0B\0a\0b\0c\0d\0";
    char *colAp = &charArr[0];char *colBp = &charArr[2];
    char *ap = &charArr[4];char *bp = &charArr[6];
    char *cp = &charArr[8];char *dp = &charArr[10];
    char **pazResult = new char *[6];
    pazResult[0] = colAp;pazResult[1] = colBp;
    pazResult[2] = ap;pazResult[3] = bp;
    pazResult[4] = cp;pazResult[5] = dp;
    DataTable *dataTable = new DataTable(pazResult, 2, 2);
    delete [] pazResult;
    EXPECT_EQ(dataTable->numResults(), 2);
}

TEST(DataTableTest, numResults_Empty) {
    char **pazResult = new char *[0];
    DataTable *dataTable = new DataTable(pazResult, 0, 0);
    delete [] pazResult;
    EXPECT_EQ(dataTable->numResults(), 0);
}

TEST(DataTableTest, printTable_Empty) {
    char **pazResult = new char *[0];
    DataTable *dataTable = new DataTable(pazResult, 0, 0);
    delete [] pazResult;
    ASSERT_NO_FATAL_FAILURE(dataTable->printTable());
}

TEST(DataTableTest, printTable_NotEmpty) {
    char charArr[] = "A\0B\0a\0b\0c\0d\0";
    char *colAp = &charArr[0];char *colBp = &charArr[2];
    char *ap = &charArr[4];char *bp = &charArr[6];
    char *cp = &charArr[8];char *dp = &charArr[10];
    char **pazResult = new char *[6];
    pazResult[0] = colAp;pazResult[1] = colBp;
    pazResult[2] = ap;pazResult[3] = bp;
    pazResult[4] = cp;pazResult[5] = dp;
    DataTable *dataTable = new DataTable(pazResult, 2, 2);
    delete [] pazResult;
    ASSERT_NO_FATAL_FAILURE(dataTable->printTable());
}
#endif