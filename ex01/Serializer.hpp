#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>

struct Data
{
	std::string	aString;
	int			aNumber;
};

class Serializer
{
public:
    Serializer();
    Serializer(const Serializer &serializer);
    ~Serializer();

    Serializer &operator=(const Serializer &serializer);

	static uintptr_t	serialize(Data *ptr);
	static Data			*deserialize(uintptr_t raw);
};

#endif
