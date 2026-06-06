/*
LC 109 - Convert Sorted List to Binary Search Tree
Time : O(N log(N)) - Traverse every node in the linked list once and split the linked list in half on every traversal
Space : O(1)

Logic:
1. Use recursion to solve this question
2. Try to split the linked list in half to find the root value until the list has fewer than 2 nodes
3. Create the root's left subtree by cutting the linked list from the beginning -> node before the root node
4. Create the root's right subtree by cutting the linked list from the node after the root node -> end of the linked list
*/


class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode* root = new TreeNode();
        ListNode* left,*right,*n_head = head;
        if (head == NULL) return NULL;
        
        int count =0;
        while(n_head)
        {
            count++;
            n_head = n_head->next;
        }
        count= count/2;
        if (count<2)
        {
            root->val = head->val;
        
            if (!head->next)return root;
            TreeNode* nleft = new TreeNode(root->val);
            root->left = nleft;
            root->val = head->next->val;
            if (!head->next->next)return root;
            TreeNode* nright = new TreeNode(head->next->next->val);


            root->right = nright;
            return root;
        }
        left = head;
        while(head)
        {
            if (count-1 == 0)
            {
                root->val= head->next->val;
                right = head->next->next;
                head->next = NULL;
                break;
            }
            count --;
            head=head->next;
        }
        root->left = sortedListToBST(left);
        root->right= sortedListToBST(right);

        
        return root;
    }
};