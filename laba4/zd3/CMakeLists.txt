add_library(MyArray zd3_4.cpp MyArray.hpp)

target_include_directories(MyArray
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR} C:/Users/Zeta/source/repos/all-in-one-LABS/laba4/zd3
)

add_executable(zd3_4 zd3_4.cpp)