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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        // Brute - force Approach 

        // ListNode *curr = head;
        // ListNode *node = head;
        // vector<int>ans;
        // int len=0,cnt=0;
        // while(node)
        // {
        //     len++;                 
        //     node=node->next;
        // }
        // while(curr)
        // {
        //     if(cnt!=len/k)   // (len/k) ---> gives the no. of times k will implement in list
        //     {
        //         vector<int>temp;
        //         int x=k;
        //         while(x!=0)
        //         {
        //             temp.push_back(curr->val);
        //             curr=curr->next;
        //             x--;
        //         }
        //         cnt++;
        //         reverse(temp.begin(),temp.end());           // uses the concept of Sort LL
        //         for(int i=0;i<temp.size();i++)
        //           ans.push_back(temp[i]);
        //     }
        //     else
        //     {
        //         ans.push_back(curr->val);
        //         curr=curr->next;
        //     }
        // }
        // curr=head;
        // for(int i=0;i<ans.size();i++)
        // {
        //     curr->val=ans[i];
        //     curr=curr->next;
        // }
        // return head;

        // --------------------------------------------------------------------------

        // Optimal Approach

        if(head==NULL || k==1)
         return head;

        ListNode *dummy = new ListNode(0);
        dummy->next=head;
        ListNode *prev = dummy, *curr=dummy , *nex=dummy;
        int len=0,cnt=0;

        while(curr->next)
        {
            len++;
            curr=curr->next;
        }

        while(cnt!=len/k)
        {
            curr=prev->next;    // curr and next always point to first and second of each k group
            nex=curr->next;
            for(int i=1;i<k;i++)
            {
                curr->next=nex->next;
                nex->next=prev->next;           // this operation will be done each k-1 times to
                prev->next=nex;                 //  reverse the each k group of linked list
                nex=curr->next;
            }
            prev=curr;
            cnt++;
        }
        return dummy->next;
    }
};