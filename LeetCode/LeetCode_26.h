#pragma once

#include <iostream>
#include <vector>

using namespace std;

class LeetCode_26
{
public:
    LeetCode_26() {
        vector<int> nums = { 0,0,1,1,1,2,2,3,3,4 };

        printf("%d\n", removeDuplicates(nums));
    }

    int removeDuplicates(vector<int>& nums) {
        int offset = 0;

        for (int& n : nums) {
            if (nums[offset] != n) {
                nums[++offset] = n;
            }
        }

        return ++offset;
    }
};
