/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root)
    {
        if(root == NULL) return 0;
        return 1 + max(height(root->left), height(root->right));
    }
    void helper(TreeNode* root, int& ans)
    {
        if(root == NULL) return;
        int ls = height(root->left);
        int rs = height(root->right);
        ans = max(ans, ls+rs);
        helper(root->left, ans);
        helper(root->right, ans);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        helper(root, ans);
        return ans;

    }
};