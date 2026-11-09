/*
LC 98 - Validate Binary Search Tree
Hours Effort: 00:57:40
Solution: DFS
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
    typedef struct {
        long par_val;
        TreeNode* node;
        char br;
        bool nc;
    } ctx;
    bool isValidBST(TreeNode* root) {
        stack<ctx> st;
        // L , R
        if (root->left) {
            st.push({root->val, root->left, 'l', false});
        }
        if (root->right) {
            st.push({root->val, root->right, 'r', false});
        }
        while (!st.empty()) {
            ctx tmp = st.top();
            st.pop();
            if (tmp.br == 'l') {
                if (tmp.node->val >= tmp.par_val)
                    return false;
                if (tmp.node->left) {

                    if (tmp.nc &&  tmp.node->left->val < tmp.par_val && cout<<"tmp.par_val: "<<tmp.par_val<<endl)
                        return false;
                    st.push({tmp.node->val, tmp.node->left, 'l',false});
                }
                //
                if (tmp.node->right) {
                    if (tmp.node->right->val > tmp.par_val && cout<<"2")
                        return false;
                    st.push({tmp.node->val, tmp.node->right, 'r', true});
                }
            } else if (tmp.br == 'r') {
                if (tmp.node->val <= tmp.par_val)
                    return false;
                //
                if (tmp.node->left) {
                    if (tmp.node->left->val < tmp.par_val  && cout<<"3")
                        return false;
                    st.push({tmp.node->val, tmp.node->left, 'l', true});
                }
                if (tmp.node->right) {
                    if (tmp.nc == true && tmp.node->right->val > tmp.par_val  && cout<<"4")
                        return false;
                    st.push({tmp.node->val, tmp.node->right, 'r', false});
                }
            }
        }
        return true;
    }
};
