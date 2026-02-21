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
    int ans;
    int solve(TreeNode* root)
    {
        if(root == NULL) return 0;
        int left  = solve(root->left);
        int right = solve(root->right);
        int s1 = left + root->val + right;
        int s2 = root->val + max(left, right);
        int s3 = root->val;

        ans = max({ans, s1, s2, s3});

        return max(s2, s3);
    }
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        solve(root);
        return ans;
    }
};