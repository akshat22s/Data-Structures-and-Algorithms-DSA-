class Solution {
public:
    int height(TreeNode* root)
    {
        if(root == NULL) return 0;
        return 1 + max(height(root->left), height(root->right));
    }
    bool helper(TreeNode* root)   
    {
        if(root == NULL) return true;
        int ls = height(root->left);
        int rs = height(root->right);
        if(abs(ls-rs) > 1) return false;
        int lcs = helper(root->left);
        int rcs = helper(root->right);
        return lcs && rcs;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        return helper(root);
    }
};