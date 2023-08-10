#pragma once

#include <iostream>
#include <vector>

using namespace std;

class LeetCode_198 {
public:
    LeetCode_198() {
        vector<int> nums = { 226,174,214,16,218,48,153,131,128,17,157,142,88,43,37,157,43,221,191,68,206,23,225,82,54,118,111,46,80,49,245,63,25,194,72,80,143,55,209,18,55,122,65,66,177,101,63,201,172,130,103,225,142,46,86,185,62,138,212,192,125,77,223,188,99,228,90,25,193,211,84,239,119,234,85,83,123,120,131,203,219,10,82,35,120,180,249,106,37,169,225,54,103,55,166,124 };

        printf("%d\n", rob(nums));
    }

    vector<int> results;

    int best(vector<int>& nums, int offset) {
        if (offset >= nums.size())
            return 0;

        if (offset == nums.size() - 1)
            return nums[offset];

        if (results[offset] >= 0)
            return results[offset];

        int a = nums[offset] + best(nums, offset + 2);
        int b = nums[offset + 1] + best(nums, offset + 3);

        int result = a >= b ? a : b;
        results[offset] = result;
        return result;
    }

    int rob(vector<int>& nums) {
        results = vector<int>(nums.size(), -1);

        return best(nums, 0);
    }
};
