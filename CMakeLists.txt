CMAKE_MINIMUM_REQUIRED(VERSION 3.9.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


project(OpenIt)
message("This is OpenIt project")

if(MSVC)
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_RELEASE} /MTd")
    add_compile_options(/W4 /WX)
endif()

enable_testing()
add_subdirectory(googletest)
add_subdirectory(src)
add_subdirectory(test)
