#pragma once

#include <iostream>

using namespace std;

class LeetCode_345 {
public:
    LeetCode_345() {
        string s = "leetcode";

        printf("%s\n", reverseVowels(s).c_str());
    }

    bool isVowel(char character) {
        const char vowels[] = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };

        for (char vowel : vowels) {
            if (vowel == character)
                return true;
        }

        return false;
    }

    string reverseVowels(string s) {
        int i = 0;
        int j = s.size();

        for (i = 0; i < j; ++i) {
            if (isVowel(s[i])) {
                for (; j > i; --j) {
                    if (isVowel(s[j])) {
                        if (s[i] != s[j])
                            swap(s[i], s[j]);

                        --j;
                        break;
                    }
                }
            }
        }

        return s;
    }
};
