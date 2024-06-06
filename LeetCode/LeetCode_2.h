#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}

    string toString() {
        return next == NULL ? to_string(val) : to_string(val) + ", " + next->toString();
    }

    static ListNode* newListNode(vector<int> nums) {
        ListNode* node = new ListNode(0);
        ListNode* next = NULL;
        for (int i = 0; i < nums.size(); ++i) {
            if (next == NULL) {
                next = node;
                next->val = nums[i];
                continue;
            }

            next->next = new ListNode(nums[i]);
            next = next->next;
        }

        return node;
    }
};

class LeetCode_2 {
public:
    LeetCode_2() {
        ListNode* l1 = ListNode::newListNode({ 9 });
        ListNode* l2 = ListNode::newListNode({ 1,9,9,9,9,9,9,9,9,9 });

        ListNode* node = addTwoNumbers(l1, l2);

        printf("%s\n", node->toString().c_str());
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* node = l1;
        bool overflow = false;

        while (l1 != NULL) {

            if (overflow) {
                overflow = false;
                l1->val += 1;
            }

            if (l2 != NULL) {
                l1->val += l2->val;
            }

            if (l1->next == NULL) {
                if (l2 != NULL && l2->next != NULL) {
                    l1->next = l2->next;
                    l2->next = NULL;
                }
            }

            if (l1->val >= 10) {
                overflow = true;
                l1->val %= 10;
                if (l1->next == NULL)
                    l1->next = new ListNode(0);
            }



            l1 = l1 == NULL ? NULL : l1->next;
            l2 = l2 == NULL ? NULL : l2->next;
        }

        return node;
    }
};
