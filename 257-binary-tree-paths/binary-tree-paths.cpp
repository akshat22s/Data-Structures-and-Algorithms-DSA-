class Solution {
public:
    void helper(TreeNode* root, string ans, vector<string> &finalAns)
    {
        if(root == NULL) return;
        string a = to_string(root->val);
        if(root->left == NULL && root->right == NULL)
        {
            ans += a;
            finalAns.push_back(ans);
            return;
        }
        ans = ans + a + "->";
        helper(root->left, ans, finalAns);
        helper(root->right, ans, finalAns);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> finalAns;
        helper(root, "", finalAns);
        return finalAns;
    }
};