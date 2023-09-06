#pragma once

#include <iostream>
#include <vector>

using namespace std;

class LeetCode_45 {
public:
    LeetCode_45() {
        vector<int> nums = { 3,4,3,2,5,4,3 };

        printf("%d\n", jump(nums));
    }

    int jump(vector<int>& nums, int target) {
        for (int i = 0; i < target; ++i) {
            if (i + nums[i] >= target) {
                return 1 + jump(nums, i);
            }
        }

        return 0;
    }

    int jump(vector<int>& nums) {
        int count = 0;
        int bestOffset = 0;
        int best = 0;
        int value = 0;
        int target = nums.size() - 1;

        for (int i = 0; i < target; ++i) {
            value = i + nums[i];
            if (value >= target)
                return ++count;

            if (best < value)
                best = value;

            if (bestOffset == i) {
                bestOffset = best;
                ++count;
            }
        }

        return 0;
    }
};
