#ifndef MOCK_FOO_HPP
#define MOCK_FOO_HPP
#include <gmock/gmock.h>
#include "foo_if.hpp"


class mockFoo : public fooIf
{
    public:
        MOCK_METHOD(int, fooInt, (const std::string &str), (override));
        MOCK_METHOD(void, fooStr, (std::string &str), (override));
        MOCK_METHOD(void, fooThrow, (), (override));
        MOCK_METHOD(void, callbackMethod, (std::function<void(void)>&), (override));


};


#endif