#ifndef BASE_HPP
#define BASE_HPP

class Base
{
public:
    Base();
    Base(const Base &base);
    ~Base();

    Base &operator=(const Base &base);

};

#endif
