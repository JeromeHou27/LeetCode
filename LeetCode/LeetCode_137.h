#pragma once

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class LeetCode_137 {
public:
    LeetCode_137() {
        vector<int> nums = { 2, 2, 3, 2 };

        printf("%d\n", singleNumber(nums));
    }

    int singleNumber(vector<int>& nums) {
        multiset<int> numsMultiSet;

        for (int i = 0; i < nums.size(); ++i) {
            numsMultiSet.insert(nums[i]);
        }

        int lastNum = 0;
        int count = 0;
        for (multiset<int>::iterator iter = numsMultiSet.begin(); iter != numsMultiSet.end(); ++iter) {
            if (lastNum != *iter && count == 1) {
                return lastNum;
            }

            count = lastNum == *iter ? count + 1 : 1;
            lastNum = *iter;
        }

        return lastNum;
    }
};
