class Solution {
public:
    void helper(TreeNode* root, int targetSum, vector<vector<int>> &result, vector<int> ans)
    {
        if(root == NULL) return;
        ans.push_back(root->val);
        if(root->left == NULL && root->right == NULL && targetSum == root->val)
        {
            result.push_back(ans);
            return;
        }
        helper(root->left, targetSum-root->val,result, ans);
        helper(root->right, targetSum-root->val, result, ans);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> ans;
        helper(root, targetSum, result, ans);
        return result;
    }
};