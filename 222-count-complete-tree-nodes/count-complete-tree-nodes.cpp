class Solution {
public:
    int getLeftHeight(TreeNode* root)
    {
        if(root == NULL) return 0;
        return 1 + getLeftHeight(root->left);
    }

    int getRightHeight(TreeNode* root)
    {
        if(root == NULL) return 0;
        return 1 + getRightHeight(root->right);
    }
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;

        int lh = getLeftHeight(root);
        int rh = getRightHeight(root);
        if(lh == rh)
        {
            return (pow(2,lh) - 1);
        }

        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};