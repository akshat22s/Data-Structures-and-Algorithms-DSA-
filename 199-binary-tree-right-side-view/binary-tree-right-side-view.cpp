class Solution {
public:
    void preorder(TreeNode* root, int level, vector<int> &ans)
    {
        if(root == NULL) return;
        if(ans.size() < level)  ans.push_back(root->val);
        preorder(root->right,level+1, ans);
        preorder(root->left, level+1, ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        preorder(root, 1, ans);
        return ans;
    }
};