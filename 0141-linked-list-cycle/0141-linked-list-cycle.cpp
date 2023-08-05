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
    bool hasCycle(ListNode *head) {
        
        // Brute- force approach 

        // unordered_set<ListNode*> s;
        // while(head)
        // {
        //     if(s.find(head)!=s.end())
        //        return true;
        //     s.insert(head);
        //     head=head->next;
        // }
        // return false;
        
        // -----------------------------------------------------------------
        
        // Optimized Approach 
        
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast!=NULL && fast->next!=NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow)
              return true;
        }
        return false;
    }
};