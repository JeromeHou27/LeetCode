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

class LeetCode_92 {
public:
    LeetCode_92() {
        const int num = 5;
        ListNode* head[num];
        for (int i = num - 1; i >= 0; --i) {
            head[i] = new ListNode(i + 1);
            if (i < num - 1)
                head[i]->next = head[i + 1];
        }

        reverseBetween(head[0], 2, 4);

        for (int i = 0; i < num; ++i) {
            delete head[i];
        }
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right)
            return head;

        vector<ListNode*> vecNode = vector<ListNode*>();
        vecNode.reserve(right - left);
        ListNode* node = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;

        for (int i = 1; i <= right + 1 && node != NULL; ++i, node = node->next) {
            if (i == left - 1)
                prev = node;
            else if (i >= left && i < right + 1)
                vecNode.push_back(node);
            else if (i == right + 1)
                next = node;
        }

        for (int i = 0; i < vecNode.size(); ++i) {
            if (i == 0) {
                vecNode[i]->next = next;
                continue;
            }

            if (prev != NULL && i == vecNode.size() - 1)
                prev->next = vecNode[i];

            vecNode[i]->next = vecNode[i - 1];
        }

        return head == vecNode[0] ? vecNode[vecNode.size() - 1] : head;
    }
};
