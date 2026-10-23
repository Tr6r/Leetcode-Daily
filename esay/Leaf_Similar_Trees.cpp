/*
LC 872 - Leaf-Similar Trees
Hours Effort: 00:13:20
Solution: Recursive
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
    stack<int> st;
    stack<int> st2;
    void st_leaf(TreeNode* root) {
        if (!root) return;
        if (!root->left && !root->right) {
            st.push(root->val);
            return;
        }
        st_leaf(root->left);
        st_leaf(root->right);
    }
    void st_leaf_2(TreeNode* root) {
        if (!root) return;
        if (!root->left && !root->right) {
            st2.push(root->val);
            return;
        }
        st_leaf_2(root->left);
        st_leaf_2(root->right);
    }
    bool compare() {
        int n_size = st.size();
        int n_size_2 = st2.size();
        if (n_size != n_size_2) return false;

        for (int i =0;i<n_size;i++) {
            int cp1 = st.top();
            int cp2 = st2.top();

            if (cp1 != cp2) return false;
            st.pop();
            st2.pop();
        }
        return true;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        st_leaf(root1);
        st_leaf_2(root2);
        return compare();
    }
};