#pragma once

#include <iostream>
#include <vector>
#include <map>

using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class LeetCode_725 {
public:
    LeetCode_725() {
    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len = 0;
        ListNode* node = head;
        while (node != NULL) {
            ++len;
            node = node->next;
        }

        vector<ListNode*> vecNode = vector<ListNode*>(k);
        int quotient = len / k;
        int remainder = len % k;

        node = head;
        ListNode* next = NULL;

        for (int i = 0; i < k; ++i) {
            vecNode[i] = node;
            if (node == NULL) {
                continue;
            }

            if (i < remainder) {
                for (int j = 0; j < quotient; ++j) {
                    node = node->next;
                }
            }
            else {
                for (int j = 0; j < quotient - 1; ++j) {
                    node = node->next;
                }
            }

            next = node->next;
            node->next = NULL;
            node = next;
        }

        return vecNode;
    }
};
