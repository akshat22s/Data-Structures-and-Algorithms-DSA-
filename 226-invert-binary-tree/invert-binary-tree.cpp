class Solution {
public:
    void solve(TreeNode* root)
    {
        if(root == NULL) return;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        root->left = right;
        root->right = left;
        solve(root->left);
        solve(root->right);
    }
    TreeNode* invertTree(TreeNode* root) 
    {
        if(root == NULL) return root;
        solve(root);
        return root;
    }
};