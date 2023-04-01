#ifndef BASE_HPP
#define BASE_HPP

class Base
{
public:
    Base();
    Base(const Base &base);
    virtual ~Base();

    Base &operator=(const Base &base);

	Base *generate(void);
};

#endif
