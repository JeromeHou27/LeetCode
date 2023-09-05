#pragma once

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class LeetCode_138 {
public:
    LeetCode_138() {
        copyRandomList(NULL);
    }

    Node* copyRandomList(Node* head) {
        if (head == NULL)
            return NULL;

        map<Node*, Node*> nodeMap = map<Node*, Node*>();
        Node* node = head;
        Node* first = NULL;
        Node* current = NULL;
        Node* previous = NULL;
        map< Node*, Node*>::iterator iter;
        do {
            iter = nodeMap.find(node);
            if (iter != nodeMap.end())
                current = iter->second;
            else {
                current = new Node(node->val);
                if (first == NULL)
                    first = current;

                nodeMap[node] = current;
            }

            if (node->random == NULL)
                current->random = NULL;
            else if (node == node->random)
                current->random = current;
            else {
                iter = nodeMap.find(node->random);
                if (iter != nodeMap.end())
                    current->random = iter->second;
                else {
                    current->random = new Node(node->random->val);
                    nodeMap[node->random] = current->random;
                }
            }

            if (previous != NULL)
                previous->next = current;

            previous = current;
            node = node->next;
        } while (node != NULL);

        return first;
    }
};
