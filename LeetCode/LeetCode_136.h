#pragma once

#include <iostream>
#include <vector>

using namespace std;

class LeetCode_136 {
public:
    LeetCode_136() {
        vector<int> nums = { 4, 1, 2, 1, 2 };

        printf("%d\n", singleNumber(nums));
    }

    int singleNumber(vector<int>& nums) {
        int num = 0;
        for (int i = 0; i < nums.size(); ++i) {
            num ^= nums[i];
        }

        return num;
    }
};
