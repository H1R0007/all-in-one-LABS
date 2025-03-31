#include "Josephus.hpp"

int josephus_problem(const std::vector<int>& nums, int k) {
    int k_buf = k;
    std::deque<int> deque(nums.begin(), nums.end());

    if (nums.size() == 1) {
        return nums[0];
    }

    else {
        while (deque.size() > 1) {

            if (k_buf > deque.size()) {
                k = k_buf % deque.size();
            }
            if (k - 1 >= 0) {
                for (int i = 0; i < k - 1; i++) {
                    deque.push_back(deque.front());
                    deque.pop_front();
                }

                deque.pop_front();
            }
            else {
                deque.pop_back();
            }
        }
        return deque.front();
    }
}