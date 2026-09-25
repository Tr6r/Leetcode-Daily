/*
LC 111 - Minimum Depth of Binary Tree
Solution: Recursion
Time: O(N), Space: O(M)
*/

class Solution {
public:
    int count = 1;
    int min = INT_MAX;
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        if (!root->left && !root->right) {
            if (min > count)
                min = count;
            return 1;
        }
        if (root->left) {
            count++;
            minDepth(root->left);
            count--;
        }
        if (root->right) {
            count++;
            minDepth(root->right);
            count--;
        }
        return min;
    }
};