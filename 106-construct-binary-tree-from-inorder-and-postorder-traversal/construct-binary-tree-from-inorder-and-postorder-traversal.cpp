/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int,int> mp;
    TreeNode* helper(vector<int>& in, int inLow, int inHigh, vector<int>& post, int postLow, int postHigh)
    {
        if(inLow > inHigh) return NULL;
        TreeNode* root = new TreeNode(post[postHigh]);
        int idx = mp[post[postHigh]];
        int leftCount = idx-inLow;
        root->left = helper(in, inLow, idx-1, post, postLow, postLow+leftCount-1);
        root->right = helper(in, idx+1, inHigh, post, postLow+leftCount, postHigh-1);
        return root;

    }
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        int n = in.size();
        for(int i = 0; i < n; i++) mp[in[i]] = i;
        return helper(in, 0, n-1, post, 0, n-1);
    }
};