add_library(prj.binary_search binary_search.cpp binary_search.hpp)

# ���������, ��� ������ ��������� ��� ���� ����������
target_include_directories(prj.binary_search
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR} C:/Users/Zeta/source/repos/all-in-one-LABS/laba2/prj.binary_search  # ������ ����� ������ #include <prj.binary_search/binary_search.hpp>
)