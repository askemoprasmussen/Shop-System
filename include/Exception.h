#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <stdexcept>


class Exception : public std::runtime_error
{
    public:
        Exception(const char* msg):std::runtime_error(msg){};
    protected:
    private:
};

#endif // EXCEPTION_H
