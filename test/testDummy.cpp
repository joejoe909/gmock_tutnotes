#include <iostream>
#include <gtest/gtest.h>
#include <memory>
#include "dummy.hpp"
#include "mock_foo.hpp"

class testFixtureDummy : public testing::Test
{
    public:
    testFixtureDummy()
    {
        mTestDummy = std::make_unique<dummy>(mFoo);
    }
    ~testFixtureDummy(){}

    void SetUp()
    {
        
    }

    void TearDown()
    {

    }
    mockFoo mFoo;
    std::unique_ptr<dummy> mTestDummy;
};

TEST_F(testFixtureDummy, dummyInt)
{
    std::string str {"test string"};
    EXPECT_CALL(mFoo, fooInt(str)).Times(1).WillOnce(testing::Return(str.size()));
    int result = mTestDummy->dummyInt(str);
    ASSERT_EQ(result, str.size());
}

TEST_F(testFixtureDummy, dummyStr)
{
    std::string str{};
    std::string resultStr{"test string"};
    EXPECT_CALL(mFoo, fooStr(str)).WillOnce(testing::SetArgReferee<0>(resultStr));
    mTestDummy->dummyStr(str);
    ASSERT_EQ(str, resultStr);
}

ACTION(throwError)
{
    throw std::runtime_error("ERROR TEST");

}

void throwFunction()
{
    std::cout << "ERROR! message from: throwFunction() \n";
    throw std::runtime_error("ERROR_TEST");
}


TEST_F(testFixtureDummy, throwTest)
{
    EXPECT_CALL(mFoo, fooThrow()).WillOnce(testing::Invoke(throwFunction));
    ASSERT_THROW(mTestDummy->dummyThrow(), std::runtime_error);

}

TEST_F(testFixtureDummy, TestCallBack)
{
    testing::MockFunction<void(void)> testFunc;
    
    EXPECT_CALL(mFoo, callbackMethod(testing::_)).Times(1).
    WillOnce(testing::InvokeArgument<0>());
    EXPECT_CALL(testFunc, Call());
    
    mTestDummy->dummyCallBack(testFunc.AsStdFunction());
}
