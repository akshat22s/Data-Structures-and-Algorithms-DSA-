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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // base case
        // 1 agar dono null ho to true;
        // 2 agar ek null aur dusra nahi tho false
        // agar ek ka value != other ka value false
        if(p == NULL && q == NULL) return true;
        if(p == NULL || q == NULL) return false;
        if(p->val != q->val) return false;

        bool leftAns = isSameTree(p->left, q->left);
        if(leftAns == false) return false;
        bool rightAns = isSameTree(p->right, q->right);
        if(rightAns == false) return false;
        return true;
    }
};