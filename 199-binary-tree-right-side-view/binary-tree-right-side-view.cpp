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
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int n = q.size();
            int x = -1;
            for(int i = 0; i < n; i++)
            {
                TreeNode* temp = q.front();
                if(temp->left != NULL) q.push(temp->left);
                if(temp->right != NULL) q.push(temp->right);
                x = temp->val;
                q.pop();
            }
            ans.push_back(x);
        }
        return ans;
    }
};