class Solution {
public:
    vector<vector<int>> finalAns;
    int height(TreeNode* root)
    {
        if(root == NULL) return 0;
        return 1 + max(height(root->left), height(root->right));
    }
    void helper(TreeNode* root, int curr, int level, vector<int> &ans)
    {
        if(curr % 2 == 0)
        {
            if(root == NULL) return;
            if(curr == level)
            {
                ans.insert(ans.begin(),root->val);
                return;
            }
            helper(root->left,  curr+1, level, ans);
            helper(root->right, curr+1, level, ans);
        }
        else
        {
            if(root == NULL) return;
            if(curr == level)
            {
                ans.push_back(root->val);
                return;
            }
            helper(root->left,  curr+1, level, ans);
            helper(root->right, curr+1, level, ans);
        }

    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int n = height(root);
        for(int i = 1; i <= n; i++)
        {
            vector<int> ans;
            helper(root, 1, i, ans);
            finalAns.push_back(ans);
        }
        return finalAns;
    }
};