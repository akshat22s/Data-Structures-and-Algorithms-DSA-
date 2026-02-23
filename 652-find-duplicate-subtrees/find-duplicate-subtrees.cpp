class Solution {
public:
    string solve(TreeNode* root, unordered_map<string, int> &mp, vector<TreeNode*>& ans)
    {
        if(root == NULL)
        {
            return "N";
        }
        string s = to_string(root->val) + "," + solve(root->left, mp, ans) + solve(root->right, mp, ans);

        if(mp[s] == 1)
        {
            ans.push_back(root);
        }
        mp[s]++;
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> mp;
        vector<TreeNode*> ans;
        solve(root, mp, ans);
        return ans;
    }
};