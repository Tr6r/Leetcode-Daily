/*
LC 98 - Validate Binary Search Tree
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
    *int val;
    *TreeNode* left;
    *TreeNode* right;
    *TreeNode()
        : val(0),
    left(nullptr), right(nullptr){} * TreeNode(int x)
        : val(x),
    left(nullptr),
    right(nullptr){} * TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x),
    left(left), right(right){}*
};
*/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        // cout<<"root.val"<<root->val<<endl;
        if (!root->left && !root->right) {
            return 1;
        }

        if (root->left) {
            int ret1 = recursive(root->left, 0);
            if (ret1)
                if (!ret1 || root->val <= root->left->val) {
                    ret = false;
                }
            return root->left->val;
        }
        if (root->right) {
            bool ret = isValidBST(root->right);
            if (!ret || root->val >= root->right->val) {
                return false;
            }
        }
        return true;
    };
}
    