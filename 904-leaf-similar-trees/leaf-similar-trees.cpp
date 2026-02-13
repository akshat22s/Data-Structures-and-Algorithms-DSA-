class Solution {
public:
    void fill(TreeNode* root, string &ans)
    {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL)
        {
            ans += to_string(root->val);
            ans += "_";
        }
        fill(root->left, ans);
        fill(root->right, ans);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string ans1;
        string ans2;
        fill(root1, ans1);
        fill(root2, ans2);

        if(ans1 != ans2) return false;
        return true;
    }
};