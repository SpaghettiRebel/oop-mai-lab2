#include <gtest/gtest.h>
#include "func.hpp"

TEST(FuncTest, ReplaceInSimpleString) {
    EXPECT_EQ(func("aaaa", 2, 'a', 'b'), "abab");
}

TEST(FuncTest, ReplaceInSentence) {
    EXPECT_EQ(func("Vader said: No, I am your father!", 2, 'a', 'o'),
              "Vader soid: No, I am your fother!");
}

TEST(FuncTest, ReplaceThirdL) {
    EXPECT_EQ(func("lalilulelo", 3, 'l', 'X'), "laliXulelo");
}

TEST(FuncTest, ReplaceAllM) {
    EXPECT_EQ(func("mmm", 1, 'm', 'n'), "nnn");
}

TEST(FuncTest, SingleCharReplace) {
    EXPECT_EQ(func("v", 1, 'v', 'a'), "a");
}

TEST(FuncTest, PositionTooBig) {
    EXPECT_EQ(func("hohenyht", 4, 'h', 'd'), "hohenyht");
}

TEST(FuncTest, NegativeIndexIgnored) {
    EXPECT_EQ(func("lalilulelo", -5, 'h', 'd'), "lalilulelo");
}

TEST(FuncTest, NoCharToReplace) {
    EXPECT_EQ(func("mmm", 2, 'n', 't'), "mmm");
}
