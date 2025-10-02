#include <gtest/gtest.h>
#include "func.hpp"
#include <sstream>
#include <stdexcept>

std::string four_to_string(const Four& f) {
    std::stringstream ss;
    f.print(ss);
    return ss.str();
}

TEST(FourConstructorTest, DefaultConstructor) {
    Four zero;
    EXPECT_EQ(four_to_string(zero), ""); 
}

TEST(FourConstructorTest, UnsignedIntConstructor) {
    Four f1(21);
    EXPECT_EQ(four_to_string(f1), "21"); 

    Four f2(301);
    EXPECT_EQ(four_to_string(f2), "301"); 
    
    Four f0(0);
    EXPECT_EQ(four_to_string(f0), "");
}

TEST(FourConstructorTest, InitializerListConstructor) {
    Four f1{2, 0, 1}; 
    EXPECT_EQ(four_to_string(f1), "201"); 
    
    Four f2{3}; 
    EXPECT_EQ(four_to_string(f2), "3"); 
}

TEST(FourConstructorTest, StringConstructor) {
    Four f1("123"); 
    EXPECT_EQ(four_to_string(f1), "123"); 
    
    Four f2("0"); 
    EXPECT_EQ(four_to_string(f2), "0"); 
}

TEST(FourConstructorTest, ConstructorExceptions) {
    EXPECT_THROW(Four(16), std::invalid_argument); 
    EXPECT_THROW((Four{1, 4}), std::invalid_argument); 
    EXPECT_THROW(Four("124"), std::invalid_argument); 
}

TEST(FourArithmeticTest, AddSimple) {
    Four f1("1");
    Four f2("2");
    EXPECT_EQ(four_to_string(f1.add(f2)), "3"); 
}

TEST(FourArithmeticTest, AddWithCarry) {
    Four f1("3");
    Four f2("1");
    EXPECT_EQ(four_to_string(f1.add(f2)), "10"); 
    
    Four f3("33");
    Four f4("1"); 
    EXPECT_EQ(four_to_string(f3.add(f4)), "100"); 
}

TEST(FourArithmeticTest, AddDifferentLengths) {
    Four f1("33");
    Four f2("102");
    EXPECT_EQ(four_to_string(f1.add(f2)), "201"); 
    EXPECT_EQ(four_to_string(f2.add(f1)), "201"); 
}

TEST(FourArithmeticTest, SubtractSimple) {
    Four f1("3");
    Four f2("1");
    EXPECT_EQ(four_to_string(f1.sub(f2)), "2"); 
}

TEST(FourArithmeticTest, SubtractWithBorrow) {
    Four f1("10");
    Four f2("1");
    EXPECT_EQ(four_to_string(f1.sub(f2)), "3"); 
    
    Four f3("21");
    Four f4("13");
    EXPECT_EQ(four_to_string(f3.sub(f4)), "2"); 
}

TEST(FourArithmeticTest, SubtractDifferentLengthsAndZeroes) {
    Four f1("100");
    Four f2("3");  
    EXPECT_EQ(four_to_string(f1.sub(f2)), "31"); 
    
    Four f3("1200"); 
    Four f4("1");   
    EXPECT_EQ(four_to_string(f3.sub(f4)), "1133"); 
}

TEST(FourArithmeticTest, SubtractResultIsZero) {
    Four f1("123");
    Four f2("123");
    EXPECT_EQ(four_to_string(f1.sub(f2)), ""); 
    
    Four f3("1");
    EXPECT_EQ(four_to_string(f3.sub(f3)), "");
}

TEST(FourArithmeticTest, SubtractNegativeResult) {
    Four f1("1");
    Four f2("10");
    EXPECT_EQ(four_to_string(f1.sub(f2)), ""); 
}

TEST(FourComparisonTest, Equality) {
    Four f1("123");
    Four f2("123");
    Four f3("321");

    EXPECT_TRUE(f1.eq(f2));
    EXPECT_FALSE(f1.eq(f3));
}

TEST(FourComparisonTest, GreaterThan) {
    Four f_long("100");
    Four f_short("3"); 
    Four f_equal("100");

    EXPECT_TRUE(f_long.gt(f_short));
    
    EXPECT_TRUE(f_short.gt(Four("2")));

    EXPECT_FALSE(f_long.gt(f_equal)); 
}

TEST(FourComparisonTest, GreaterThanOrEqual) {
    Four f1("21");
    Four f2("21");
    Four f3("12");

    EXPECT_TRUE(f1.ge(f2)); 
    EXPECT_TRUE(f1.ge(f3)); 
    EXPECT_FALSE(f3.ge(f1)); 
}

TEST(FourComparisonTest, LessThan) {
    Four f1("12");
    Four f2("21");

    EXPECT_TRUE(f1.lt(f2)); 
    EXPECT_FALSE(f2.lt(f1)); 
    EXPECT_FALSE(f1.lt(f1)); 
}

TEST(FourComparisonTest, LessThanOrEqual) {
    Four f1("12");
    Four f2("21");
    Four f3("12");

    EXPECT_TRUE(f1.le(f3)); 
    EXPECT_TRUE(f1.le(f2)); 
    EXPECT_FALSE(f2.le(f1)); 
}