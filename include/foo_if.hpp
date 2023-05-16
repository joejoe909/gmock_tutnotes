#ifndef FOO_IF_HPP
#define FOO_IF_HPP
#include <string>
#include <functional>

class fooIf
{
    public:
        virtual int fooInt(const std::string &str) = 0;
        virtual void fooStr(std::string& str) = 0;
        virtual void fooThrow() = 0;
        virtual void callbackMethod(std::function<void(void)>& callback) = 0;



};


#endif