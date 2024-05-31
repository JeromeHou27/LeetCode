#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <unordered_map>

using namespace std;

class LeetCode_2537 {
public:

    LeetCode_2537() {
        //vector<int> nums = { 1,1,1,1,1 };
        //int k = 10;
        //vector<int> nums = { 3,1,4,3,2,2,4 };
        //int k = 2;
        vector<int> nums = { 2,1,3,1,2,2,3,3,2,2,1,1,1,3,1 };
        int k = 11;

        long long results = countGood(nums, k);
        printf("%d", results);
        printf("\n");
    }

    long long countGood(vector<int>& nums, int k) {
        const int n = nums.size();

        unordered_map<int, int> m;
        int total = 0;
        long long result = 0;

        for (int i = 0, j = 0; i < n; i++) {
            total += m[nums[i]];
            ++m[nums[i]];

            while (j <= i && total >= k) {
                --m[nums[j]];
                total -= m[nums[j]];
                j++;
            }

            result += j;
        }

        return result;
    }
};
