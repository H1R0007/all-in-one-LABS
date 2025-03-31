add_library(prj.Josephus Josephus.cpp Josephus.hpp)

target_include_directories(prj.Josephus
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR} C:/Users/Zeta/source/repos/laba2/laba2/prj.Josephus  # Теперь можно писать #include <prj.binary_search/binary_search.hpp>
)