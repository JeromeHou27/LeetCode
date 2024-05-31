#pragma once

#include <iostream>
#include <vector>

using namespace std;

class LeetCode_713 {
public:
    LeetCode_713() {
        vector<int> nums = { 10,5,2,6 };
        int k = 100;

        printf("%d\n", numSubarrayProductLessThanK(nums, k));
    }

    int multiplication(vector<int>& nums, int k, int value, int offset) {
        if (offset < nums.size() && value * nums[offset] < k) {
            if (value * nums[offset] * 2 < k)
                return 1 + multiplication(nums, k, value * nums[offset], offset + 1);

            return 1;
        }

        return 0;
    }

    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < k)
                count += 1 + multiplication(nums, k, nums[i], i + 1);
        }

        return count;
    }
};
