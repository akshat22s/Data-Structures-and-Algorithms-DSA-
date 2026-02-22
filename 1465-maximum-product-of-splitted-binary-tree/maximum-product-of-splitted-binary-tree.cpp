class Solution {
public:
    int totalSum;
    long long maxP = 0;
    int helperSum(TreeNode* root)
    {
        if(root == NULL) return 0;
        return root->val + helperSum(root->left) + helperSum(root->right);
    }
    int helper(TreeNode* root)
    {
        if(root == NULL) return 0;
        int leftSum  = helper(root->left);
        int rightSum = helper(root->right);
        long long subTree = root->val + leftSum + rightSum;
        long long remainingSum = totalSum - subTree;
        long long  product = subTree * remainingSum;
        maxP = max(maxP, product);
        return subTree;
    }
    int maxProduct(TreeNode* root) {
        totalSum = helperSum(root);
        helper(root);
        return maxP % 1000000007;
    }
};