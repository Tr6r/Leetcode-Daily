/*
LC 98 - Validate Binary Search Tree
Hours Effort: 02:55:26
Solution: inorder
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
        stack<TreeNode> st;
        vector<int> sort;
        st.push({*root});
        while (!st.empty()) {
            TreeNode* tmp = &st.top();
            st.pop();
            if (tmp->left) {
                TreeNode* l = tmp->left;
                tmp->left = NULL;
                st.push({*tmp});

                st.push({*l});

            } else if (tmp->right) {
                sort.push_back(tmp->val);
                TreeNode* r = tmp->right;
                st.push({*r});
            } else {
                sort.push_back(tmp->val);
            }
        }
        for (int i = 1; i < sort.size(); i++) {
            if (sort[i-1] >= sort[i]) return false;
        }

        return true;
    }
};

