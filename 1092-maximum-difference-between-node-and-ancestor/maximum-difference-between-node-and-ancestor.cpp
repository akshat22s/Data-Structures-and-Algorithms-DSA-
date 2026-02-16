class Solution {
public:
    int maxDiff;
    void maxDiffFill(TreeNode* root, TreeNode* child)
    {
        if(root == NULL) return;
        if(child == NULL) return;
        maxDiff = max(maxDiff, abs(root->val - child->val));

        maxDiffFill(root, child->left);
        maxDiffFill(root, child->right);
    }

    void helper(TreeNode* root)
    {
        if(root == NULL) return;
        maxDiffFill(root, root->left);
        maxDiffFill(root, root->right);

        helper(root->left);
        helper(root->right);
    }
    int maxAncestorDiff(TreeNode* root) {
        maxDiff = -1;
        helper(root);
        return maxDiff;
    }
};