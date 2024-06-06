#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

class LeetCode_846 {
public:
    LeetCode_846() {
        vector<int> hand = { 1,2,3,6,2,3,4,7,8 };
        int groupSize = 3;

        bool results = isNStraightHand(hand, groupSize);
        printf("%s\n", results ? "true" : "false");
    }

    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize > 0)
            return false;

        map<int, int> m;
        for (int i = 0; i < hand.size(); ++i) {
            ++m[hand[i]];
        }

        map<int, int>::iterator iter = m.begin();
        int count = 0;
        int number = 0;
        while (iter != m.end()) {
            for (int i = 0; i < groupSize; ++i, ++iter) {
                if (iter == m.end())
                    return false;

                if (i == 0) {
                    number = iter->first;
                    count = iter->second;
                }
                else if (++number != iter->first || iter->second < count)  {
                    return false;
                }
                
                iter->second -= count;
            }

            for (int i = 0; i < groupSize - 1; ++i) {
                if ((--iter)->second == 0) {
                    ++iter;
                    break;
                }
            }
        }

        return true;
    }
};
