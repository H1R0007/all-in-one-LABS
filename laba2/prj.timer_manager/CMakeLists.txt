add_library(prj.timer_manager timer_manager.cpp timer_manager.hpp)

target_include_directories(prj.timer_manager
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR} C:/Users/Zeta/source/repos/all-in-one-LABS/laba2/prj.timer_manager  # Теперь можно писать #include <prj.binary_search/binary_search.hpp>
)