class Solution {
public:
    void fill(TreeNode* root, vector<int> &ans)
    {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL)
        {
            ans.push_back(root->val);
        }
        fill(root->left, ans);
        fill(root->right, ans);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> ans1;
        vector<int> ans2;
        fill(root1, ans1);
        fill(root2, ans2);

        if(ans1.size() != ans2.size()) return false;
        for(int i = 0; i < ans1.size(); i++)
        {
            if(ans1[i] != ans2[i]) return false;
        }
        return true;
    }
};