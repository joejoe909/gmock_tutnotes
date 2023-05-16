#ifndef DUMMY_HPP
#define DUMMY_HPP
#include <string>
#include "foo_if.hpp"
#include <functional>

class dummy
{
    public:
        dummy(fooIf& f):mFoo(f){};
        int dummyInt(const std::string &str);
        void dummyStr(std::string &str);
        void dummyThrow();
        void dummyCallBack(std::function<void(void)> callback);

        fooIf& mFoo;

};


#endif // DUMMY_HPP