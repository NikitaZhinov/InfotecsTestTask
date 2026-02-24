#include "journal/level.hpp"

#include <gtest/gtest.h>
#include <stdexcept>

TEST(LevelTest, FormatStringUnimportant) {
    std::string str = "unimportant";

    ASSERT_EQ(journal::UNIMPORTANT, journal::formatLevel(str));
}

TEST(LevelTest, FormatStringImportant) {
    std::string str = "important";

    ASSERT_EQ(journal::IMPORTANT, journal::formatLevel(str));
}

TEST(LevelTest, FormatStringVeryImportant) {
    std::string str = "very_important";

    ASSERT_EQ(journal::VERY_IMPORTANT, journal::formatLevel(str));
}

TEST(LevelTest, FormatStringBasicNecessities) {
    std::string str = "basic_necessities";

    ASSERT_EQ(journal::BASIC_NECESSITIES, journal::formatLevel(str));
}

TEST(LevelTest, FormatStringThrow) {
    std::string str = ";iyhvutuc";

    ASSERT_THROW(journal::formatLevel(str), std::runtime_error);
}

TEST(LevelTest, FormatLevelUnimportant) {
    journal::Level level = journal::UNIMPORTANT;

    ASSERT_EQ("UNIMPORTANT", journal::formatLevel(level));
}

TEST(LevelTest, FormatLevelImportant) {
    journal::Level level = journal::IMPORTANT;

    ASSERT_EQ("IMPORTANT", journal::formatLevel(level));
}

TEST(LevelTest, FormatLevelgVeryImportant) {
    journal::Level level = journal::VERY_IMPORTANT;

    ASSERT_EQ("VERY_IMPORTANT", journal::formatLevel(level));
}

TEST(LevelTest, FormatLevelBasicNecessities) {
    journal::Level level = journal::BASIC_NECESSITIES;

    ASSERT_EQ("BASIC_NECESSITIES", journal::formatLevel(level));
}

TEST(LevelTest, FormatLevelThrow) {
    journal::Level level = static_cast<journal::Level>(-1);

    ASSERT_THROW(journal::formatLevel(level), std::runtime_error);
}
