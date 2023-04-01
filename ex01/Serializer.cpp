
#include <iostream>

#include "Serializer.hpp"

///////////////////////////////////////////////////////////////////////////////
// Constructors / Destructor
///////////////////////////////////////////////////////////////////////////////

Serializer::Serializer()
{
    std::cout << "Serializer Default constructor." << std::endl;
}

Serializer::Serializer(const Serializer &scalarConverter)
{
    *this = scalarConverter;
    std::cout << "Serializer Copy constructor." << std::endl;
}

Serializer::~Serializer()
{
    std::cout << "Serializer destructor." << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
// Operators
///////////////////////////////////////////////////////////////////////////////

Serializer &Serializer::operator=(const Serializer &scalarConverter)
{
    (void)scalarConverter;
    std::cout << "Serializer copy operator." << std::endl;

    return *this;
}

///////////////////////////////////////////////////////////////////////////////
// Member functions
///////////////////////////////////////////////////////////////////////////////

uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
