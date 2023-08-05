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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        //  Brute-force Approach  :- T.C : O(m*n) , S.C : O(1)

        // ListNode *temp;
        // while(headA)
        // {       
        //     temp=headB;
        //     while(temp)
        //     {
        //         if(headA==temp)
        //           return headA;
        //         temp=temp->next;
        //     }
        //     headA=headA->next;
        // }
        // return NULL;

        // Optimal Approach :- T.C : O(m+n) , S.C : O(1)
       
        if(headA==NULL || headB==NULL)
           return NULL;

        ListNode *a= headA;
        ListNode *b= headB;
        
        while(a!=b)
        {
            if(a==NULL)
              a=headB;
            else
              a=a->next;
            
            if(b==NULL)
              b=headA;
            else
              b=b->next;
        }
        return a;
    }
};