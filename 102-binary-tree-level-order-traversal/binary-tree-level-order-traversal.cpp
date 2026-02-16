class Solution {
public:
    int height(TreeNode* root)
    {
        if(root == NULL) return 0;
        return 1 + max(height(root->left), height(root->right));
    }
    void nthLevel(TreeNode* root, int curr, int level, vector<int> &ans)
    {
        if(root == NULL) return;
        if(curr == level)
        {
            ans.push_back(root->val);
            return;
        }
        nthLevel(root->left, curr+1, level, ans);
        nthLevel(root->right, curr+1, level, ans);
    }
    void helper(TreeNode* root, vector<vector<int>> &finalAns)
    {
        if(root == NULL) return;
        int n = height(root);
        for(int i = 1; i <= n; i++)
        {
            vector<int> ans;
            nthLevel(root, 1, i, ans);
            finalAns.push_back(ans);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> finalAns;
        helper(root, finalAns);
        return finalAns;
    }
};