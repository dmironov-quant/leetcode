// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/?envType=daily-question&envId=2026-02-24

class Solution {
public:
    void inorder(TreeNode* node, int curr, int& ans) {
        if (node->left == nullptr && node->right == nullptr) {
            ans += (curr << 1) + node->val;
            return;
        }
        if (node->left)  inorder(node->left,  (curr << 1) + node->val, ans);
        if (node->right) inorder(node->right, (curr << 1) + node->val, ans);
    }

    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        inorder(root, 0, ans);
        return ans;
    }
};
