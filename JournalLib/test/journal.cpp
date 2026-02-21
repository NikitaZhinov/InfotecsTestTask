#include <gtest/gtest.h>

#include "journal/journal.hpp"

using namespace journal;

TEST(JournalTest, Create) {
    Journal j("test.txt.test");

    ASSERT_EQ("test.txt.test", j.getFileName());
    ASSERT_EQ(UNIMPORTANT, j.getBaseLevel());
    ASSERT_TRUE(j.isOpen());
}

TEST(JournalTest, Open) {
    Journal j("test.txt.test");

    j.open();

    ASSERT_EQ("test.txt.test", j.getFileName());
    ASSERT_EQ(UNIMPORTANT, j.getBaseLevel());
    ASSERT_TRUE(j.isOpen());
}

TEST(JournalTest, OpenWithAnotherName) {
    Journal j("test_0000_23.txt.test");

    j.open();

    ASSERT_EQ("test_0000_23.txt.test", j.getFileName());
    ASSERT_EQ(UNIMPORTANT, j.getBaseLevel());
    ASSERT_TRUE(j.isOpen());
}

TEST(JournalTest, Close) {
    Journal j("test.txt.test");

    j.close();

    ASSERT_EQ("test.txt.test", j.getFileName());
    ASSERT_EQ(UNIMPORTANT, j.getBaseLevel());
    ASSERT_FALSE(j.isOpen());
}

TEST(JournalTest, SetBaseLevel) {
    Journal j("test.txt.test");

    j.setBaseLevel(IMPORTANT);

    ASSERT_EQ("test.txt.test", j.getFileName());
    ASSERT_EQ(IMPORTANT, j.getBaseLevel());
    ASSERT_TRUE(j.isOpen());
}
