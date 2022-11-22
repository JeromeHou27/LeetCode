#pragma once

#include <iostream>
#include <vector>

using namespace std;

class LeetCode_279
{
public:
	LeetCode_279() {
		int n = 13;

		printf("%d\n", numSquares(n));
	}

	int d = 0;
	int num = 0;

	int numSquares(int n) {
		int best = INT_MAX;
		int now = 0;

		int s = sqrt(n);
		if (s <= 1)
			return n;

		for (int i = 0; i < s; ++i) {
			num = n;
			d = (s - i) * (s - i);
			int q = num / d;
			num -= d * q;

			if (num == 0) {
				if (best > q)
					best = q;
			}
			else {
				now = q + numSquares(num);
				if (best > now)
					best = now;
			}
		}

		return best;
	}
};
