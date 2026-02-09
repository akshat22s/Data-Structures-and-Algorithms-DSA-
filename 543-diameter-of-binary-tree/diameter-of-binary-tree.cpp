class Solution {
public:
    int dfs(TreeNode* root, int &maxDia)
    {
        if(root == NULL) return 0;

        int leftHeight =  dfs(root->left,  maxDia);
        int rightHeight = dfs(root->right, maxDia);

        int dia = leftHeight + rightHeight;

        maxDia = max(maxDia, dia);

        return 1 + max(leftHeight, rightHeight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDia = 0;
        dfs(root, maxDia);
        return maxDia;
    }
};