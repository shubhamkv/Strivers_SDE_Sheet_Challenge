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
    bool isPalindrome(ListNode* head) {
        
        // Brute - force Approach 

        // vector<int> nums;
        // while(head)
        // {
        //     nums.push_back(head->val);
        //     head=head->next;
        // }
        // for(int i=0;i<nums.size()/2;i++)
        // {
        //     if(nums[i]!=nums[nums.size()-1-i])
        //         return false;
        // }
        // return true;

        // -------------------------------------------------------------------------

        // Optimised Approach

        ListNode *temp=head;
        // step 1 -- find middle of the list

        ListNode *slow=head;
        ListNode *fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL)  
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        // step 2 -- reverse the list from one pointer ahead from middle of list

        slow=slow->next;
        ListNode *curr=slow;
        ListNode *prev=NULL;
        ListNode *next;
        while(curr)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        
        // step 3 -- check the first and second half of list is equal or not

        while(prev!=NULL)
        {
           if(temp->val != prev->val)
              return false;
           temp=temp->next;
           prev=prev->next;
        }

        return true;

    }
};