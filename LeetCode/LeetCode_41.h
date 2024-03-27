#pragma once

#include <iostream>
#include <vector>

using namespace std;

class LeetCode_41 {
public:
    LeetCode_41() {
        vector<int> nums = { 1,1 };

        printf("%d\n", firstMissingPositive(nums));
    }

    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] <= 0)
                nums[i] = INT_MAX;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] <= (int)nums.size()) {
                if (nums[i] > 0) {
                    if (nums[nums[i] - 1] > 0)
                        nums[nums[i] - 1] = nums[nums[i] - 1] * -1;
                }
                else {
                    if (nums[i] * -1 <= (int)nums.size() && nums[(nums[i] * -1) - 1] > 0)
                        nums[(nums[i] * -1) - 1] = nums[(nums[i] * -1) - 1] * -1;
                }
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0)
                return i + 1;
        }

        return nums.size() + 1;
    }
};
