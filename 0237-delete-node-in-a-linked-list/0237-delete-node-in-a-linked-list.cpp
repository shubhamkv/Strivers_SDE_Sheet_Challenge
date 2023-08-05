/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        
        // ListNode *dummy = NULL;
        // while(dummy->next!=NULL)
        // {
        //     ListNode *res = dummy->next;
        //     if(res->val==node)
        //        dummy->next=dummy->next->next;
        //     dummy = dummy->next;
        // }

        node->val = node->next->val;      // storing the value of next pointer which has to deleted
        node->next = node->next->next;    // do the work of dislink and link with next to next ptr
    }
};