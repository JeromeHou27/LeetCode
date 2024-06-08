#pragma once

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class LeetCode_648 {
public:
    LeetCode_648() {
        vector<string> dictionary = { "a","b","c" };
        string sentence = "aadsfasf absbs bbab cadsfafs";
        string result = replaceWords(dictionary, sentence);
        printf("%s\n", result.c_str());
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        for (int i = 0; i < dictionary.size() - 1; ++i) {
            for (int j = i + 1; j < dictionary.size(); ++j) {
                if (dictionary[i].size() > dictionary[j].size())
                    swap(dictionary[i], dictionary[j]);
            }
        }

        int offset = 0;
        int dictionaryIndex = -1;
        int resultOffset = 0;

        for (int i = 0; i < sentence.size(); ++i) {
            while (i < sentence.size()) {
                if (sentence[++i] == ' ') {
                    break;
                }
            }

            for (int j = 0; j < dictionary.size(); ++j) {
                if (i - offset < dictionary[j].size())
                    break;

                dictionaryIndex = j;
                for (int k = 0; k < dictionary[j].size(); ++k) {
                    if (sentence[offset + k] != dictionary[j][k]) {
                        dictionaryIndex = -1;
                        break;
                    }
                }

                if (dictionaryIndex >= 0)
                    break;
            }

            if (offset != 0) {
                sentence[resultOffset] = ' ';
                ++resultOffset;
            }

            if (dictionaryIndex >= 0) {
                for (int j = 0; j < dictionary[dictionaryIndex].size(); ++j) {
                    sentence[resultOffset + j] = dictionary[dictionaryIndex][j];
                }
                resultOffset += dictionary[dictionaryIndex].size();
            }
            else {
                for (int j = 0; j < i - offset + (i == sentence.size() - 1 ? 1 : 0); ++j) {
                    sentence[resultOffset + j] = sentence[offset + j];
                }
                resultOffset += i - offset + (i == sentence.size() - 1 ? 1 : 0);
            }

            dictionaryIndex = -1;
            offset = i + 1;
        }

        sentence.resize(resultOffset);

        return sentence;
    }
};
