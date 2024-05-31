#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <deque>

using namespace std;

class LeetCode_310 {
public:

    LeetCode_310() {
        int n = 6;
        vector<vector<int>> edges = { {0,1} ,{0,2},{0,3},{3,4},{4,5} };

        vector<int> results = findMinHeightTrees(n, edges);
        for (int i = 0; i < results.size(); ++i) {
            printf("%d", results[i]);
        }
        printf("\n");
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1)
            return { 0 };
        else if (n == 2)
            return { 0, 1 };

        vector<set<int>> v(n);
        for (int i = 0; i < edges.size(); ++i) {
            v[edges[i][0]].insert(edges[i][1]);
            v[edges[i][1]].insert(edges[i][0]);
        }

        deque<map<int, set<int>*>> order;
        for (int i = 0; i < v.size() - 1; ++i) {
            if (v.size() == 1)
                continue;

            if (order.size() == 0) {
                map<int, set<int>*> m;
                m[i] = &v[i];
                order.push_back(m);
                break;
            }

            v[i].
        }

        return { 0 };
    }
};
