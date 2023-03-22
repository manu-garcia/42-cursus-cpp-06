#include <iostream>
#include <sstream>

#include "ScalarConverter.hpp"

void testLiteral(const std::string &literal)
{
    std::cout << "Testing literal: " << literal << std::endl;
    ScalarConverter::convert(literal);
    std::cout << std::endl;
}

int test(void)
{
    testLiteral("c");
    testLiteral("a");
    testLiteral("97");
    testLiteral("65");
    testLiteral("0");
    testLiteral("-42");
    testLiteral("42");
    testLiteral("0.0f");
    testLiteral("-4.2f");
    testLiteral("4.2f");
    testLiteral("-inff");
    testLiteral("+inff");
    testLiteral("nanf");
    testLiteral("0.0");
    testLiteral("-4.2");
    testLiteral("4.2");
    testLiteral("-inf");
    testLiteral("+inf");
    testLiteral("nan");

    return 0;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " <literal>" << std::endl;
        return 1;
    }

    std::string literal = argv[1];

    if (literal == "test")
    {
        return test();
    }

    ScalarConverter::convert(argv[1]);
    return 0;
}
