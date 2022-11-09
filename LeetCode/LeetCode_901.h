#pragma once

#include <iostream>
#include <deque>
#include <map>

using namespace std;

class StockSpanner {
public:
    struct Counter {
        int price;
        int count;
    };

    deque<Counter> d;

    int count = 0;
    int i = 0;

    StockSpanner() {
    }

    int next(int price) {
        count = 0;

        if (d.size() > 0) {
            for (i = d.size() - 1; i >= 0;--i) {
                if (d[i].price > price) {
                    break;
                }

                count += d[i].count + 1;

                if (i == 0) {
                    d.clear();
                    break;
                }

                d.pop_back();
            }
        }

        d.push_back({price, count});

        return count + 1;
    }
};

class LeetCode_901 {
public:
    LeetCode_901() {
        int input[] = { 100,80,60,70,60,75,85 };

        StockSpanner stockSpanner;

        for (int& i : input) {
            printf("%d\n", stockSpanner.next(i));
        }
    }
};
