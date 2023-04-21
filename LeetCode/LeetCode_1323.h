#pragma once

#include <iostream>

using namespace std;

class LeetCode_1323 {
public:
    LeetCode_1323() {
        int num = 9669;

        printf("%d", maximum69Number(num));
    }

    int maximum69Number(int num) {
        char numStr[10] = "";
        sprintf_s(numStr, "%d", num);

        for (int i = 0; i < sizeof(numStr); ++i) {
            if (numStr[i] == '6') {
                numStr[i] = '9';
                break;
            }
        }

        return atoi(numStr);
    }
};
