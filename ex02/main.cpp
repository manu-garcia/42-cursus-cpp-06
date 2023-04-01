#include <time.h>
#include <stdlib.h>
#include <iostream>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	switch (rand() % 3)
	{
	case 0:
		return new A();
		break;
	case 1:
		return new B();
		break;
	case 2:
		return new C();
		break;
	}
	return NULL;
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "Base has been identified as A*" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "Base has been identified as B*" << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "Base has been identified as C*" << std::endl;
	else
		std::cout << "Base has not been identified as any type" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "Base has been identified as A&" << std::endl;
		return;
	}
	catch (std::exception &e)
	{
	}

	try
	{
		B &b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "Base has been identified as B&" << std::endl;
		return;
	}
	catch (std::exception &e)
	{
	}

	try
	{
		C &c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "Base has been identified as C&" << std::endl;
		return;
	}
	catch (std::exception &e)
	{
	}
}

int main(void)
{
	srand(time(0));

	std::cout << "Generating 5 random classes:" << std::endl;
	for (int i=0; i < 10; i++) {
		Base *ptr = generate();
		identify(ptr);
		delete ptr;
		std::cout << std::endl;
	}

	std::cout << "***********************************************" << std::endl;
	std::cout << "***********************************************" << std::endl;
	std::cout << "***********************************************" << std::endl;
	std::cout << std::endl;

	A *aPtr = new A();
	identify(aPtr);
	delete aPtr;
	std::cout << std::endl;

	B *bPtr = new B();
	identify(bPtr);
	delete bPtr;
	std::cout << std::endl;

	C *cPtr = new C();
	identify(cPtr);
	delete cPtr;
	std::cout << std::endl;

	A a;
	identify(a);
	std::cout << std::endl;

	B b;
	identify(b);
	std::cout << std::endl;

	C c;
	identify(c);
	std::cout << std::endl;

	return 0;
}
