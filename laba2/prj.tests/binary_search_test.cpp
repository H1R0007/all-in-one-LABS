#include <binary_search.hpp>
#include <iostream>

int main()
{
    std::vector<int> nums = { 1, 2, 3, 1, 2, 3 };
    int result = longest_duplicate_subarray(nums);
    std::cout << result << std::endl;  // Вывод: 3

    std::vector<int> nums1 = { 5,5,5,5 };
    int result1 = longest_duplicate_subarray(nums1);
    std::cout << result1 << std::endl;  // Вывод: 3

    nums1 = { 1 };
    result1 = longest_duplicate_subarray(nums1);
    std::cout << result1 << std::endl;  // Вывод: 0

    nums1 = { 1,1 };
    result1 = longest_duplicate_subarray(nums1);
    std::cout << result1 << std::endl;  // Вывод: 1

    nums1 = { 1,2,1,2,3,1,2 };
    result1 = longest_duplicate_subarray(nums1);
    std::cout << result1 << std::endl;  // Вывод: 2

    nums1 = { 1,2,2,3,3,4 };
    result1 = longest_duplicate_subarray(nums1);
    std::cout << result1 << std::endl;  // Вывод: 1

    nums1 = { -1,0,-1,0 };
    result1 = longest_duplicate_subarray(nums1);
    std::cout << result1 << std::endl;  // Вывод: 2
    return 0;
}