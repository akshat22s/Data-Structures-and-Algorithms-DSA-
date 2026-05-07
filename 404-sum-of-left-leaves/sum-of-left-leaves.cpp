class Solution {
public:
    int sum;
    void solve(TreeNode* root, bool flag)
    {
        if(flag == true && root->left == NULL && root->right == NULL)
        {
            sum += root->val;
        }
        if(root->left != NULL) solve(root->left, true);
        if(root->right != NULL) solve(root->right,false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL) return 0;
        sum = 0;
        solve(root, false);
        return sum;
    }
};