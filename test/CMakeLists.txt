cmake_minimum_required(VERSION 3.1)


set(TEST_SOURCES testfield.cpp testgame.cpp testplayer.cpp ../src/field.h ../src/field.cpp ../src/game.h ../src/game.cpp ../src/player.h ../src/player.cpp ../src/common.h ../src/io.h ../src/io.cpp)
#set(TEST_SOURCES ${CMAKE_SOURCE_DIR}/test/*.cpp ${CMAKE_SOURCE_DIR}/src/*.h ${CMAKE_SOURCE_DIR}/src/*.cpp)
add_executable(testcode ${TEST_SOURCES})
target_include_directories(testcode PUBLIC ${GTEST_SOURCE_DIR}/include)

find_library(GTEST_LIB gtestd ${CMAKE_BINARY_DIR}/lib/Debug)
find_library(GMOCK_LIB gmockd ${CMAKE_BINARY_DIR}/lib/Debug)

if(GTEST_LIB)
    message("GTest is FOUND!")
else()
    message("GTest isn't FOUND!")
endif()

target_link_libraries(testcode gtest gmock_main gtest_main)
add_test(testcode testcode)

