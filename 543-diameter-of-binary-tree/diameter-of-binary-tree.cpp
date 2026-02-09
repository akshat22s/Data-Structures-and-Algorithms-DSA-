class Solution {
public:
    int height(TreeNode* root)
    {
        if(root == NULL) return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    int helper(TreeNode* root, int &maxDia)
    {
        if(root == NULL) return 0;
        int dia = height(root->left) + height(root->right);
        maxDia = max(maxDia, dia);

        helper(root->left,  maxDia);
        helper(root->right, maxDia);

        return maxDia;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDia = 0;
        return helper(root, maxDia);
    }
};