#include "dummy.hpp"


int dummy::dummyInt(const std::string &str)
{
    return mFoo.fooInt(str);
}

void dummy::dummyStr(std::string &str)
{
    mFoo.fooStr(str);
    return;
}

void dummy::dummyThrow()
{
    mFoo.fooThrow();
}

void dummy::dummyCallBack(std::function<void(void)> callback)
{
    mFoo.callbackMethod(callback);
}

