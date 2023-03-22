
#include <iostream>
#include <iomanip>
#include <sstream>

#include "ScalarConverter.hpp"

///////////////////////////////////////////////////////////////////////////////
// Constructors / Destructor
///////////////////////////////////////////////////////////////////////////////

ScalarConverter::ScalarConverter()
{
    std::cout << "ScalarConverter Default constructor." << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &scalarConverter)
{
    *this = scalarConverter;
    std::cout << "ScalarConverter Copy constructor." << std::endl;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "ScalarConverter destructor." << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
// Operators
///////////////////////////////////////////////////////////////////////////////

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &scalarConverter)
{
    (void)scalarConverter;
    std::cout << "ScalarConverter copy operator." << std::endl;

    return *this;
}

///////////////////////////////////////////////////////////////////////////////
// Member functions
///////////////////////////////////////////////////////////////////////////////

void ScalarConverter::convertToChar(const std::string &literal)
{
    if (literal.size() == 1 && isalpha(literal[0]))
    {
        std::cout << "char: '" << literal[0] << "'" << std::endl;
        return;
    }

    double literalAsDouble = std::atof(literal.c_str());

    if (!literal.size() ||
        (!literalAsDouble && literal[0] != '0') ||
        literalAsDouble < std::numeric_limits<unsigned char>::min() ||
        literalAsDouble > std::numeric_limits<unsigned char>::max())
    {
        std::cout << "char: Impossible" << std::endl;
        return;
    }

    if (isalpha(literalAsDouble))
    {
        std::cout << "char: '" << static_cast<unsigned char>(literalAsDouble) << "'" << std::endl;
    }
    else
    {
        std::cout << "char: Non displayable" << std::endl;
    }
}

bool ScalarConverter::canBeConvertedToDouble(const std::string &literal)
{
    double literalAsDouble;

    std::istringstream iss(literal);
    iss >> std::noskipws >> literalAsDouble;
    if (iss.fail() || !iss.eof())
    {
        return false;
    }

    return true;
}

void ScalarConverter::convertToInt(const std::string &literal)
{
    double literalAsDouble = std::atof(literal.c_str());

    if ((!literalAsDouble && literal[0] != '0') ||
        isalpha(literal[0]) ||
        literalAsDouble < std::numeric_limits<int>::min() ||
        literalAsDouble > std::numeric_limits<int>::max())
    {
        std::cout << "int: Impossible" << std::endl;
        return;
    }

    std::cout << "int: " << static_cast<int>(literalAsDouble) << std::endl;
}

void ScalarConverter::convertToFloat(const std::string &literal)
{
    if (literal == "-inff")
    {
        std::cout << "float: -inff" << std::endl;
        return;
    }

    if (literal == "+inff")
    {
        std::cout << "float: +inff" << std::endl;
        return;
    }

    if (literal == "nanf")
    {
        std::cout << "float: nanf" << std::endl;
        return;
    }

    double literalAsDouble = std::atof(literal.c_str());

    if (literalAsDouble == 0 && literal[0] != '0')
    {
        std::cout << "float: impossible" << std::endl;
        return;
    }

    std::cout << "float: " << std::fixed << std::setprecision(1)
              << static_cast<float>(literalAsDouble) << "f" << std::endl;
}

void ScalarConverter::convertToDouble(const std::string &literal)
{
    if (literal == "-inf")
    {
        std::cout << "double: -inf" << std::endl;
        return;
    }

    if (literal == "+inf")
    {
        std::cout << "double: +inf" << std::endl;
        return;
    }

    if (literal == "nan")
    {
        std::cout << "double: nan" << std::endl;
        return;
    }

    double literalAsDouble = std::atof(literal.c_str());

    if (literalAsDouble == 0 && literal[0] != '0')
    {
        std::cout << "double: impossible" << std::endl;
        return;
    }

    std::cout << "double: " << std::fixed << std::setprecision(1)
              << static_cast<double>(literalAsDouble) << std::endl;
}

void ScalarConverter::convert(const std::string &literal)
{
    ScalarConverter::convertToChar(literal);
    ScalarConverter::convertToInt(literal);
    ScalarConverter::convertToFloat(literal);
    ScalarConverter::convertToDouble(literal);
}
