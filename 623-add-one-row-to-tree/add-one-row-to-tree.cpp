class Solution {
public:
    TreeNode* add(TreeNode* root, int val, int depth, int curr)
    {
        if(root == NULL) return root;
        if(depth - 1 == curr)
        {
            TreeNode* tempL = root->left;
            TreeNode* tempR = root->right;

            TreeNode* newNodeL = new TreeNode(val);
            TreeNode* newNodeR = new TreeNode(val);

            root->left = newNodeL;
            root->right = newNodeR;

            newNodeL->left = tempL;
            newNodeR->right = tempR;
        }
        add(root->left, val, depth, curr+1);
        add(root->right, val, depth, curr+1);

        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1)
        {
            TreeNode* newNode = new TreeNode(val);
            newNode->left = root;

            return newNode;
        }

        int curr = 1;
        return add(root, val, depth, curr);
    }
};