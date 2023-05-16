cmake_minimum_required(VERSION 3.26.3)
set(CMAKE_CXX_STANDARD 14)

project(gmkExample LANGUAGES CXX )

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        bf66935e07825318ae519675d73d0f3e313b3ec6  # release-1.10.0
)

FetchContent_MakeAvailable(googletest)

add_executable(${PROJECT_NAME} 
src/dummy.cpp 
test/testDummy.cpp
src/foo.cpp
)

target_link_libraries(${PROJECT_NAME} gtest_main gmock_main)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})

include_directories(include)



# include_directories(googletest/googletest/include)
# add_executable(${PROJECT_NAME} example.cpp)
# target_link_libraries(${PROJECT_NAME} 
# ${CMAKE_SOURCE_DIR}/googletest/build/lib/libgtest.a
# ${CMAKE_SOURCE_DIR}/googletest/build/lib/libgtest_main)

# set(CMAKE_THREAD_LIBS_INIT "-lpthread")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
# set(CMAKE_HAVE_THREADS_LIBRARY 1)
# set(CMAKE_USE_WIN32_THREADS_INIT 0)
# set(CMAKE_USE_PTHREADS_INIT 1)
# set(THREADS_PREFER_PTHREAD_FLAG ON)



