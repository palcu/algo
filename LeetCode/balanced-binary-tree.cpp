/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int checkDepth(TreeNode *node) {
        if (node == nullptr) return 0;
        int left = checkDepth(node->left),
            right = checkDepth(node->right);
        if (left < 0 || right < 0) return -1;
        int diff = abs(left - right);
        if (diff > 1) return -1;
        return 1 + max(left, right);
    }

public:
    bool isBalanced(TreeNode * root) {
        if (root == nullptr)
            return true;
        return checkDepth(root) > 0;
    }
};
