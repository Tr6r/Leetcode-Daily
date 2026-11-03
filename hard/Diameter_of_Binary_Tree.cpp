/*
LC 543 - Diameter of Binary Tree
Hours Effort: 00:21:52
Solution: Recursion
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int l = 0;
    int r = 0;
    int r_pivot=0;
    bool l_now = true;
    int count = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root->left && !root->right) {
            return 0;
        }
        if (count == 0) {
            // cout<<"assa"<<endl;
            r_pivot = root->right->val;
            root->val = 0;
            count++;
        }

        if (root->left != NULL) {
            int a = root->val  + 1 ;
            root->left->val = a;
            if (root->left->val > l)
                l = root->left->val;
            diameterOfBinaryTree(root->left);
        }
        if (root->right != NULL) {
            int a = root->val  + 1 ;
            root->right->val = a;
            if (!r_pivot && root->right->val > r)
                r = root->right->val;
            diameterOfBinaryTree(root->right);
        }

        return l + r;
    }
};