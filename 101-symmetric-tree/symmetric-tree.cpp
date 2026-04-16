class Solution {
public:
    bool solve(TreeNode* p, TreeNode* q)
    {
        if(p == NULL && q == NULL) return true;
        if(p == NULL || q == NULL) return false;
        if(p->val != q->val) return false;
        bool leftAns = solve(p->left, q->right);
        bool rightAns = solve(p->right, q->left);
        return leftAns && rightAns;
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return solve(root->left, root->right);


    }
};