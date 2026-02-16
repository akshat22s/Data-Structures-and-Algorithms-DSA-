class Solution {
public:
    int maxSum;
    int helper(TreeNode* root)
    {
        if(root == NULL) return 0;
        int l = helper(root->left);
        int r = helper(root->right);

        int s1 = root->val + l + r;

        int s2 = max(l, r) + root->val;

        int s3 = root->val;

        maxSum = max({maxSum, s1, s2, s3});

        return max(s2, s3);
    }
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        helper(root);
        return maxSum;
    }
};