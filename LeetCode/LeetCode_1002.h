#pragma once

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class LeetCode_1002 {
public:
    LeetCode_1002() {
        vector<string> words = { "cool","lock","cook" };

        vector<string> results = commonChars(words);
        for (int i = 0; i < results.size(); ++i) {
            printf("%d: %s\n", i, results[i].c_str());
        }
    }

    vector<string> commonChars(vector<string>& words) {
        vector<int> wordCount('z' - 'a' + 1);
        for (int i = 0; i < words[0].size(); ++i) {
            ++wordCount[words[0][i] - 'a'];
        }
        
        int count = 0;
        for (int i = 1; i < words.size(); ++i) {
            for (char j = 0; j < wordCount.size(); ++j) {
                if (wordCount[j] == 0)
                    continue;

                count = 0;
                for (int k = 0; k < words[i].size(); ++k) {
                    if (j + 'a' == words[i][k])
                        ++count;

                    if (wordCount[j] == count)
                        break;
                }
                wordCount[j] = count;
            }
        }

        vector<string> result;
        for (int i = 0; i < wordCount.size(); ++i) {
            if (wordCount[i] == 0)
                continue;
            
            for (int j = 0; j < wordCount[i]; ++j) {
                result.push_back(string(1, i + 'a'));
            }
        }

        return result;
    }
};
