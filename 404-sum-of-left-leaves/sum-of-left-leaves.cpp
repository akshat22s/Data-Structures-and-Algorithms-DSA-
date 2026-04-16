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
    int count;
    void solve(TreeNode* root)
    {
        if(root == NULL) return;
        if(root->left != NULL && root->left->left == NULL && root->left->right == NULL)
        {
            count += root->left->val;
        }

        solve(root->left);
        solve(root->right);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        count = 0;
        if(root == NULL) return 0;
        solve(root);
        return count;
    }
};