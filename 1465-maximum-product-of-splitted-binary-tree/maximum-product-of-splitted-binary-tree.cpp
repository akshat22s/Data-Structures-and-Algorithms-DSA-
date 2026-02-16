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
    int SUM = 0;
    long maxP = 0;
    int helperSum(TreeNode* root)
    {
        if(root == NULL) return 0;
        return root->val + helperSum(root->left) + helperSum(root->right);
    }
    int find(TreeNode* root)
    {
        if(root == NULL) return 0;

        int leftSum  = find(root->left);
        int rightSum = find(root->right);

        long subTreeSum = root->val + leftSum + rightSum; // S1
        long remaningSubTreeSum = SUM - subTreeSum;       // S2

        maxP = max(maxP, subTreeSum * remaningSubTreeSum);
        return subTreeSum;
    }
    int maxProduct(TreeNode* root) {
        SUM = helperSum(root);
        find(root);
        return maxP % 1000000007;
    }
};