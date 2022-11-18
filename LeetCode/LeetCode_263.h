#pragma once

#include <iostream>

using namespace std;

class LeetCode_263 {
public:
	LeetCode_263() {
		int n = 1;

		printf("%d\n", isUgly(n));
	}

    bool isUgly(int n) {
		if (n <= 0)
			return false;

		while (n % 5 == 0) {
			n /= 5;
		}

		while (n % 3 == 0) {
			n /= 3;
		}

		while (!(n & 1)) {
			n >>= 1;
		}

		return n == 1;
    }
};
