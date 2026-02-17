class Solution {
public:
    int height(TreeNode* root, int& ans)
    {
        if(root == NULL) return 0;
        int left  = height(root->left, ans);
        int right = height(root->right, ans);
        ans = max(ans, left+right);
        return 1 + max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        height(root, ans);
        return ans;
    }
};