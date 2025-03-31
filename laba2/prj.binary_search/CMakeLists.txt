add_library(prj.binary_search binary_search.cpp binary_search.hpp)

# Указываем, где искать заголовки для этой библиотеки
target_include_directories(prj.binary_search
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR} C:/Users/Zeta/source/repos/laba2/laba2/prj.binary_search  # Теперь можно писать #include <prj.binary_search/binary_search.hpp>
)