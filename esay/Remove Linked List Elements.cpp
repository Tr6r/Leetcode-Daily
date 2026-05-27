/*
LC 203 - Remove Linked List Elements.
Time : O(N) - traverse every node in the head list once.
Space : O(1)

Logic:
1. 1. Create a copy of the original linked list.
2. traverse every node in the original list. 
3. If the current node's value is equal to the given value:
   - if pre NULL -> move the head to the next node.
   - else link the previous node to the next node of the current node.
4. Move the previous pointer to the current node.
*/

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *new_head = head;
        ListNode *pre = NULL;
        if (!head) return new_head;
        while ( head != NULL)
        {
            if (head->val == val)
            {
                if(!pre)
                {
                    if (new_head->next == NULL)
                    {
                        new_head = NULL;
                        return new_head;
                    }
                    new_head = new_head->next;
                    head = head->next;
                    continue;
                }
                pre->next = head->next;
                head = head->next;
                continue;
            }
            pre = head;
            head = head->next;
        }
        return new_head;
    }
};