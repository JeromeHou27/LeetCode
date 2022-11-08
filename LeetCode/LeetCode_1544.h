#pragma once

#include <iostream>

using namespace std;

class LeetCode_1544 {
public:
    const char diff = 'a' - 'A';

    LeetCode_1544() {
        string input = "leEeetcode";

        printf("%s", makeGood(input).c_str());
    }

    string makeGood(string s) {
        string r;
        r.reserve((s.size()));
        char d;

        for (int i = 0; i < s.size(); ++i) {
            if (r.size() > 0) {
                d = r.back() - s[i];
                if (d == diff || d == diff * -1) {
                    r.pop_back();
                    continue;
                }
            }

            r.push_back(s[i]);
        }

        return r;
    }
};
