#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

class ScalarConverter
{
private:
    static bool canBeConvertedToDouble(const std::string &literal);
    static void convertToChar(const std::string &literal);
    static void convertToInt(const std::string &literal);
    static void convertToDouble(const std::string &literal);
    static void convertToFloat(const std::string &literal);

public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &scalarConverter);
    ~ScalarConverter();

    ScalarConverter &operator=(const ScalarConverter &scalarConverter);

    static void convert(const std::string &literal);
};

#endif
