#pragma once


#include <iostream>
#include <deque>

using namespace std;

class LeetCode_1047
{
public:
    LeetCode_1047() {
        string s = "abbaca";

        printf("%s\n", removeDuplicates(s).c_str());
    }

    string removeDuplicates(string s) {
        string r;
        r.reserve(s.size());
        r.push_back(s[0]);
        for (int i = 1; i < s.size(); ++i) {
            if (r.size() > 0 && r.back() == s[i])
                r.pop_back();
            else
                r.push_back(s[i]);
        }

        return r;
    }
};
