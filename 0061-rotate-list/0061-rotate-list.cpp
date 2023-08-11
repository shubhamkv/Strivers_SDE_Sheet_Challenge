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
    ListNode* rotateRight(ListNode* head, int k) {
        
        // Brute-force Approach : O(n*k) , O(1)  :  Gives TLE

        // if(head==NULL || head->next==NULL || k==0)
        //     return head;

        // for(int i=0;i<k;i++)
        // {
        //     ListNode *temp=head;
        //     while(temp->next->next)
        //       temp=temp->next;
        //     ListNode *end = temp->next;
        //     temp->next=NULL;
        //     end->next=head;
        //     head=end;
        // }
        // return head;

        // ------------------------------------------------------------------------------
        
        // Optimal Approach : O(n) , O(1)

        if(head==NULL || head->next==NULL || k==0)
            return head;

        ListNode *curr = head;
        int len =1;

        while(curr->next)
        {
            len++;
            curr=curr->next;
        }
        curr->next = head;   // making a circular linked list
        k=k%len;
        k=len-k;
        while(k--)
        {
           curr=curr->next;
        }
        head = curr->next;
        curr->next = NULL;

        return head;
    }
};