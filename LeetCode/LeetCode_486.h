#pragma once

#include <iostream>
#include <vector>

using namespace std;

class LeetCode_486 {
public:
    LeetCode_486() {
        vector<int> nums = { 1,5,233,7 };

        printf("%s\n", predictTheWinner(nums) ? "true" : "false");
    }

    vector<int> results;

    int getBest(vector<int>& nums, int begin, int end) {
        if (begin == end)
            return nums[begin];

        int result = results[begin * nums.size() + end];
        if (result != 0)
            return result;

        int l = nums[begin] - getBest(nums, begin + 1, end);
        int r = nums[end] - getBest(nums, begin, end - 1);

        result = l >= r ? l : r;
        results[begin * nums.size() + end] = result;

        return result;
    }

    bool predictTheWinner(vector<int>& nums) {
        results = vector<int>(nums.size() * nums.size(), 0);

        return getBest(nums, 0, nums.size() - 1) >= 0;
    }
};
