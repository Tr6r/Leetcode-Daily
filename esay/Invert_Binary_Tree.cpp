/*
LC 226 - Invert Binary Tree
Hours Effort: 00:07:41
Solution: Recursive
Time: O(N), Space: O(1)
*/

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
    TreeNode* invertTree(TreeNode* root) {
        if (!root){
            return NULL;
        }
        if (!root->left && !root->right) {
            return root;
        }

        invertTree(root->left);
        invertTree(root->right);

        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        return root;
    }
};