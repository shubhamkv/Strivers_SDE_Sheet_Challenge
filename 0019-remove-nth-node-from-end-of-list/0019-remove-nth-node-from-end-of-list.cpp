/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
    //    int cnt=0;
    //    ListNode* curr=head;
    //    while(curr)
    //    {
    //        cnt++;
    //        curr=curr->next;
    //    }
    //    if(cnt==n)                   //edge case
    //      return head->next;
    //    curr=head;
    //    int x=0;
    //    while(curr)
    //    {
    //        x++;
    //        if(x==cnt-n){
    //         curr->next=curr->next->next;
    //         break;
    //        }
    //        curr=curr->next;
    //    }
    //    return head;

       // Optimal Approach : One Pass

        ListNode *slow = head;
        ListNode *fast = head;

        for(int i=1;i<=n;i++)
           fast=fast->next;
        
        if(fast==NULL)             //  edge case when size of list equals to n
          return slow->next;
          
        while(fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next->next;

        return head;
    }
};