class Solution {
public:
    queue<TreeNode*> q;
    bool isCompleteTree(TreeNode* root) {
        q.push(root);
        bool past = false;
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            if(temp == NULL)
            {
                past = true;
            }
            else
            {
                if(past == true) return false;
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return true;
    }
};