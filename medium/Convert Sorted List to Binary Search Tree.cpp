/*
LC 109 - Convert Sorted List to Binary Search Tree
Time : O(N log(N)) - Traverse every node in the linked list once and split the linked list in half on every traversal
Space : O(log(N)) - Use recursion stack

Logic:
1. Use recursion to solve this question
2. Use fast and slow pointers to split the linked list in half
3. If there is just one node, stop recursion
4. Create the root value at the slow pointer
5. Create the root's left subtree by recursion on the first half of the linked list
6. Create the root's right subtree by recursion on the rest of the linked list
*/
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return NULL;
        ListNode *pre=NULL,*fast=head,*slow=head;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            pre = slow;
            slow=slow->next;
        }
        if(pre==NULL)
        {
            TreeNode *root = new TreeNode();
            root->val = slow->val;
            return root;
        }
        TreeNode *root = new TreeNode(slow->val);
        pre->next = NULL;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        return root;
    }
};