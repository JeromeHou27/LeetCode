#pragma once

/*
* https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

* 約束：
* 1 <= stones.length <= 1000
* 0 <= xi, yi <= 104
* 沒有兩塊石頭在同一個坐標點。
*/

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

class LeetCode_947 {
public:
	LeetCode_947() {
		vector<vector<int>> stones = { {0,1},{1,2},{1,3},{3,3},{2,3},{0,2} };

		printf("%d\n", removeStones(stones));
	}

	void removeX(vector<int>& xVector) {
		map<int, vector<int>>::iterator iter;

		for (int& x : xVector) {
			iter = xMap.find(x);
			if (iter != xMap.end()) {
				vector<int> y = iter->second;
				xMap.erase(iter);

				removeY(y);
			}
		}
	}

	void removeY(vector<int>& yVector) {
		map<int, vector<int>>::iterator iter;

		for (int& y : yVector) {
			iter = yMap.find(y);
			if (iter != yMap.end()) {
				vector<int> x = iter->second;
				yMap.erase(iter);

				removeX(x);
			}
		}
	}

	map<int, vector<int>> xMap;
	map<int, vector<int>> yMap;

	int removeStones(vector<vector<int>>& stones) {
		for (vector<int>& s : stones) {
			auto a = xMap.insert(pair<int, vector<int>>(s[0], { s[1] }));
			if (!a.second) {
				a.first->second.push_back(s[1]);
			}

			a = yMap.insert(pair<int, vector<int>>(s[1], { s[0] }));
			if (!a.second) {
				a.first->second.push_back(s[0]);
			}
		}

		int count = 0;

		while (xMap.size() > 0) {
			++count;
			auto iter = xMap.begin();
			vector<int> y = iter->second;
			xMap.erase(iter);

			removeY(y);
		}

		return stones.size() - count;
    }
};
