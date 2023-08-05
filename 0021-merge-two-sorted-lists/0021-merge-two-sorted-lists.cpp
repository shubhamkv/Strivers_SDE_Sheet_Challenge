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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        //  Brute-force Approach 

        // if(l1==NULL && l2==NULL)
        //   return NULL;

        // ListNode *res = new ListNode(0);
        // ListNode *curr = res;
        // while(l1!=NULL && l2!=NULL)
        // {
        //     if(l1->val<=l2->val)
        //     {
        //         curr->next=l1;
        //         l1=l1->next;
        //     }
        //     else
        //     {
        //         curr->next=l2;
        //         l2=l2->next;
        //     }
        //     curr=curr->next;
        // }
        
        // if(l1!=NULL)
        // {
        //     curr->next=l1;
        //     l1=l1->next;
        // }
        // if(l2!=NULL)
        // {
        //     curr->next=l2;
        //     l2=l2->next; 
        // }

        // return res->next;

        // Optimal Approach 

        if(!l1)
          return l2;
        if(!l2)
          return l1;

        if(l1->val>l2->val)
          swap(l1,l2);

        ListNode* res = l1;
        while(l1 && l2)
        {
            ListNode* temp = NULL;
            while(l1!=NULL && l1->val<=l2->val)
            {
                temp=l1;
                l1=l1->next;
            }
            temp->next=l2;
            swap(l1,l2);
        }
        return res;
    }
};