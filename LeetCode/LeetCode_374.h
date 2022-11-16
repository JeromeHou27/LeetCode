#pragma once

#include <iostream>

using namespace std;

class LeetCode_374
{
public:
	LeetCode_374() {		
		int num = 1000;

        printf("%d\n", guessNumber(num));
	}

	int guess(int pick) {
		const int num = 1;
		
		if (num < pick)
			return -1;
		else if (num > pick)
			return 1;

		return 0;
	}

    int guessNumber(int n) {
        int result = -1;
        int num = n;
        int offset = n;

        do {
            offset /= 2;

            if (result < 0)
                num -= offset == 0 ? 1 : offset;
            else
                num += offset == 0 ? 1 : offset;

            result = guess(num);

            if (offset & 1)
                ++offset;

        } while (result != 0);

        return num;
    }
};
