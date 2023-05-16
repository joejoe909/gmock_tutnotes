#include "foo.hpp"

int foo::fooInt(const std::string str)
{
    return str.size();
}


void foo::fooStr(std::string& str)
{
    str = "exampleStr";
    return;
}

void foo::fooThrow()
{
    //thrwo runtime error;
}

void foo::callbackMethod(std::function<void(void)> &callback)
{
    callback();
}