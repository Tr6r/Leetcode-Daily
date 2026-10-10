/*
LC 104 - Maximum Depth of Binary Tree
Solution: DFS
Time: O(N), Space: O(N)
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
    typedef struct {
        TreeNode* node;
        int deep;
    } CTX;
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int max_deep = 0;
        stack<CTX>s;
        s.push({root, 1});
        while(!s.empty()) {
            CTX ctx = s.top();
            s.pop();
            int n_deep = ctx.deep + 1;
            if (ctx.node->left) {
                s.push({ctx.node->left, n_deep});
            }
            if (ctx.node->right) {
                s.push({ctx.node->right, n_deep});
            }
            if (max_deep < ctx.deep ) max_deep = ctx.deep;
        }
        return max_deep;
    }
};