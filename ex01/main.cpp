#include <iostream>

#include "Serializer.hpp"

int main(void)
{
	Data data;
	data.aString = "To be serialized and de-serialized along with number 555";
	data.aNumber = 555;

	uintptr_t serializedPtr;
	serializedPtr = Serializer::serialize(&data);

	Data *dataPtr;
	dataPtr = Serializer::deserialize(serializedPtr);
	std::cout << "Original struct memory address: " << &data << std::endl;
	std::cout << "DE-Serialized struct memory address: " << dataPtr << std::endl;
	std::cout << "DE-Serialized struct string: " << dataPtr->aString << std::endl;
	std::cout << "DE-Serialized struct number: " << dataPtr->aNumber << std::endl;
	std::cout << std::endl;

    return 0;
}
