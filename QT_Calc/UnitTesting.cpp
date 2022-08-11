#include <catch.hpp>
#include <math.h>

#include "digit.h"
#include "infixToPostfix.h"
#include "unaryOperation.h"


TEST_CASE("Checking for label")
{
    REQUIRE(all_num("0","10") == "10");
    REQUIRE(all_num("2","10") == "210");
}

TEST_CASE("Checking for all unary operations","[approx, modulo, square, square root, reciprocal, clear,fraction (/2) ]" )
{
    REQUIRE(all_unary_operation("6.1","≈") == 6.0);
    REQUIRE(all_unary_operation("10","%") == 0.1);
    REQUIRE(all_unary_operation("6","𝔁²") == 36);
    REQUIRE(all_unary_operation("25","²√") == 5);
    REQUIRE(all_unary_operation("8","1/𝔁") == 0.125);
    REQUIRE(all_unary_operation("20","CE") == 0);
    REQUIRE(all_unary_operation("50","𝔁/2") == 25);
    REQUIRE(all_unary_operation("50","&") == 0);
}

TEST_CASE("Checking for all binary operation results","[addition, subtraction, multiplication,division]")
{
    REQUIRE(operation(10,20,'+') == 30);
    REQUIRE(operation(40,20,'-') == 20);
    REQUIRE(operation(10,7,'*') == 70);
    REQUIRE(operation(50,10,'/') == 5);

}

TEST_CASE("Checking for all operands","[0,1,2,3,4,5,6,7,8,9]")
{
    REQUIRE(isOperand('0') == 1);
    REQUIRE(isOperand('1') == 1);
    REQUIRE(isOperand('2') == 1);
    REQUIRE(isOperand('3') == 1);
    REQUIRE(isOperand('4') == 1);
    REQUIRE(isOperand('5') == 1);
    REQUIRE(isOperand('6') == 1);
    REQUIRE(isOperand('7') == 1);
    REQUIRE(isOperand('8') == 1);
    REQUIRE(isOperand('9') == 1);
    REQUIRE(isOperand('n') == 0);
}

TEST_CASE("Checking for all binary operators","[addition, subtraction, multiplication,division,power]")
{
    REQUIRE(isOperator('+') == 1);
    REQUIRE(isOperator('-') == 1);
    REQUIRE(isOperator('*') == 1);
    REQUIRE(isOperator('/') == 1);
    REQUIRE(isOperator('^') == 1);
    REQUIRE(isOperator('$') == 0);
}

TEST_CASE("Checking for precedence of  operators")
{
    REQUIRE(precofOperator('^') == 3);
    REQUIRE(precofOperator('/') == 2);
    REQUIRE(precofOperator('*') == 2);
    REQUIRE(precofOperator('+') == 1);
    REQUIRE(precofOperator('-') == 1);
    REQUIRE(precofOperator('!') == -1);
}

TEST_CASE("Checking for infix to postfix conversion")
{
    REQUIRE(infixToPostfix("33 + 9") == "33 9 + ");
    REQUIRE(infixToPostfix("3 + 9 - ( 3 - 88 ) * 7") == "3 9 + 3 88 - 7 * - ");
    REQUIRE(infixToPostfix("6 + 9 - 33") == "6 9 + 33 - ");
}

TEST_CASE("Checking for infix to result")
{
    REQUIRE(infixToPostfixEvaluate("33 + 9 ") == 42);
    REQUIRE(infixToPostfixEvaluate("3 + 9 - ( 3 - 88 ) * 7") == 583);
    REQUIRE(infixToPostfixEvaluate("6 + 9 - 33") == 18);
}

TEST_CASE("Checking for  postfix to result")
{
    REQUIRE(postfixEval("33 9 + ") == 42);
    REQUIRE(postfixEval( "3 9 + 3 88 - 7 * - ") == 583);
    REQUIRE(postfixEval( "6 9 + 33 - ") == 18);
}



