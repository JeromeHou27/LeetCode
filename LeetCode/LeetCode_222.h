#pragma once

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    ~TreeNode() {
        if (left != nullptr)
            delete left;
        if (right != nullptr)
            delete right;
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class LeetCode_222 {
public:
    vector<char> getBits(int index) {
        vector<char> bits;

        while (index > 0) {
            bits.push_back(index % 2);
            index >>= 1;
        }

        return bits;
    }

    TreeNode* genTreeNode(vector<int>& nums) {
        TreeNode* root = NULL;
        TreeNode* node = NULL;

        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0) {
                root = new TreeNode(nums[i]);
            }
            else {
                vector<char> bits = getBits(i + 1);
                node = root;
                for (int j = bits.size() - 2; j >= 0; --j) {
                    if (j == 0) {
                        if (bits[j] == 0) {
                            node->left = new TreeNode(nums[i]);
                            node = node->left;
                        }
                        else {
                            node->right = new TreeNode(nums[i]);
                            node = node->right;
                        }
                    }
                    else {
                        node = bits[j] == 0 ? node->left : node->right;
                    }
                }
            }
        }

        return root;
    }

    LeetCode_222() {
        vector<int> nums = { 1,2,3,4,5,6 };

        TreeNode* root = genTreeNode(nums);

        printf("%d\n", countNodes(root));
    }

    int countNodes(TreeNode* root) {
        if (root == NULL)
            return 0;

        TreeNode* node = root;
        int level = 0;

        while (node != NULL) {
            ++level;
            node = node->left;
        }

        int mini = 1;
        for (int i = 1; i < level; ++i) {
            mini *= 2;
        }

        int size = mini;
        int offset = mini;
        int lastOffset = mini;
        bool big = true;

        while (size > 0) {
            size /= 2;
            if (big) {
                if (size == 0)
                    offset = mini * 2 - 1;
                else
                    offset += size;
            }
            else {
                if (size == 0)
                    break;
                if (size > 0)
                    offset -= size;
            }

            node = root;

            vector<char> bits = getBits(offset);
            for (int j = bits.size() - 2; j >= 0; --j) {
                node = bits[j] == 0 ? node->left : node->right;
            }

            if (node != NULL) {
                lastOffset = offset;
                big = true;
            }
            else
            {
                big = false;
            }
        }

        return lastOffset;
    }
};
