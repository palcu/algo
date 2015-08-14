class Solution {
    bool check_existence(TreeNode* p, TreeNode* q) {
        if ((p && !q) || (!p && q))
            return false;
        return true;
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!check_existence(p, q))
            return false;
        if (!p && !q)
            return true;
        queue<TreeNode*> q1, q2;
        q1.push(p);
        q2.push(q);
        while (!q1.empty() && !q2.empty()) {
            TreeNode *node1, *node2;
            node1 = q1.front(); q1.pop();
            node2 = q2.front(); q2.pop();
            if (!node1 && !node2)
                continue;
            if (node1->val != node2->val)
                return false;
            if (check_existence(node1->left, node2->left)) {
                q1.push(node1->left);
                q2.push(node2->left);
            } else {
                return false;
            }
            if (check_existence(node1->right, node2->right)) {
                q1.push(node1->right);
                q2.push(node2->right);
            } else {
                return false;
            }
        }
        return true;
    }
};
